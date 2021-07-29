#include "def.h"
#include <bitset>
#include "boardstate.h"

//   rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1

void boardstate::translatefen(std::string fen){
    int ra{7};
    int fi{0};
    int spacecount{0};
    int enpas_r{8};
    int enpas_f{8};


    for (char& c: fen){
        if(c == '/'){
            ra--;
            fi=0;
            continue;
        }
        else if(c == ' '){
            spacecount++;
            std::cout << "space counted"<<std::endl;
            continue;
        }
        if(spacecount == 0){
            if(c >= '1' && c <= '8'){
                fi+=(c-'1');
            }
            else{
                switch(c){
                case 'p':{
                    this->board[ra][fi] = (board[ra][fi] & 0b11110000) | ( p & 0b00001111) ;
                    break;
                }
                case 'n':{
                    this->board[ra][fi] = (board[ra][fi] & 0b11110000) | ( n & 0b00001111);
                    break;
                }
                case 'b':{
                    this->board[ra][fi] = (board[ra][fi] & 0b11110000) | ( b & 0b00001111);
                    break;
                }
                case 'r':{
                    this->board[ra][fi] = (board[ra][fi] & 0b11110000) | ( r & 0b00001111);
                    break;
                }
                case 'q':{
                    this->board[ra][fi] = (board[ra][fi] & 0b11110000) | ( q & 0b00001111);
                    break;
                }
                case 'k':{
                    this->board[ra][fi] = (board[ra][fi] & 0b11110000) | ( k & 0b00001111);
                    break;
                }
                case 'P':{
                    this->board[ra][fi] = (board[ra][fi] & 0b11110000) | ( P & 0b00001111);
                    break;
                }
                case 'N':{
                    this->board[ra][fi] = (board[ra][fi] & 0b11110000) | ( N & 0b00001111);
                    break;
                }
                case 'B':{
                    this->board[ra][fi] = (board[ra][fi] & 0b11110000) | ( B & 0b00001111);
                    break;
                }
                case 'R':{
                    this->board[ra][fi] = (board[ra][fi] & 0b11110000) | ( R & 0b00001111);
                    break;
                }
                case 'Q':{
                    this->board[ra][fi] = (board[ra][fi] & 0b11110000) | ( Q & 0b00001111);
                    break;
                }
                case 'K':{
                    this->board[ra][fi] = (board[ra][fi] & 0b11110000) | ( K & 0b00001111);
                    break;
                }
                default:{
                    std::cout<<"error fen piece not identified"<< std::endl << '.'<<c<<'.'  <<std::endl;
                    break;
                }
                }
                std::cout << std::bitset<8>(board[ra][fi]) <<"\t"<<c<<"\t"<<piece(board[ra][fi])<<std::endl;
                fi++;
                continue;

            }
            fi++;
            continue;
        }
        else if(spacecount == 1){
            if(c == 'b'){
                sturn(0);
                //board[0][0] == board[0][0] & 0b01111111;
            }
            else if(c == 'w'){
                sturn(1);
                //board[0][0] == board[0][0] | 0b10000000;
            }
            else{
                std::cout<<"fen turn error"<<std::endl;
            }
            std::cout<<"turn is "<<gturn<<std::endl;
            continue;
        }
        else if(spacecount == 2){
            if( c == 'K'){
                oncastle(board[0][4]);
                oncastle(board[0][0]);
            }
            else if(c == 'Q'){
                oncastle(board[0][4]);
                oncastle(board[0][7]);
            }
            else if(c == 'k'){
                oncastle(board[7][4]);
                oncastle(board[7][0]);
            }
            else if(c == 'q'){
                oncastle(board[7][4]);
                oncastle(board[7][7]);
            }

            else{
                std::cout<<"castle not recognised"<<std::endl;
            }
            continue;
        }
        else if(spacecount == 3){
            if(c <= '8' && c>='1'){
                enpas_r = c - ('1');
            }
            else if(c>='a' && c<='h'){
                enpas_f = c - ('a');
            }
            else if(c == '-'){
                continue;
            }
            else{
                std::cout<<"fen enpas error"<<std::endl;
            }
            continue;
        }
        else if(spacecount == 4){
            break;
        }


    }

    if(enpas_r < 8 && enpas_f < 8){
        setenpassant(enpas_r,enpas_f);
    }
    if(enpas == 64){std::cout<<"enpa defaulted"<<std::endl;}

    std::cout <<"enpassant set to"<< std::bitset<8>(this->enpas) <<std::endl;

}
