#include <ap_int.h>
#include <ap_fixed.h>
#include <stdint.h>

typedef float DTYPE;
typedef uint16_t idx_t;
typedef uint16_t iter_t;

#define SIZE 256 		/* SIZE OF DFT */
void dft(DTYPE xx_R[SIZE], DTYPE xx_I[SIZE], DTYPE XX_R[SIZE], DTYPE XX_I[SIZE]);

