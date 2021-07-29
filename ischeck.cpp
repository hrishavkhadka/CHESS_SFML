#include "boardstate.h"

bool boardstate::ischecked(bool player){
    int adjust{0};
    if(!player){
        adjust = 7;
    }

    for (int i{0};i<8;i++){
        for(int j{0};j<8;j++){
            if(piece(board[i][j])==(K-adjust)){
                //std::cout << "king is at : "<<i<<j;
                if(isattacked(i,j,player)){
                    return true;
                }
                else{
                    return false;
                }
            }
        }
    }
    return false;
}
