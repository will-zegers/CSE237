/*
	Filename: fir.cpp
		FIR lab wirtten for WES/CSE237C class at UCSD.

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
	coef_t c[N] = {53, 0, -91, 0, 313, 500, 313, 0, -91, 0,53};
	// Write your code here
	static data_t shift_reg[N];
	acc_t acc;
	data_t data;
	int i;

	acc = 0;
	for (i = N-1; i >= 0; i--) {
		if (i == 0) {
			shift_reg[0] = x;
			data = x;
		} else {
			shift_reg[i] = shift_reg[i-1];
			data = shift_reg[i];
		}
		acc += data * c[i];
	}
	*y = acc;
}


