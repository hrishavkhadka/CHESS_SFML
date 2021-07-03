#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>


int main()
{
    int positionarray[64] =                         //printing is done purely based on this array . link between display module and rule module
    {
    -500,-300,-320,-900,-10000,-320,-300,-500,      //minus for black. usual piece positions
    -100,-100,-100,-100,-100,-100,-100,-100,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    100,100,100,100,100,100,100,100,
    500,300,320,900,10000,320,300,500
    };
    
    sf::RectangleShape *piece;                       // 64 member shape array for piece on each square. values assigned at runtime according to positionarray[]
    piece = new sf::RectangleShape[64];

    for (int i = 0; i < 64; i++) {                   //dynamically declared to avoid stackoverflow
        piece[i].setSize(sf::Vector2f(128,128));
    }
    
    sf::Texture boardtexture;                         //loading textures from hereon.loaded from project folder. understand from the code. 
    boardtexture.loadFromFile("img/chessboard3.jpg"); 
   
    sf::RectangleShape board;                         //board texture assigned to board shape.
    board.setSize(sf::Vector2f(1024, 1024));
    board.setTexture(&boardtexture);

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
    bool draw_bit{ true }, mouse_bit{ true };    //'switches' to activate or deactivate certain functions based on a sequence of events when pieces need to be moved 

    sf::RenderWindow window(sf::VideoMode(1024, 1024), "CHESS", sf::Style::Titlebar | sf::Style::Close);

    while (window.isOpen())
    {
 
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

 

        /*
        

        */

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && mouse_bit) {    //when mouse is pressed first.
            sf::Vector2i mousepos{ sf::Mouse::getPosition(window) };
            x1 = mousepos.x;    //x1 and y1 for where mouse is clicked
            y1 = mousepos.y;
            draw_bit = false;
            mouse_bit = false;  //made false to enable next mouse functions
        }
        if (event.type == sf::Event::MouseMoved && !mouse_bit) {           //when mouse is held
            piece[x1 / 128 + y1 / 128 * 8].setPosition(sf::Vector2f(event.mouseMove.x - 64, event.mouseMove.y - 64));
        }
        if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && !mouse_bit) {  //when mouse is released
            sf::Vector2i mousepos{ sf::Mouse::getPosition(window) };
            x2 = mousepos.x;    //x2 and y2 for where mouse is released
            y2 = mousepos.y;
            positionarray[x2 / 128 + y2 / 128 * 8] = positionarray[x1 / 128 + y1 / 128 * 8]; //released sq = clicked sq
            positionarray[x1 / 128 + y1 / 128 * 8] = 0;                                      //clicked sq = 0 
            draw_bit = true;   //draw bit set to true to reassign and reposition according to new values. 
            mouse_bit = true;  //made true at end of mouse clicking cycle
            movesound.play();
        }

        window.clear();
        window.draw(board);

        for (int i = 0; i < 64; i++) {                                     //to draw (and reassign if pieces are moved).
            if (positionarray[i]) {
                if (draw_bit) {                                            //draw bit controls whether to reassign or simply draw as previous.
                    switch (positionarray[i]) {
                    case(-500):
                        piece[i].setTexture(&brtexture);
                        break;
                    case(-300):
                        piece[i].setTexture(&bntexture);
                        break;
                    case(-320):
                        piece[i].setTexture(&bbtexture);
                        break;
                    case(-900):
                        piece[i].setTexture(&bqtexture);
                        break;
                    case(-10000):
                        piece[i].setTexture(&bktexture);
                        break;
                    case(-100):
                        piece[i].setTexture(&bptexture);
                        break;
                    case(500):
                        piece[i].setTexture(&wrtexture);
                        break;
                    case(300):
                        piece[i].setTexture(&wntexture);
                        break;
                    case(320):
                        piece[i].setTexture(&wbtexture);
                        break;
                    case(900):
                        piece[i].setTexture(&wqtexture);
                        break;
                    case(10000):
                        piece[i].setTexture(&wktexture);
                        break;
                    case(100):
                        piece[i].setTexture(&wptexture);
                        break;
                        // case(0):
                        //     piece[i].setTexture(&bptexture);
                    default:
                        break;
                    }
                    piece[i].setPosition(sf::Vector2f((i % 8) * 128, (i / 8) * 128));      //position set/reset according to index in RectangleShape array
                    
                }
                window.draw(piece[i]);
            }
        }




        window.display();       
        
    }
    delete[] piece;
    return 0;
}