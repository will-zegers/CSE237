/*
The bit_reverse part of FFT.
INPUT:
	In[]:

OUTPUT:
	Out[]:
 */

#include "bit_reverse.h"
#include <stdio.h>

#define reverse(idx) ((idx & 0x001) << 9) | ((idx & 0x002) << 7) | ((idx & 0x004) << 5) | ((idx & 0x008) << 3) | ((idx & 0x010) << 1) | ((idx & 0x0020) >> 1) | ((idx & 0x040) >> 3) | ((idx & 0x080) >> 5) | ((idx & 0x100) >> 7) | ((idx & 0x200) >> 9)

void bit_reverse(DTYPE xx_R[SIZE], DTYPE xx_I[SIZE], DTYPE XX_R[SIZE], DTYPE XX_I[SIZE]){

	for (int i = 0; i < SIZE; ++i) {
#pragma HLS UNROLL skip_exit_check factor=2
#pragma HLS PIPELINE

		XX_R[i] = xx_R[reversed[i]];
		XX_I[i] = xx_I[reversed[i]];
	}
}
