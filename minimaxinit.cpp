#include<algorithm>

#include "def.h"
#include "boardstate.h"



const int MAX = 30000;
const int MIN = -30000;

extern unsigned int moves[10]{0};
extern unsigned int ogdepth{0};

unsigned int minimaxinit(int depth, boardstate brd, bool maximizingPlayer)
{
    unsigned int movetoreturn{0};

    int alpha {-30000};
    int beta {30000};
    if(depth == 0){
        depth = brd.depthguess();
    }
    ogdepth = depth;
    /*std::cout<<"\nminimax called\n";
    brd.makemove(m);                  //make makemove

    if (depth == 0){                     //how to check checkmate
                   //eval to be made
        //std::cout<<"minimax depth 0 reached\n";
        return brd.eval();
    }*/

    if (maximizingPlayer)
    {
        int best = MIN;

        unsigned int movelist[256]{0};   //maybe 128 works well
        brd.getmove(movelist);          //complete getmove
        std::sort(movelist, movelist + sizeof(movelist) / sizeof(movelist[0]),std::greater<int>());  //does sort work if null elements
        if(movelist[0] == 0 && brd.ischecked(1)){  //checkmate
            std::cout<<"# white checkmated\n";
            return 0;// BLACKWINS;

        }
        if(movelist[0] == 0){       //stalemate
            std::cout<<"# white stalemated\n";
            return 0;// STALEMATE;

        }

        for (unsigned int mo : movelist)
        {
            if(mo){          //check this again
                int val = minimax(depth - 1, brd, mo, false ,alpha, beta);
                //best = std::max(best, val);
                if(best<val){
                    best = val;
                    movetoreturn = mo;
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
        std::cout<<"\nbest value maximizing : "<<best<<std::endl;

    }
    else
    {
        int best = MAX;

        unsigned int movelist[256]{0};
        brd.getmove(movelist);
        std::sort(movelist, movelist + sizeof(movelist) / sizeof(movelist[0]),std::greater<int>());
        if(movelist[0] == 0 && brd.ischecked(0)){  //checkmate
            std::cout<<"# black checkmated\n";
            return 0;// WHITEWINS;

        }
        if(movelist[0] == 0){       //stalemate
            std::cout<<"# black stalemated\n";
            return 0;// STALEMATE;

        }

        for (unsigned int mo : movelist)
        {
            if(mo){
                int val = minimax(depth - 1, brd, mo, true, alpha, beta);
                //best = std::min(best, val);
                if(best>val){
                    best = val;
                    movetoreturn = mo;
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
        std::cout<<"\nbest value minimizing : "<<best<<std::endl;
    }
    return movetoreturn;
}
