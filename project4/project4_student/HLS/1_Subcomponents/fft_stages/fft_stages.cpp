#include"fft_stages.h"
#include <stdio.h>
/*
* Function: fft_stage_first_op calculates the first stage of the FFT.
*
INPUT:
In_R, In_I[]: Real and Imag parts of Complex signal

OUTPUT:
OUT_R, OUT_I[]: Real and Imag parts of Complex signal
*/

//=======================BEGIN: FFT fft_stage_first_op =========================
void fft_stages(DTYPE X_R[SIZE], DTYPE X_I[SIZE], int STAGES, DTYPE OUT_R[SIZE], DTYPE OUT_I[SIZE]) {

	INTTYPE i, j;
	INTTYPE i_lower;
	DTYPE temp_R, temp_I;
	DTYPE c, s;

	const INTTYPE DFTPTS = 1 << STAGES;
	const INTTYPE NUMBF = DFTPTS >> 1;

	for(j=0; j < NUMBF; j++) {
		c = W_real[j * (SIZE >> STAGES)];
		s = W_imag[j * (SIZE >> STAGES)];

		DFTpts:for(i = j ; i < SIZE; i += DFTPTS) {
			i_lower = i + NUMBF;      //index of lower point in butterfly
			temp_R = X_R[i_lower] * c - X_I[i_lower] * s;
			temp_I = X_I[i_lower] * c + X_R[i_lower] * s;

			OUT_R[i_lower] = X_R[i] - temp_R;
			OUT_I[i_lower] = X_I[i] - temp_I;
			OUT_R[i] = X_R[i] + temp_R;
			OUT_I[i] = X_I[i] + temp_I;
		}
	}
}
//=======================END: FFT fft_stage_first_op =========================

