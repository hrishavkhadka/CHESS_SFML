#ifndef DEF_H
#define DEF_H

#include <stdint.h>
#include <iostream>

#define BLACKWINS 32001
#define WHITEWINS 32000
#define STALEMATE 31999
//board square info.......set on a uint8_t data bits(8)
#define piece(x) (x & 0b00001111)
//#define spiece(i,j) (board[i][j])
#define castle(x) ((x & 0b00010000)>>4)
#define oncastle(x) (x= x | 0b00010000)
#define togglecastle(x) (x ^ 0b00010000)
#define offcastle(x) (x = (x | 0b11101111))

#define checkenpassant(i,j) ((((i<<3)|j)==enpas)?true:false)
#define setenpassant(i,j) (enpas =((enpas&0)|((i<<3)|(j))))
#define resetenpassant (enpas=0)
//player turn
#define gturn (((board[0][0]>>7)&1)?1:0)
#define sturn(x) (board[0][0] = (board[0][0] & 0b01111111) | (x << 7))
#define changeturn (board[0][0]=board[0][0]^0b10000000)
//move get info......set on a unsigned short data bits(16)
#define gfromj(x) (x & 0b0000000000000111)
#define gfromi(x) ((x & 0b0000000000111000)>>3)
#define gtoj(x) ((x & 0b0000000111000000)>>6)
#define gtoi(x) ((x & 0b0000111000000000)>>9)
#define gpromq(x) ((x & 0b0001000000000000)>>12)
#define gpromr(x) ((x & 0b0010000000000000)>>13)
#define gpromb(x) ((x & 0b0100000000000000)>>14)
#define gpromn(x) ((x & 0b1000000000000000)>>15)
#define gscore(x) ((x & 0b11110000000000000000)>>16)
//move set info
#define sfromj(move,x) (move = (move | x))
#define sfromi(move,x) (move = (move | (x<<3)))
#define stoj(move,x) (move = (move | (x<<6)))
#define stoi(move,x) (move = (move | (x<<9)))

#define sscore(move,x) (move = (move | (x<<12)))//; std::cout<< (gfromi(move))<< (gfromj(move))<<"\t"<< (gtoi(move))<< (gtoj(move)) <<std::endl; std::cout<< (ischeckedaftermove(*this,tempmove,0)?"att":"not atkd")
#define setmove(move,fi,fj,ti,tj,pq,pr,pb,pn,sc) (move=((((((((((move | (fj)) | (fi<<3)) | (tj<<6)) | (ti<<9)) | (pq<<12)) | (pr<<13)) | (pb<<14)) | (pn<<15)) | (sc<<16))))

typedef unsigned long long  U64;
typedef unsigned short U2;
typedef uint8_t U1;
typedef int8_t S1;

enum {BLACK,WHITE};
enum {p,n,b,r,q,k,empty,P,N,B,R,Q,K};

class boardstate;

int minimax(int depth, boardstate brd, unsigned int m, bool maximizingPlayer, int alpha, int beta);
unsigned int minimaxinit(int depth, boardstate brd, bool maximizingPlayer );
int chess();
int displaychess(boardstate* brd);

#endif
