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
        if (!piece->isValidMove(toX, toY, grid)) return false;
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
    
    std::vector<std::pair<int, int>> Board::getAllPossibleMoves(const int &x, const int &y) const
    {
        std::vector<std::pair<int, int>> moves;
        if (x < 0 || x > 9 || y < 0 || y > 8) {
            return moves;
        }
        Piece* piece = grid[x][y];
        if (piece == nullptr) return moves;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 9; j++) {
                if (i == x && j == y) continue;
                Piece* target = grid[i][j];
                if (target != nullptr && target->getColor() == piece->getColor()) continue;
                if (piece->isValidMove(i, j, const_cast<Piece * (*)[9]>(grid))) {
                    moves.push_back({ i, j });
                }
            }
        }
        return moves;
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
                // ... tạo move ...
				Move move;
				move.fromX = piece->getX();
				move.fromY = piece->getY();
				move.toX = target.first;
				move.toY = target.second;
				move.movedPiece = piece;
				move.capturedPiece = grid[target.first][target.second]; // NULL nếu không có quân bị ăn

                allMoves.push_back(move);
            }
        }

        // THÊM SẮP XẾP NƯỚC ĐI Ở ĐÂY
        //std::sort(allMoves.begin(), allMoves.end(), [this](const Move& a, const Move& b) {
        //    return scoreMove(a) > scoreMove(b); // Nước đi tốt hơn được xét trước
        //    });

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

        if (this->isGeneralFacing()) {
            PointAI -= 10000;
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
        if (depth == 0 || this->isGameover()||this->isGeneralFacing())
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
        std::vector<Move> moves = this->getAllPossibleMoves(PlayerColor::BLACK);
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
        }

        return bestMove;
    }
    bool Board::checkMate(int x, int y)
    {
        
        for (auto& m : getAllPossibleMoves(x, y))
        {
            Piece* target = grid[m.first][m.second];
            if (target == nullptr) continue;

            std::string symbol = target->getSymbol();

            if (symbol == "BG" ||
                symbol == "RG" )
            {
            
                return true;
            }
        }
        return false;
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
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 9; ++j) {
                Piece* piece = grid[i][j];
                if (piece != nullptr && piece->getColor() == color) {
                    std::vector<std::pair<int, int>> moves = getAllPossibleMoves(i, j);
                    for (const auto& move : moves) {

                       
                        movePiece(i, j, move.first, move.second);

                        bool biChieu = checkMate(move.first,move.second);

                       
                        undo();

                       
                        if (!biChieu)
                            return true; 
                    }
                }
            }
        }
        return false; 
    }
    bool Board::isGeneralFacing() const {
        int redX = -1, redY = -1;
        int blackX = -1, blackY = -1;

       
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 9; ++j) {
                Piece* p = grid[i][j];
                if (p != nullptr) {
                    if (p->getSymbol() == "RG") { 
                        redX = i; redY = j;
                    }
                    else if (p->getSymbol() == "BG") { 
                        blackX = i; blackY = j;
                    }
                }
            }
        }

       
        if (redX == -1 || blackX == -1) return false;

       
        if (redY != blackY) return false;

       
        int y = redY;
        int start = std::min(redX, blackX) + 1;
        int end = std::max(redX, blackX);

        for (int x = start; x < end; ++x) {
            if (grid[x][y] != nullptr) {
                return false; 
            }
        }

    
        return true;
    }
    int Board::isYouWin() const
    {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 9; ++j) {
                Piece* p = grid[i][j];
                if (p != nullptr) {
                    if (p->getSymbol() == "RG")
                        return 0;   
                    else if (p->getSymbol() == "BG")
                        return 1;
                }
            }
        }
        return 1000;
    }
    void Board::redo(const Move & move)
    {
        if (redon.IsFull()) return;
		this->redon.Push(move);
    }
    bool Board::moveodering(const PlayerColor& c )
    {
		if (history.IsEmpty()) return false;
		Move lastMove = history.Top();
        if(lastMove.capturedPiece == nullptr)
			return  false;
        if (c == PlayerColor::BLACK)
        {
            if (lastMove.capturedPiece->getSymbol() == "RC" || lastMove.capturedPiece->getSymbol() == "RR" || lastMove.capturedPiece->getSymbol() == "RG")
                return true;
        }
		return false;
    }
   