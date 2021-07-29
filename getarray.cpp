#include "def.h"
#include "boardstate.h"

void boardstate::getarray(U1 arr[8][8]) {
	for (int i{ 0 }; i < 8; i++) {
		for (int j{ 0 }; j < 8; j++) {
			arr[i][j] = board[i][j];
		}
	}
}