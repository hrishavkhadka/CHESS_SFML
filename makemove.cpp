#include "def.h"
#include "boardstate.h"


void boardstate::shiftpiece(int fi,int fj,int ti,int tj){
    board[ti][tj]= (board[ti][tj] & 0b10000000) | (board[fi][fj] & 0b00001111);   //put from piece and turn off castling
    board[fi][fj]= (board[fi][fj] & 0b10000000) | (0b00000110);                   //empty and turn off castling

    resetenpassant;
    changeturn;
    //printboard();
}

void boardstate::makemove(unsigned int m){
    if(m == 0){
        //std::cout<<"empty move"<<std::endl;
        return;
    }
    //std::cout<<"make move called : "<<gfromi(m)<<gfromj(m)<<"\t"<<gtoi(m)<<gtoj(m)<<std::endl;

    //enpassant
    if(piece(board[gfromi(m)][gfromj(m)])==p || piece(board[gfromi(m)][gfromj(m)])==P){

            if(gtoi(m)==3 && gfromi(m)==1){    //pawn jump
                shiftpiece(gfromi(m),gfromj(m),gtoi(m),gtoj(m));
                setenpassant(2,gfromj(m));
                //std::cout<<"en passant set at : 2"<<gfromj(m)<<std::endl;
            }

            else if(gtoi(m)==4 && gfromi(m)==6){   //pawn jump
                shiftpiece(gfromi(m),gfromj(m),gtoi(m),gtoj(m));
                setenpassant(5,gfromj(m));
                //std::cout<<"en passant set at : 5"<<gfromj(m)<<std::endl;
            }

            else if(gtoi(m)==7){   //white promotion
                if(gpromq(m)){
                    shiftpiece(gfromi(m),gfromj(m),gtoi(m),gtoj(m));
                    board[gtoi(m)][gtoj(m)] = (board[gtoi(m)][gtoj(m)] & 0b10000000) | (Q&0b00001111);
                }
                else if(gpromr(m)){
                    shiftpiece(gfromi(m),gfromj(m),gtoi(m),gtoj(m));
                    board[gtoi(m)][gtoj(m)] = (board[gtoi(m)][gtoj(m)] & 0b10000000) | (R&0b00001111);
                }
                else if(gpromb(m)){
                    shiftpiece(gfromi(m),gfromj(m),gtoi(m),gtoj(m));
                    board[gtoi(m)][gtoj(m)] = (board[gtoi(m)][gtoj(m)] & 0b10000000) | (B&0b00001111);
                }
                else if(gpromn(m)){
                    shiftpiece(gfromi(m),gfromj(m),gtoi(m),gtoj(m));
                    board[gtoi(m)][gtoj(m)] = (board[gtoi(m)][gtoj(m)] & 0b10000000) | (N&0b00001111);
                }
                else{
                    shiftpiece(gfromi(m), gfromj(m), gtoi(m), gtoj(m));
                    board[gtoi(m)][gtoj(m)] = (board[gtoi(m)][gtoj(m)] & 0b10000000) | (Q & 0b00001111);
                    std::cout<<"white promotion not made"<<std::endl;
                }
            }
            else if(gtoi(m)==0){         //black promotion
                if(gpromq(m)){
                    shiftpiece(gfromi(m),gfromj(m),gtoi(m),gtoj(m));
                    board[gtoi(m)][gtoj(m)] = (board[gtoi(m)][gtoj(m)] & 0b10000000) | (q&0b00001111);
                }
                else if(gpromr(m)){
                    shiftpiece(gfromi(m),gfromj(m),gtoi(m),gtoj(m));
                    board[gtoi(m)][gtoj(m)] = (board[gtoi(m)][gtoj(m)] & 0b10000000) | (r&0b00001111);
                }
                else if(gpromb(m)){
                    shiftpiece(gfromi(m),gfromj(m),gtoi(m),gtoj(m));
                    board[gtoi(m)][gtoj(m)] = (board[gtoi(m)][gtoj(m)] & 0b10000000) | (b&0b00001111);
                }
                else if(gpromn(m)){
                    shiftpiece(gfromi(m),gfromj(m),gtoi(m),gtoj(m));
                    board[gtoi(m)][gtoj(m)] = (board[gtoi(m)][gtoj(m)] & 0b10000000) | (n&0b00001111);
                }
                else{
                    shiftpiece(gfromi(m), gfromj(m), gtoi(m), gtoj(m));
                    board[gtoi(m)][gtoj(m)] = (board[gtoi(m)][gtoj(m)] & 0b10000000) | (q & 0b00001111);
                    std::cout<<"black promotion not made"<<std::endl;
                }
            }
            else if(checkenpassant(gtoi(m),gtoj(m))){      //enpassant
                shiftpiece(gfromi(m),gfromj(m),gtoi(m),gtoj(m));
                board[gfromi(m)][gtoj(m)] = 0b00000110;
                //std::cout<<"enpassant capture done : "<<gfromi(m)<<gfromj(m)<<"\t"<< gtoi(m)<<gtoj(m)<<std::endl;
            }
            else{
                shiftpiece(gfromi(m),gfromj(m),gtoi(m),gtoj(m));
            }
            return;

    }

    else if(piece(board[gfromi(m)][gfromj(m)])==k){
        //castle bqside
        if((gfromi(m)==7 && gfromj(m)==4) && (gtoi(m)==7 && gtoj(m)==2)){
                shiftpiece(7,4,7,2);
                shiftpiece(7,0,7,3);

                changeturn;
                return ;

        }
        //castle bkside
        if((gfromi(m)==7 && gfromj(m)==4) && (gtoi(m)==7 && gtoj(m)==6)){
                shiftpiece(7,4,7,6);
                shiftpiece(7,7,7,5);

                changeturn;
                return ;

        }
    }

    else if(piece(board[gfromi(m)][gfromj(m)])==K){
        //castle wqside
        if((gfromi(m)==0 && gfromj(m)==4) && (gtoi(m)==0 && gtoj(m)==2)){
                shiftpiece(0,4,0,2);
                shiftpiece(0,0,0,3);

                changeturn;
                return ;

        }
        //castle wkside
        if((gfromi(m)==0 && gfromj(m)==4) && (gtoi(m)==0 && gtoj(m)==6)){
                shiftpiece(0,4,0,6);
                shiftpiece(0,7,0,5);

                changeturn;
                return ;

        }
    }

    //default
    shiftpiece(gfromi(m),gfromj(m),gtoi(m),gtoj(m));
    return;


}
