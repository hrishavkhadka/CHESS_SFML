#include "def.h"
#include <bitset>
#include "boardstate.h"



void boardstate::printboardinbits() {
	for (int i=7; i >=0; i--) {
		for (int j=0; j < 8; j++) {
			std::cout <<(piece(this->board[i][j]))<<"\t";
		}
		std::cout << std::endl;
	}
	std::cout<<"turn : "<<gturn<<std::endl;
	std::cout<<"turn : "<<std::bitset<8>(board[0][0])<<std::endl;
}
void boardstate::printboard(){
    for (int i=7; i >=0; i--) {
		for (int j=0; j < 8; j++) {
			switch(piece(board[i][j])){
            case empty:{
                std::cout<<".  ";
                break;
            }
            case p:{
                std::cout<<"p  ";
                break;
            }
            case n:{
                std::cout<<"n  ";
                break;
            }
            case b:{
                std::cout<<"b  ";
                break;
            }
            case r:{
                std::cout<<"r  ";
                break;
            }
            case q:{
                std::cout<<"q  ";
                break;
            }
            case k:{
                std::cout<<"k  ";
                break;
            }
            case P:{
                std::cout<<"P  ";
                break;
            }
            case N:{
                std::cout<<"N  ";
                break;
            }
            case B:{
                std::cout<<"B  ";
                break;
            }
            case R:{
                std::cout<<"R  ";
                break;
            }
            case Q:{
                std::cout<<"Q  ";
                break;
            }
            case K:{
                std::cout<<"K  ";
                break;
            }
            default:{
                std::cout<<"error fen piece not identified"<<std::endl;
                break;
            }
		}

	}
	std::cout << std::endl;
    }
}




