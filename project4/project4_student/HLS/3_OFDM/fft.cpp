/*
 This is traditional 2-radix DIT FFT algorithm implementation.
 INPUT:
 In_R, In_I[]: Real and Imag parts of Complex signal

 OUTPUT:
 Out_R, Out_I[]: Real and Imag parts of Complex signal
 */

#include "fft.h"

#define reverse(idx) ((idx & 0x001) << 9) | ((idx & 0x002) << 7) | ((idx & 0x004) << 5) | ((idx & 0x008) << 3) | ((idx & 0x010) << 1) | ((idx & 0x0020) >> 1) | ((idx & 0x040) >> 3) | ((idx & 0x080) >> 5) | ((idx & 0x100) >> 7) | ((idx & 0x200) >> 9)

void bit_reverse(DTYPE xx_R[SIZE], DTYPE xx_I[SIZE], DTYPE XX_R[SIZE], DTYPE XX_I[SIZE]);
void fft_stages(DTYPE X_R[SIZE], DTYPE X_I[SIZE], int STAGES, DTYPE OUT_R[SIZE],
		DTYPE OUT_I[SIZE]);
void qpsk_decode(DTYPE R[SIZE], DTYPE I[SIZE], int D[SIZE]);

void demod(DTYPE X_R[SIZE], DTYPE X_I[SIZE], int D[SIZE], DTYPE OUT_R[SIZE], DTYPE OUT_I[SIZE])
{
#pragma HLS PIPELINE
	fft(X_R, X_I, OUT_R, OUT_I);
	qpsk_decode(OUT_R, OUT_I, D);
}

void fft(DTYPE X_R[SIZE], DTYPE X_I[SIZE], DTYPE OUT_R[SIZE], DTYPE OUT_I[SIZE]) {
#pragma HLS DATAFLOW
	//Call fft
	DTYPE Stage0_R[SIZE], Stage0_I[SIZE];
	DTYPE Stage1_R[SIZE], Stage1_I[SIZE];
	DTYPE Stage2_R[SIZE], Stage2_I[SIZE];
	DTYPE Stage3_R[SIZE], Stage3_I[SIZE];
	DTYPE Stage4_R[SIZE], Stage4_I[SIZE];
	DTYPE Stage5_R[SIZE], Stage5_I[SIZE];
	DTYPE Stage6_R[SIZE], Stage6_I[SIZE];
	DTYPE Stage7_R[SIZE], Stage7_I[SIZE];
	DTYPE Stage8_R[SIZE], Stage8_I[SIZE];
	DTYPE Stage9_R[SIZE], Stage9_I[SIZE];
	DTYPE Stage10_R[SIZE], Stage10_I[SIZE];


#pragma HLS ARRAY_MAP variable=Stage0_R instance=merged_stage_0 horizontal
#pragma HLS ARRAY_MAP variable=Stage0_I instance=merged_stage_0 horizontal
#pragma HLS ARRAY_MAP variable=Stage1_R instance=merged_stage_1 horizontal
#pragma HLS ARRAY_MAP variable=Stage1_I instance=merged_stage_1 horizontal
#pragma HLS ARRAY_MAP variable=Stage2_R instance=merged_stage_2 horizontal
#pragma HLS ARRAY_MAP variable=Stage2_I instance=merged_stage_2 horizontal
#pragma HLS ARRAY_MAP variable=Stage3_R instance=merged_stage_3 horizontal
#pragma HLS ARRAY_MAP variable=Stage3_I instance=merged_stage_3 horizontal
#pragma HLS ARRAY_MAP variable=Stage4_R instance=merged_stage_4 horizontal
#pragma HLS ARRAY_MAP variable=Stage4_I instance=merged_stage_4 horizontal
#pragma HLS ARRAY_MAP variable=Stage5_R instance=merged_stage_5 horizontal
#pragma HLS ARRAY_MAP variable=Stage5_I instance=merged_stage_5 horizontal
#pragma HLS ARRAY_MAP variable=Stage6_R instance=merged_stage_6 horizontal
#pragma HLS ARRAY_MAP variable=Stage6_I instance=merged_stage_6 horizontal
#pragma HLS ARRAY_MAP variable=Stage7_R instance=merged_stage_7 horizontal
#pragma HLS ARRAY_MAP variable=Stage7_I instance=merged_stage_7 horizontal
#pragma HLS ARRAY_MAP variable=Stage8_R instance=merged_stage_8 horizontal
#pragma HLS ARRAY_MAP variable=Stage8_I instance=merged_stage_8 horizontal
#pragma HLS ARRAY_MAP variable=Stage9_R instance=merged_stage_9 horizontal
#pragma HLS ARRAY_MAP variable=Stage9_I instance=merged_stage_9 horizontal
#pragma HLS ARRAY_MAP variable=Stage10_R instance=merged_stage_9 horizontal
#pragma HLS ARRAY_MAP variable=Stage10_I instance=merged_stage_9 horizontal


	bit_reverse(X_R, X_I, Stage0_R, Stage0_I);

	fft_stages(Stage0_R, Stage0_I, 1, Stage1_R, Stage1_I);
	fft_stages(Stage1_R, Stage1_I, 2, Stage2_R, Stage2_I);
	fft_stages(Stage2_R, Stage2_I, 3, Stage3_R, Stage3_I);
	fft_stages(Stage3_R, Stage3_I, 4, Stage4_R, Stage4_I);
	fft_stages(Stage4_R, Stage4_I, 5, Stage5_R, Stage5_I);
	fft_stages(Stage5_R, Stage5_I, 6, Stage6_R, Stage6_I);
	fft_stages(Stage6_R, Stage6_I, 7, Stage7_R, Stage7_I);
	fft_stages(Stage7_R, Stage7_I, 8, Stage8_R, Stage8_I);
	fft_stages(Stage8_R, Stage8_I, 9, Stage9_R, Stage9_I);
	fft_stages(Stage9_R, Stage9_I, 10, Stage10_R, Stage10_I);

	bit_reverse(Stage10_R, Stage10_I, OUT_R, OUT_I);
}

