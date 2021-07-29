
#include<algorithm>

#include "def.h"
#include "boardstate.h"

const int MAX = 30000;
const int MIN = -30000;

extern unsigned int moves[10];
extern unsigned int ogdepth;

int minimax(int depth, boardstate brd, unsigned int m, bool maximizingPlayer , int alpha, int beta)
{
    //std::cout<<"\nminimax called\n";
    brd.makemove(m);                  //make makemove

    if (depth == 0){                     //how to check checkmate
                   //eval to be made

        //std::cout<<"minimax depth 0 reached\n";
        return brd.eval();
    }

    if (maximizingPlayer)
    {
        int best = MIN;

        unsigned int movelist[256]{0};   //maybe 128 works well
        brd.getmove(movelist);          //complete getmove
        std::sort(movelist, movelist + sizeof(movelist) / sizeof(movelist[0]),std::greater<int>());  //does sort work if null elements
        if(movelist[0] == 0 && brd.ischecked(1)){  //checkmate

            return -(20500+depth);

        }
        if(movelist[0] == 0){       //stalemate

            return 0;

        }

        for (unsigned int mo : movelist)
        {
            if(mo){
                int val = minimax(depth - 1, brd, mo, false ,alpha, beta);

                if(best<val){
                    best = val;

                }
                alpha = std::max(alpha, best);

                if (beta <= alpha){

                    break;
                }
            }
            else{
                break;
            }
        }
        return best;
    }
    else
    {
        int best = MAX;

        unsigned int movelist[256]{0};
        brd.getmove(movelist);
        std::sort(movelist, movelist + sizeof(movelist) / sizeof(movelist[0]),std::greater<int>());
        if(movelist[0] == 0 && brd.ischecked(0)){  //checkmate

            return (20500+depth);

        }
        if(movelist[0] == 0){       //stalemate
 
            return 0;

        }

        for (unsigned int mo : movelist)
        {
            if(mo){
                int val = minimax(depth - 1, brd, mo, true, alpha, beta);

                if(best>val){
                    best = val;
                   
                }
                beta = std::min(beta, best);

                if (beta <= alpha){

                    break;
                }
            }
            else{
                break;
            }
        }
        return best;
    }
}

