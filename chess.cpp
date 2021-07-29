#include<bitset>
#include "def.h"
#include "boardstate.h"

/*static int nodecounttest{0};
int mima(boardstate brd,int depth,unsigned int m){
    if(depth == 0){
        nodecounttest++;
        //std::cout<<"turn:"<< brd.getturn() <<std::endl;
    }
    else{
        brd.makemove(m);
        //if(depth == 1){brd.printboard();}
        unsigned int movelist[256]{0};
        brd.getmove(movelist);
        for(unsigned int mo:movelist){
            /*if(depth == 2 && mo != 0){
                std::cout << "\n\n\n\n move:\t"<<gfromi(mo)<<gfromj(mo)<<"\t"<<gtoi(mo)<<gtoj(mo)<<std::endl<<std::endl;
            }
            if(depth == 1 && mo != 0){
                std::cout << "move:\t"<<gfromi(mo)<<gfromj(mo)<<"\t"<<gtoi(mo)<<gtoj(mo)<<std::endl;
            }

            if(mo != 0){
                mima(brd,depth-1,mo);
            }
        }
    }
    return 0;
}*/
extern unsigned int moves[10];

int chess() {

    boardstate brd;
    brd.translatefen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");

    brd.printboard();

    displaychess(&brd);

    unsigned int mov=minimaxinit(0,brd,brd.getturn());

    std::cout<<"\n\nmove :  "<<gfromi(mov)<<gfromj(mov)<<"\t"<<gtoi(mov)<<gtoj(mov)<<std::endl;



    std::cout<<"\nstart print moves"<<std::endl;
    for(int i=0;i<10;i++){
        std::cout<< std::bitset<16>(moves[i]) << "\t" << moves[i]<<"\t"<<gfromi(moves[i])<<gfromj(moves[i])<<"\t"<<gtoi(moves[i])<<gtoj(moves[i]) <<std::endl;

    }
    std::cout<<"end print moves"<<std::endl;



	return 0;
}
