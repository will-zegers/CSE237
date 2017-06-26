#ifndef BITREVERSE_H
#define BITREVERSE_H

#include <ap_fixed.h>

typedef float DTYPE;
typedef int INTTYPE;

#define SIZE 1024 		/* SIZE OF FFT */
#define SIZE2 SIZE>>1	/* SIZE OF FFT/2 */
#define M 10			/* Number of Stages = Log2N */


void bit_reverse(DTYPE xx_R[SIZE], DTYPE xx_I[SIZE], DTYPE XX_R[SIZE], DTYPE XX_I[SIZE]);

#endif
