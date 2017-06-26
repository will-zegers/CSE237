#include "fft.h"

void qpsk_decode(DTYPE R[SIZE], DTYPE I[SIZE], int D[SIZE]) {

	for (int i = 0; i < SIZE; ++i) {
		D[i] = (R[i] >= 0) ? ((I[i] >= 0) ? 0 : 2) : (I[i] >= 0) ? 1 : 3;
	}
}
