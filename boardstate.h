#ifndef BOARDSTATE_H
#define BOARDSTATE_H
#include "def.h"


class boardstate
{
private:

	U1 board[8][8];
	U1 enpas;


public:
    boardstate(){
        for (int i=7; i >=0; i--) {
            for (int j=0; j < 8; j++) {
                board[i][j] = empty;
            }
        }
        enpas = 64;
    }

	U1 getsquare(int i, int j) { return board[i][j]; }
	void setsquare(int i, int j, U1 pc) { board[i][j] = pc; }

    void translatefen(std::string);

    void printboard();
    void printboardinbits();

    bool getturn(){return gturn;}
	void getmove(unsigned int[256]);
	void makemove(unsigned int);
	void unmakemove(unsigned int);
	void shiftpiece(int,int,int,int);

	int eval();
	U1 diff(unsigned int);
	int depthguess();

	bool isattacked(int,int,bool);
	bool ischecked(bool);
	static bool ischeckedaftermove(boardstate,unsigned int,bool);

	void getarray(U1 arr[8][8]);

};

#endif
