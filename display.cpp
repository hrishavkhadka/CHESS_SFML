#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "def.h"
#include "boardstate.h"

constexpr int window_height = 1000;
constexpr int window_width = 1000;
constexpr int board_height = window_height * 1;
constexpr int board_width = window_width * 1;
constexpr int square_height = board_height / 8;
constexpr int square_width = board_width / 8;

bool movelistcontains(unsigned int mo, unsigned int movelist[256]) {
    for (int i{ 0 }; i < 256; i++) {
        if ((movelist[i] & 0b111111111111) == (mo & 0b111111111111)) { 
            //std::cout << "movelist contains mo" << std::endl;
            return true; 
        }
        if (movelist[i] == 0) { break; }
        
    }
    return false;
}

int displaychess(boardstate* brd)
{
    
   // U1 positionarray[8][8];                         //printing is done purely based on this array . link between display module and rule module
   // brd->getarray(positionarray);
    
    sf::RectangleShape *pce;                       // 64 member shape array for piece on each square. values assigned at runtime according to positionarray[]
    pce = new sf::RectangleShape[64];

    for (int i = 0; i < 64; i++) {                   //dynamically declared to avoid stackoverflow
        pce[i].setSize(sf::Vector2f(square_width,square_height));
    }
    
    sf::Texture boardtexture;                         //loading textures from hereon.loaded from project folder. understand from the code. 
    boardtexture.loadFromFile("img/chessboard3.jpg"); 
   
    sf::RectangleShape board;                         //board texture assigned to board shape.
    board.setSize(sf::Vector2f(board_width,board_height));
    board.setTexture(&boardtexture);
   // board.setPosition(sf::Vector2f(square_width, square_height));

    sf::Texture bktexture;
    bktexture.loadFromFile("img/bk.png");
   
    sf::Texture bptexture;
    bptexture.loadFromFile("img/bp.png");
 
    sf::Texture bqtexture;
    bqtexture.loadFromFile("img/bq.png");
 
    sf::Texture brtexture;
    brtexture.loadFromFile("img/br.png");
 
    sf::Texture bbtexture;
    bbtexture.loadFromFile("img/bb.png");

    sf::Texture bntexture;
    bntexture.loadFromFile("img/bn.png");

    sf::Texture wktexture;
    wktexture.loadFromFile("img/wk.png");

    sf::Texture wptexture;
    wptexture.loadFromFile("img/wp.png");
 
    sf::Texture wqtexture;
    wqtexture.loadFromFile("img/wq.png");
 
    sf::Texture wrtexture;
    wrtexture.loadFromFile("img/wr.png");
 
    sf::Texture wbtexture;
    wbtexture.loadFromFile("img/wb.png");
 
    sf::Texture wntexture;
    wntexture.loadFromFile("img/wn.png");
    
    sf::SoundBuffer move;                        //move sound effect.
    move.loadFromFile("sound/movesound.wav");
    sf::Sound movesound{ move };
    
    int x1, y1, x2, y2;                          //to store mouse coordinates later.
    bool generate_flag{ false },draw_bit{ true }, mouse_bit{ true };    //'switches' to activate or deactivate certain functions based on a sequence of events when pieces need to be moved 
    unsigned int mo;
    int posindex{ 0 };
    unsigned int movelist[256];

    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "CHESS", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(30);
    while (window.isOpen())
    {
 
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(board);

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && mouse_bit) {    //when mouse is pressed first.
            sf::Vector2i mousepos = sf::Mouse::getPosition(window);
            x1 = mousepos.x/square_width;    //x1 and y1 for where mouse is clicked
            y1 = mousepos.y/square_height;
            draw_bit = false;
            mouse_bit = false;  //made false to enable next mouse functions
        }
        if (event.type == sf::Event::MouseMoved && !mouse_bit) {           //when mouse is held
            pce[x1*8  + y1].setPosition(sf::Vector2f(event.mouseMove.x - square_height/2, event.mouseMove.y - square_width/2));
        }
        if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && !mouse_bit) {  //when mouse is released
            sf::Vector2i mousepos{ sf::Mouse::getPosition(window) };
            x2 = mousepos.x/square_width;    //x2 and y2 for where mouse is released
            y2 = mousepos.y/square_height;
            mo = 0;
            setmove(mo, 7 - y1, x1, 7 - y2, x2, 0, 0, 0, 0, 0);
            if ( movelistcontains(mo,movelist)) {
                
                brd->makemove(mo);
                generate_flag = true;
                movesound.play();
               // pce[x1 * 8 + y1].setPosition(sf::Vector2f((x2 * square_width), (y2 * square_height)));
               // window.draw(pce[x1 * 8 + y1]);
            }
            draw_bit = true;   //draw bit set to true to reassign and reposition according to new values. 
            mouse_bit = true;  //made true at end of mouse clicking cycle
            
        }



        for (int i = 0; i < 8; i++) {                                     //to draw (and reassign if pieces are moved).
            for (int j = 0; j < 8; j++) {
                posindex = i * 8 + j;
                if ( piece(brd->getsquare((7-j),i)) != empty ) {
                    
                    if (draw_bit) {                                            //draw bit controls whether to reassign or simply draw as previous.
                        
                        switch ( piece(brd->getsquare((7-j), i)) ) {
                        case(r):
                            pce[posindex].setTexture(&brtexture);
                            break;
                        case(n):
                            pce[posindex].setTexture(&bntexture);
                            break;
                        case(b):
                            pce[posindex].setTexture(&bbtexture);
                            break;
                        case(q):
                            pce[posindex].setTexture(&bqtexture);
                            break;
                        case(k):
                            pce[posindex].setTexture(&bktexture);
                            break;
                        case(p):
                            pce[posindex].setTexture(&bptexture);
                            break;
                        case(R):
                            pce[posindex].setTexture(&wrtexture);
                            break;
                        case(N):
                            pce[posindex].setTexture(&wntexture);
                            break;
                        case(B):
                            pce[posindex].setTexture(&wbtexture);
                            break;
                        case(Q):
                            pce[posindex].setTexture(&wqtexture);
                            break;
                        case(K):
                            pce[posindex].setTexture(&wktexture);
                            break;
                        case(P):
                            pce[posindex].setTexture(&wptexture);
                            break;
                            // case(0):
                            //     piece[i].setTexture(&bptexture);
                        default:
                            break;
                        }
                        pce[posindex].setPosition(sf::Vector2f((i * square_width), ( j * square_height)));      //position set/reset according to index in RectangleShape array
         
                    }
                    window.draw(pce[posindex]);
                }
            }
        }

        window.display();
        
        if (draw_bit) {
            draw_bit = false;
            for (int i{ 0 }; i < 256; i++) { movelist[i] == 0; }
            brd->getmove(movelist);
        }
        if (generate_flag) {
            mo = minimaxinit(0, *brd, brd->getturn());
            brd->makemove(mo);
            movesound.play();

            draw_bit = true;
            generate_flag = false;
        }

       

               
        
    }
    delete[] pce;
    return 0;
}