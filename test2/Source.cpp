#include <SFML/Audio.hpp>
#include <optional>
#include"Board.h"
#include<random>
#include<ctime>
//#include "Piece.h"
int lamtron(int x)
{
    int rounded = round(x / 100.0) * 100;
    return rounded;
}
int main() {
    sf::RenderWindow window(sf::VideoMode({ 1024, 1127 }), "China Chess");
    /*  Game game;
      game.start();*/
      // tao am thanh
    Board board;

    sf::Texture quanxeden;
    quanxeden.setSmooth(1);
    sf::Texture quanxedo;
    sf::Texture bancotrong;
    sf::Texture quantuongden;
    sf::Texture quantuongdo;
    sf::Texture quansiden;
    sf::Texture quansido;
    sf::Texture quanphaoden;
    sf::Texture quanphaodo;
    sf::Texture quantotden;
    sf::Texture quantotdo;
    sf::Texture quanvuaden;
    sf::Texture quanvuado;
    sf::Texture quanmaden;
    sf::Texture quanmado;
    sf::Texture youlose;
    // load anh len
	youlose.loadFromFile("youlose.png");
    quanxeden.loadFromFile("quanxeden.png");
    quanxedo.loadFromFile("quanxedo.png");
    bancotrong.loadFromFile("bancotrong.png");
    quantuongden.loadFromFile("quantuongden.png");
    quantuongdo.loadFromFile("quantuongdo.png");
    quansiden.loadFromFile("quansiden.png");
    quansido.loadFromFile("quansido.png");
    quanphaoden.loadFromFile("quanphaoden.png");
    quanphaodo.loadFromFile("quanphaodo.png");
    quantotden.loadFromFile("quantotden.png");
    quantotdo.loadFromFile("quantotdo.png");
    quanvuaden.loadFromFile("quanvuaden.png");
    quanvuado.loadFromFile("quanvuado.png");
    quanmaden.loadFromFile("quanmaden.png");
    quanmado.loadFromFile("quanmado.png");
    bancotrong.loadFromFile("bancotrong.png");
    //quan co do
	sf::Sprite boardSprite(bancotrong);
    sf::Sprite quantuong(quantuongdo);
    sf::Sprite quantuong1(quantuongdo);
    sf::Sprite quanxe(quanxedo);
    sf::Sprite quanxe1(quanxedo);
    sf::Sprite quansi(quansido);
    sf::Sprite quansi1(quansido);
    sf::Sprite quanphao(quanphaodo);
    sf::Sprite quanphao1(quanphaodo);
    sf::Sprite quantot(quantotdo);
    sf::Sprite quantot1(quantotdo);
    sf::Sprite quantot2(quantotdo);
    sf::Sprite quantot3(quantotdo);
    sf::Sprite quantot4(quantotdo);
    sf::Sprite quanvua(quanvuado);
    sf::Sprite quanma(quanmado);
    sf::Sprite quanma1(quanmado);
    //quan co den
    sf::Sprite quantuongd(quantuongden);
    sf::Sprite quantuongd1(quantuongden);
    sf::Sprite quanxed(quanxeden);
    sf::Sprite quanxed1(quanxeden);
    sf::Sprite quansid(quansiden);
    sf::Sprite quansid1(quansiden);
    sf::Sprite quanphaod(quanphaoden);
    sf::Sprite quanphaod1(quanphaoden);
    sf::Sprite quantotd(quantotden);
    sf::Sprite quantotd1(quantotden);
    sf::Sprite quantotd2(quantotden);
    sf::Sprite quantotd3(quantotden);
    sf::Sprite quantotd4(quantotden);
    sf::Sprite quanvuad(quanvuaden);
    sf::Sprite quanmad(quanmaden);
    sf::Sprite quanmad1(quanmaden);
    // phe do

    board.grid[0][4] = new General(PlayerColor::BLACK, 0, 4, true, 10000, quanvuad);
    board.grid[0][3] = new Advisor(PlayerColor::BLACK, 0, 3, true, 250, quansid);
    board.grid[0][5] = new Advisor(PlayerColor::BLACK, 0, 5, true, 250, quansid1);
    board.grid[0][2] = new Elephant(PlayerColor::BLACK, 0, 2, true, 250, quantuongd1);
    board.grid[0][6] = new Elephant(PlayerColor::BLACK, 0, 6, true, 250, quantuongd);
    board.grid[0][1] = new Knight(PlayerColor::BLACK, 0, 1, true, 400, quanmad);
    board.grid[0][7] = new Knight(PlayerColor::BLACK, 0, 7, true, 400, quanmad1);
    board.grid[0][0] = new Rock(PlayerColor::BLACK, 0, 0, true, 1000, quanxed);
    board.grid[0][8] = new Rock(PlayerColor::BLACK, 0, 8, true, 1000, quanxed1);
    board.grid[2][1] = new Cannon(PlayerColor::BLACK, 2, 1, true, 500, quanphaod);
    board.grid[2][7] = new Cannon(PlayerColor::BLACK, 2, 7, true, 500, quanphaod1);
    board.grid[3][0] = new Pawn(PlayerColor::BLACK, 3, 0, true, 100, quantotd);
    board.grid[3][2] = new Pawn(PlayerColor::BLACK, 3, 2, true, 100, quantotd1);
    board.grid[3][4] = new Pawn(PlayerColor::BLACK, 3, 4, true, 100, quantotd2);
    board.grid[3][6] = new Pawn(PlayerColor::BLACK, 3, 6, true, 100, quantotd3);
    board.grid[3][8] = new Pawn(PlayerColor::BLACK, 3, 8, true, 100, quantotd4);

    // phe den


    board.grid[9][4] = new General(PlayerColor::RED, 9, 4, true, 10000, quanvua);
    board.grid[9][3] = new Advisor(PlayerColor::RED, 9, 3, true, 250, quansi1);
    board.grid[9][5] = new Advisor(PlayerColor::RED, 9, 5, true, 250, quansi);
    board.grid[9][2] = new Elephant(PlayerColor::RED, 9, 2, true, 250, quantuong);
    board.grid[9][6] = new Elephant(PlayerColor::RED, 9, 6, true, 250, quantuong1);
    board.grid[9][1] = new Knight(PlayerColor::RED, 9, 1, true, 400, quanma1);
    board.grid[9][7] = new Knight(PlayerColor::RED, 9, 7, true, 400, quanma);
    board.grid[9][0] = new Rock(PlayerColor::RED, 9, 0, true, 1000, quanxe1);
    board.grid[9][8] = new Rock(PlayerColor::RED, 9, 8, true, 1000, quanxe);
    board.grid[7][1] = new Cannon(PlayerColor::RED, 7, 1, true, 500, quanphao1);
    board.grid[7][7] = new Cannon(PlayerColor::RED, 7, 7, true, 500, quanphao);
    board.grid[6][0] = new Pawn(PlayerColor::RED, 6, 0, true, 100, quantot);
    board.grid[6][2] = new Pawn(PlayerColor::RED, 6, 2, true, 100, quantot1);
    board.grid[6][4] = new Pawn(PlayerColor::RED, 6, 4, true, 100, quantot2);
    board.grid[6][6] = new Pawn(PlayerColor::RED, 6, 6, true, 100, quantot3);
    board.grid[6][8] = new Pawn(PlayerColor::RED, 6, 8, true, 100, quantot4);
   
    sf::Vector2u size = quanxeden.getSize();
    sf::Sprite test(quanvuado);
	test.setPosition({ 100,100 });
    sf::CircleShape diem(10);
    diem.setFillColor(sf::Color::Red);
   
    //vi tri cac o tren bam co
    sf::Vector2f PosBoard[10][9] = {
     { {101,100}, {203,100},  {305,101}, {408,101}, {511,102}, {611,101}, {713,100}, {818,101}, {918,101} },
     { {100,202}, {202,202}, {305,204}, {408,203}, {511,203}, {613,204}, {716,203}, {817,203}, {922,203} },
     { {101,304}, {205,304}, {304,305}, {407,306}, {512,305}, {612,305}, {717,305}, {819,302}, {919,302} },
     { {101,406}, {204,407}, {308,408}, {410,409}, {509,410}, {613,408}, {717,407}, {818,407}, {922,404} },
     { {101,507}, {205,505}, {307,509}, {408,512}, {509,510}, {610,511}, {717,508}, {819,508}, {920,509} },
     { {102,609}, {201,613}, {306,614}, {409,615}, {512,615}, {613,613}, {716,612}, {817,611}, {918,611} },
     { {100,716}, {203,715}, {305,714}, {408,716}, {511,715}, {614,715}, {716,714}, {818,713}, {923,715} },
     { {101,815}, {204,811}, {306,817}, {408,817}, {510,819}, {613,820}, {716,816}, {817,817}, {920,815} },
     { {101,917} , {204,917}   ,{306,917}, { 408,917 }, { 510,917 } ,{ 613,917 } ,{ 716,917 }, { 817,917 } ,{ 920,917 } } ,
     { {101,1017} , {204,1017}   ,{306,1017}, { 408,1017 }, { 510,1017 } ,{ 613,1017 } ,{ 716,1017 }, { 817,1017 } ,{ 920,1017 } },
    };
    diem.setFillColor(sf::Color::Red);
    
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board.grid[i][j] != nullptr)
            {
				board.grid[i][j]->sprite.setPosition({PosBoard[i][j].x - size.x/2,PosBoard[i][j].y-size.y/2});
               
            }

        }
    }

    sf::Vector2f mousePos;
   





    sf::CircleShape node(38);
    
    sf::CircleShape node1(10);
    Piece* selectedPiece = nullptr;
    std::vector<sf::CircleShape> dots;
    bool pass = false;
	std::pair <int, int> move;
    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {   
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }


            // Nhấn chuột
            if (board.currentPlayer == PlayerColor::RED){
                 node.setFillColor(sf::Color::Transparent);
                // node1.setFillColor(sf::Color::Transparent);
                if (event->is<sf::Event::MouseButtonPressed>()) {
                    auto mouse = event->getIf<sf::Event::MouseButtonPressed>();
                    mousePos = window.mapPixelToCoords(mouse->position);
                    if (mouse->button == sf::Mouse::Button::Left) { // click chuot trai vao quan xe
                        std::cout << mousePos.x << " , " << mousePos.y << "\n";




                        bool handled = false;


                        for (auto& dot : dots) {
                            if (dot.getGlobalBounds().contains(mousePos) && selectedPiece) {
                                board.movePiece(move.first, move.second, lamtron(dot.getPosition().y) / 100 - 1, lamtron(dot.getPosition().x) / 100 - 1);

                                selectedPiece->sprite.setPosition({ static_cast<float>(dot.getPosition().x - size.x / 2 + 10),static_cast<float>(dot.getPosition().y - size.y / 2 + 10) });
                                board.printBoard();
                                selectedPiece->sprite.setColor(sf::Color::White);
                                selectedPiece = nullptr;
                                dots.clear();
                                handled = true;
                                break;
                            }
                        }



                        if (!handled) {
                            if (selectedPiece) selectedPiece->sprite.setColor(sf::Color::White);
                            dots.clear();
                            selectedPiece = nullptr;

                            for (int i = 0; i < 10; i++)
                                for (int j = 0; j < 9; j++)
                                    if (board.grid[i][j] &&
                                        board.grid[i][j]->sprite.getGlobalBounds().contains(mousePos) &&
                                        board.grid[i][j]->getColor() == PlayerColor::RED) {

                                        selectedPiece = board.grid[i][j];
                                        move = { i, j };
                                        selectedPiece->sprite.setColor(sf::Color::Red);

                                        for (auto& m : board.getAllPossibleMoves(i, j)) {
                                            sf::CircleShape dot(10.f);
                                            dot.setFillColor(sf::Color::Red);
                                            dot.setPosition(PosBoard[m.first][m.second] - sf::Vector2f(10.f, 10.f));
                                            int col = lamtron(dot.getPosition().x) / 100 - 1;
                                            int row = lamtron(dot.getPosition().y) / 100 - 1;

                                           
                                                if (board.grid[row][col]!=nullptr) {
                                                   
													dot.setOrigin({ dot.getRadius(),dot.getRadius() });
                                                   dot.setScale({ 4,4});
													
                                                    dot.setFillColor(sf::Color(255,0,0,0));
                                                    board.grid[row][col]->sprite.setColor(sf::Color::Magenta);
                                                }
                                          
                                            dots.push_back(dot);

                                        }

                                        handled = true;
                                        break;
                                    }

                        }
                      
                        

                         


                      
                           

                        if (selectedPiece==nullptr)
                        {
                            for (int i = 0; i < 10; i++)
                                for (int j = 0; j < 9; j++)
                                    if (board.grid[i][j] != nullptr && board.grid[i][j]->getColor() == PlayerColor::BLACK)
                                        board.grid[i][j]->sprite.setColor(sf::Color::White);
                        }


                        if (!handled && selectedPiece) {
                            selectedPiece->sprite.setColor(sf::Color::White);
                            selectedPiece = nullptr;
                            dots.clear();
                        }
                       


                    }





                        


                    



                }



            }
            else {
                Move move = board.findBestMove(4);
                board.movePiece(move.fromX, move.fromY, move.toX, move.toY);
                std::cout << "AI di chuyen tu (" << move.fromX << ", " << move.fromY << ") den (" << move.toX << ", " << move.toY << ")\n";
                std::cout << PosBoard[move.toX][move.toY].x << " " << PosBoard[move.toX][move.toY].y << "\n";
                board.grid[move.toX][move.toY]->sprite.setPosition({ PosBoard[move.toX][move.toY].x - size.x / 2, PosBoard[move.toX][move.toY].y - size.y / 2 });
                node1.setFillColor(sf::Color::Yellow);
                node.setOutlineThickness(2);
                node.setOutlineColor(sf::Color::Red);
                int bankinh = node.getRadius();
                int bankinh1 = node1.getRadius();
                node.setPosition({ PosBoard[move.toX][move.toY].x - bankinh ,PosBoard[move.toX][move.toY].y - bankinh
                    });

                node1.setPosition({ PosBoard[move.fromX][move.fromY].x - bankinh1 ,PosBoard[move.fromX][move.fromY].y - bankinh1 });


            }
        }

        window.clear();
		window.draw(boardSprite);
        for(int i = 0 ;i<10;i++)
            for(int j=0;j<9;j++)
                if(board.grid[i][j]!=nullptr)
					window.draw(board.grid[i][j]->sprite);
        for (auto& dot : dots)
        {
            window.draw(dot);
        }
        if (board.isGameover())
       {
			
			sf::Sprite lose(youlose);
			lose.setPosition({ 50,300 });
			window.draw(lose);
       }
        window.draw(node);
        window.draw(node1);
        window.display();
    }

    return 0;
}