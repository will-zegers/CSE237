#include<ap_int.h>
#include<ap_fixed.h>

typedef float DTYPE;
typedef int   idx_t;

#define SIZE 256 		/* SIZE OF DFT */
void dft(DTYPE xx_R[SIZE], DTYPE xx_I[SIZE], DTYPE XX_R[SIZE], DTYPE XX_I[SIZE]);

