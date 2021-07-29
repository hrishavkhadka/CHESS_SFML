#include"def.h"

int weight(U1 piece) {
	switch (piece) {
	case empty:
		break;
	case p:
		return -100;
	case P:
		return 100;
	case n:
		return -300;
	case N:
		return 300;
	case b:
		return -320;
	case B:
		return 320;
	case r:
		return -500;
	case R:
		return 500;
	case q:
		return -900;
	case Q:
		return 900;
	case k:
		return -10000;
	case K:
		return 10000;
	default:
		std::cout << "weight failed" << std::endl;
		return 0;

	}
}