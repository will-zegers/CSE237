/*
	Filename: fir.cpp
		FIR lab wirtten for WES/CSE237C class at UCSD.
		Match filter
	INPUT:
		x: signal (chirp)

	OUTPUT:
		y: filtered output

*/

#include "fir.h"
void fir (
  data_t *y,
  data_t x
  ) {

	coef_t c[N] = {10, 11, 11, 8, 3, -3, -8, -11, -11, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -11, -11, -8, -3, 3, 8, 11, 11, 10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 8, 3, -3, -8, -11, -11, -10, -10, -10, -10, -10, -10, -10, -10, -11, -11, -8, -3, 3, 8, 11, 11, 10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 8, 3, -3, -8, -11, -11, -10, -10, -10, -10, -10, -10, -10, -10, -11, -11, -8, -3, 3, 8, 11, 11, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
#pragma HLS RESOURCE variable=c core=ROM_2P_BRAM
#pragma HLS ARRAY_PARTITION variable=c cyclic factor=8 dim=1
	
	// Write your code here
	static data_t shift_reg[N];
#pragma HLS RESOURCE variable=shift_reg core=RAM_2P_BRAM
#pragma HLS ARRAY_PARTITION variable=shift_reg cyclic factor=16 dim=1
	acc_t acc;
	data_t data;
	int i;

	acc = 0;

	TDL:
	for (i = N-1; i > 0; i--) {
#pragma HLS UNROLL factor=16
#pragma HLS PIPELINE II=1
		shift_reg[i] = shift_reg[i-1];
	}
	shift_reg[0] = x;

	MAC:
	for (i = N-1; i > 0; i--) {
#pragma HLS DEPENDENCE variable=acc inter false
#pragma HLS UNROLL factor=16
#pragma HLS PIPELINE II=1
		acc += shift_reg[i] * c[i];
	}
	acc += x * c[0];

	*y = acc;
}


