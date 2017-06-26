/*
This is traditional 2-radix DIT FFT algorithm implementation.
It is based on conventional 3-loop structure.
INPUT:
  In_R, In_I[]: Real and Imag parts of Complex signal

OUTPUT:
  In_R, In_I[]: Real and Imag parts of Complex signal
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fft.h"

#define reverse(n) ((n & 0x1) << 9) | ((n & 0x2) << 7) | ((n & 0x4) << 5) | ((n & 0x8) << 3) | ((n & 0x10) << 1) | ((n & 0x20) >> 1) | ((n & 0x40) >> 3) | ((n & 0x80) >> 5) | ((n & 0x100) >> 7) | ((n & 0x200) >> 9)


void fft(DTYPE x_R[SIZE], DTYPE x_I[SIZE], DTYPE X_R[SIZE], DTYPE X_I[SIZE])
{

  DTYPE temp_R;   /*temporary storage complex variable*/
  DTYPE temp_I;   /*temporary storage complex variable*/

  int i,j;      /* loop indexes */
  int i_lower;    /* Index of lower point in butterfly */
  int step;

  int stage;
  int DFTpts;
  int numBF;      /*Butterfly Width*/

  /*=====================BEGIN BIT REBERSAL===========================*/
  for (i = 0; i < SIZE; ++i) {
    X_R[reverse(i)] = x_R[i];
    X_I[reverse(i)] = x_I[i];
  }
  /*++++++++++++++++++++++END OF BIT REVERSAL++++++++++++++++++++++++++*/

  /*=======================BEGIN: FFT=========================*/
  // Do M stages of butterflies
  DTYPE c, s;

  stages:for(stage=1; stage<= M; stage++)
  {
    DFTpts = 1 << stage;    // DFT = 2^stage = points in sub DFT
    numBF = DFTpts >> 1;       // Butterfly WIDTHS in sub-DFT
    // Perform butterflies for j-th stage
    butterfly:for(j=0; j<numBF; j++)
    {
#pragma HLS LOOP_TRIPCOUNT max=512
      c = W_real[j * (SIZE>>stage)];
      s = W_imag[j * (SIZE>>stage)];

      // Compute butterflies that use same W**k
      DFTpts:for(i =j ; i < SIZE; i += DFTpts) {
#pragma HLS UNROLL factor=256
#pragma HLS LOOP_TRIPCOUNT max=512
        i_lower = i + numBF;      //index of lower point in butterfly
        temp_R = X_R[i_lower] * c - X_I[i_lower] * s;
        temp_I = X_I[i_lower] * c + X_R[i_lower] * s;

        X_R[i_lower] = X_R[i] - temp_R;
        X_I[i_lower] = X_I[i] - temp_I;
        X_R[i] = X_R[i] + temp_R;
        X_I[i] = X_I[i] + temp_I;
      }
    }
  }
}
/*=======================END: FFT=========================*/
