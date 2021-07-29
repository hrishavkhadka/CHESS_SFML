#include "def.h"
#include "boardstate.h"

const int piecetimeestimate[6] {2,5,10,10,15,0};

int boardstate::depthguess(){

    int totaltimevalue{0};

    for(int ii{0};ii<8;ii++){
        for(int jj{0};jj<8;jj++){
            if(piece(board[ii][jj]) == empty){
                continue;
            }
            else if(piece(board[ii][jj])>empty){
                totaltimevalue += piecetimeestimate[(piece(board[ii][jj]) - 7 )];
            }
            else{
                totaltimevalue += piecetimeestimate[piece(board[ii][jj])];
            }
        }
    }
    if(totaltimevalue<=6){
        return 10;
    }
    if(totaltimevalue <=10){
        return 9;
    }
    else if(totaltimevalue < 20){
        return 8;
    }
    else if(totaltimevalue < 80){
        return 7;
    }
    else {
        return 6;
    }
}
