    #pragma once﻿
    #include "Board.h"


Board::Board() : currentPlayer(PlayerColor::RED) {
    for (int i = 0; i < 10; i++) 
        for (int j = 0; j < 9; j++) 
            grid[i][j] = nullptr;
       
        initZobristTable();

    
}
        void Board::khoitao() {
			this->redPieces.clear();
			this->blackPieces.clear();
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 9; ++j) {
                    Piece* p = grid[i][j];
                    if (p != nullptr) {
                        if (p->getColor() == PlayerColor::RED)
                            redPieces.push_back(p);
                        else
                            blackPieces.push_back(p);
                    }
                }
            }

        }

    Board::~Board() {
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 9; j++)
                if (grid[i][j] != nullptr) delete grid[i][j];
    }

    void Board::clear() {
        for (int i = 0; i < 10; ++i)
            for (int j = 0; j < 9; ++j) {
                if (grid[i][j]) {
                    delete grid[i][j];
                    grid[i][j] = nullptr;
                }
            }
    }


    bool Board::movePiece(const int &fromX, const int& fromY, const int& toX, const int &toY) {
        if (fromX < 0 || fromX > 9 || fromY < 0 || fromY > 8 ||
            toX < 0 || toX > 9 || toY < 0 || toY > 8) {
            return false;
        }
        if (fromX == toX && fromY == toY) return false;

        Piece* piece = grid[fromX][fromY];
        if (piece == nullptr) return false;
        if (piece->getColor() != currentPlayer) return false;

        Piece* target = grid[toX][toY];
        if (target != nullptr && target->getColor() == currentPlayer) return false;
        if (target != nullptr) {
            target->setAlive(false);  
        }


    
        grid[toX][toY] = piece;
		
        grid[fromX][fromY] = nullptr;

  
        piece->setPosition(toX, toY);

        Move move;
        move.fromX = fromX;
        move.fromY = fromY;
        move.toX = toX;
        move.toY = toY;
        move.movedPiece = piece;
        move.capturedPiece = target; 

        history.Push(move);

        currentPlayer = (currentPlayer == PlayerColor::RED)
            ? PlayerColor::BLACK
            : PlayerColor::RED;

        return true;
    }
    
    std::vector<std::pair<int, int>> Board::getAllPossibleMoves(const int &x, const int &y) 
    {
        std::vector<std::pair<int, int>> moves;
        if (x < 0 || x > 9 || y < 0 || y > 8) {
            return moves;
        }
		for (int i = 0; i < redPieces.size(); i++)
        {
			
            if ((redPieces[i]->getX() == x && redPieces[i]->getY() == y)&&redPieces[i]->getAlive()) {
               moves =  redPieces[i]->getAllPossibleMoves(grid);
               break;
            }
        }
        for (int i = (int)moves.size() - 1; i >= 0; i--)
        {
            this->movePiece(x, y, moves[i].first, moves[i].second);

            if (this->isGeneralFacing() || getCheckmate()) {
                moves.erase(moves.begin() + i);
            }

            this->undo();
        }

        return moves;
    }
        
    bool Board::getCheckmate() 
    {
		int redGeneralX = -1, redGeneralY = -1;
        for (int i = 0; i < redPieces.size(); i++)
        {
            if (redPieces[i]->getSymbol() == "RG" && redPieces[i]->getAlive())
            {
                redGeneralX = redPieces[i]->getX();
                redGeneralY = redPieces[i]->getY();
            }
            
        }
		if (redGeneralX == -1 || redGeneralY == -1) return false;

        for (int i = 0 ; i < blackPieces.size() ; i++)
        {
            if (blackPieces[i]->getAlive() &&blackPieces[i]->isValidMove(redGeneralX, redGeneralY, grid))
            {
                return true; 
            }
        }
		return false;
		}

    bool Board::Checkmate()
    {
        int blackGeneralX = -1, blackGeneralY = -1;
        for (int i = 0; i < redPieces.size(); i++)
        {
            if (blackPieces[i]->getSymbol() == "RG" && blackPieces[i]->getAlive())
            {
                blackGeneralX = redPieces[i]->getX();
                blackGeneralY = redPieces[i]->getY();
            }

        }
        if (blackGeneralX == -1 || blackGeneralY == -1) return false;

        for (int i = 0; i < redPieces.size(); i++)
        {
            if (redPieces[i]->isValidMove(blackGeneralX, blackGeneralY, grid))
            {
                return true;
            }
        }
        return false;
    }
    bool Tamchieu()
    {

    }
    void Board::printBoard() const {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 9; j++) {
                if (grid[i][j] == nullptr) {
                    std::cout << ". ";
                }
                else {
                    std::cout << grid[i][j]->getSymbol() << " ";
                }
            }
            std::cout << std::endl;
        }
    }

   
    std::vector<Move> Board::getAllPossibleMoves(PlayerColor color) {
        std::vector<Move> allMoves;
        std::vector<Piece*> pieces = (color == PlayerColor::RED) ? redPieces : blackPieces;

        for (Piece* piece : pieces) {
            if (!piece->getAlive()) continue;

            std::vector<std::pair<int, int>> possibleMoves = piece->getAllPossibleMoves(grid);

            for (auto& target : possibleMoves) {
				Move move;
				move.fromX = piece->getX();
				move.fromY = piece->getY();
				move.toX = target.first;
				move.toY = target.second;
				move.movedPiece = piece;
				move.capturedPiece = grid[target.first][target.second]; 

                allMoves.push_back(move);
            }
        }

     

        return allMoves;
    }
    \
    bool Board::isGameover() const {
        
        bool redFound = false, blackFound = false;
        for (Piece* p : redPieces) {
            if (p->getAlive() && p->getSymbol() == "RG") {
                redFound = true;
                break;
            }
        }
        for (Piece* p : blackPieces) {
            if (p->getAlive() && p->getSymbol() == "BG") {
                blackFound = true;
                break;
            }
        }
        return !redFound || !blackFound;
    }
    //tinh gia tri quan co 
    int Board::EvaluatePoint() const {
        int PointAI = 0;
        int PointPlayer = 0;

    
        for (Piece* p : blackPieces) {
            if (p->getAlive()) {
                p->updatePoint(p->getX(), p->getY());
                PointAI += p->getPoint();
            }
        }

        for (Piece* p : redPieces) {
            if (p->getAlive()) {
                p->updatePoint(p->getX(), p->getY());
                PointPlayer += p->getPoint();
            }
        }

       

        return PointAI - PointPlayer;
    }


    //undone
    void Board::undo()
    {
        if (history.IsEmpty()) return;
        Move lastMove = history.Pop();
		
        grid[lastMove.fromX][lastMove.fromY] = lastMove.movedPiece;
        grid[lastMove.toX][lastMove.toY] = lastMove.capturedPiece;

        if (lastMove.movedPiece)
            lastMove.movedPiece->setPosition(lastMove.fromX, lastMove.fromY);

        if (lastMove.capturedPiece) {
            lastMove.capturedPiece->setPosition(lastMove.toX, lastMove.toY);
            lastMove.capturedPiece->setAlive(true);
        }
         
       
        currentPlayer = (currentPlayer == PlayerColor::RED) ? PlayerColor::BLACK : PlayerColor::RED;
    }
  
    //minimax
    int Board::minimax(int depth, int alpha, int beta, bool isTurnBlack)
    {
        if (depth == 0 || this->isGameover())
            return this->EvaluatePoint();

        
        uint64_t key = generateZobristKey();

        
        int alphaOrig = alpha;
        int betaOrig = beta;

        int ttValue;
        if (TT.probe(key, depth, alpha, beta, ttValue)) {
            return ttValue; 
        }

        int value;

        if (isTurnBlack)
        {
            int maxEval = -1000000;
            std::vector<Move> moves = this->getAllPossibleMoves(PlayerColor::BLACK);
            if (moves.empty()) return EvaluatePoint();

            for (const Move& m : moves)
            {
                if (!this->movePiece(m.fromX, m.fromY, m.toX, m.toY))
                    continue; 

                value = minimax(depth - 1, alpha, beta, false);
                this->undo();

                if (value > maxEval) maxEval = value;
                if (value > alpha) alpha = value;

                if (alpha >= beta) break; 
            }

            int flag = EXACT;
            if (maxEval <= alphaOrig) flag = UPPERBOUND;
            else if (maxEval >= betaOrig) flag = LOWERBOUND;

            TT.store(key, depth, maxEval, flag);
            return maxEval;
        }
        else              
        {
            int minEval = 1000000;
            std::vector<Move> moves = this->getAllPossibleMoves(PlayerColor::RED);
            if (moves.empty()) return EvaluatePoint();

            for (const Move& m : moves)
            {
                if (!this->movePiece(m.fromX, m.fromY, m.toX, m.toY))
                    continue;

                value = minimax(depth - 1, alpha, beta, true);
                this->undo();

                if (value < minEval) minEval = value;
                if (value < beta) beta = value;

                if (alpha >= beta) break;
            }

            int flag = EXACT;
            if (minEval <= alphaOrig) flag = UPPERBOUND;
            else if (minEval >= betaOrig) flag = LOWERBOUND;

            TT.store(key, depth, minEval, flag);
            return minEval;
        }
    }
    

    Move Board::findBestMove(int depth)
    {
        int bestValue = -1000000;
        Move bestMove;

       
        std::vector<Move> moves = moveOrdering(PlayerColor::BLACK); 

    
        for (int i = 0; i < moves.size(); i++)
        {
            this->movePiece(moves[i].fromX, moves[i].fromY, moves[i].toX, moves[i].toY);
            int moveValue = minimax(depth - 1, -100000, 100000, false);
            this->undo();
            if (moveValue > bestValue)
            {
                bestValue = moveValue;
                bestMove = moves[i];
            }
            if(bestValue == 10000)
				break;

        }

        return bestMove;
    }
    bool Board::checkMate()
    {
        return true;
    }
    void Board::initZobristTable() {
        std::mt19937_64 rng(2025); 
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 9; ++j) {
                for (int k = 0; k < 14; ++k) {
                    zobristTable[i][j][k] = rng();
                }
            }
        }
    }
    uint64_t Board::generateZobristKey() const {
        uint64_t key = 0;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 9; ++j) {
                Piece* p = grid[i][j];
                if (p) {
                
                    int pieceIndex = p->getsymbolvalue();
                    key ^= zobristTable[i][j][pieceIndex];
                }
            }
        }

       
        if (currentPlayer == PlayerColor::RED)
            key ^= 0xF00BA4BAADF00DULL;

        return key;
    }
    bool Board::Luatnuocdidung(PlayerColor color)
    {
       
    }
    bool Board::isGeneralFacing() const {
        int redX = -1, redY = -1;
        int blackX = -1, blackY = -1;

        for (auto p : redPieces)
            if (p->getSymbol() == "RG" && p->getAlive()) {
                redX = p->getX();
                redY = p->getY();
                break;
            }

        for (auto p : blackPieces)
            if (p->getSymbol() == "BG" && p->getAlive()) {
                blackX = p->getX();
                blackY = p->getY();
                break;
            }

        if (redX == -1 || blackX == -1) return false;
        if (redY != blackY) return false; 

        int minX = std::min(redX, blackX);
        int maxX = std::max(redX, blackX);

       
        for (int i = minX + 1; i < maxX; i++) {
            if (grid[i][redY] != nullptr)
                return false;
        }

        return true; 
    }

    void Board::redo()
    {
		if (this->redon.IsEmpty()) return;
        Move move = redon.Pop();
		this->movePiece(move.fromX, move.fromY, move.toX, move.toY);
    }
    
   