void bit_reverse(DTYPE xx_R[SIZE], DTYPE xx_I[SIZE], DTYPE XX_R[SIZE], DTYPE XX_I[SIZE]){

	for (int i = 0; i < SIZE; ++i) {
#pragma HLS PIPELINE
		XX_R[i] = xx_R[reverse(i)];
		XX_I[i] = xx_I[reverse(i)];
	}
}

//stages
void fft_stages(DTYPE X_R[SIZE], DTYPE X_I[SIZE], int STAGES, DTYPE OUT_R[SIZE], DTYPE OUT_I[SIZE]) {

	INTTYPE i, j;
	INTTYPE i_lower;
	INTTYPE theta;
	DTYPE temp_R, temp_I;
	DTYPE c, s;

	const INTTYPE DFTPTS = (1 << STAGES);
	const INTTYPE UBOUND = SIZE - DFTPTS;
	const INTTYPE PHASE  = (SIZE >> STAGES);

	for (theta = 0, i = 0, j = 0; j < SIZE2; j++) {
#pragma HLS PIPELINE

		c = W_real[theta];
		s = W_imag[theta];
		i_lower = i + (DFTPTS >> 1);

		temp_R = X_R[i_lower] * c - X_I[i_lower] * s;
		temp_I = X_I[i_lower] * c + X_R[i_lower] * s;

		OUT_R[i_lower] = X_R[i] - temp_R;
		OUT_I[i_lower] = X_I[i] - temp_I;

		OUT_R[i] = X_R[i] + temp_R;
		OUT_I[i] = X_I[i] + temp_I;

		theta = ((j+1) == theta + PHASE) ? theta + PHASE : theta;
		i = (i >= UBOUND) ? i - (UBOUND - 1) : i + DFTPTS ;
	}
}
/*=======================END: FFT=========================*/
