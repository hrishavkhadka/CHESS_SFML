#include "eval.h"
#include "def.h"
#include "boardstate.h"



U1 boardstate::diff(unsigned int m){
    U1 fpc = piece(board[gfromi(m)][gfromj(m)]);
    U1 tpc = piece(board[gtoi(m)][gtoj(m)]);
    int fpcscore1,fpcscore2,tpcscore{0};

    if(fpc>empty){
        fpcscore1= mg_table_white[fpc-7][gfromi(m)][gfromj(m)];
        if (fpcscore1 > 2000) { fpcscore1 = 0; }
        fpcscore2= mg_table_white[fpc-7][gtoi(m)][gtoj(m)];
        if(tpc!=empty){
            tpcscore= mg_table_black[tpc][gtoi(m)][gtoj(m)];
        }
        else{
            tpcscore=fpcscore1;
        }
    }
    else{
        fpcscore1= mg_table_black[fpc][gfromi(m)][gfromj(m)];
        if (fpcscore1 > 2000) { fpcscore1 = 0; }
        fpcscore2= mg_table_black[fpc][gtoi(m)][gtoj(m)];
        if(tpc!=empty){
            tpcscore= mg_table_white[tpc-7][gtoi(m)][gtoj(m)];
        }
        else{
            tpcscore=fpcscore1;
        }
    }
    int score = ( tpcscore + fpcscore2-(fpcscore1*2) )/50  ;
    //std::cout<<"score:  "<<score<<"\ttpc : "<<tpcscore<<"\tfpc1 : "<<fpcscore1<<"\tfpc2 : "<<fpcscore2<<std::endl;
    if(score>15){
        return 15;
    }
    else if(score<0){
        return 0;
    }
    else{
        return score;
    }

}

