#include <ap_int.h>
#include <ap_fixed.h>
#include <stdint.h>
#include <hls_stream.h>

typedef float DTYPE;
typedef uint16_t idx_t;
typedef uint16_t iter_t;

#define SIZE 256 		/* SIZE OF DFT */
void dft(hls::stream<DTYPE> xx_R[SIZE], hls::stream<DTYPE> xx_I[SIZE], hls::stream<DTYPE> XX_R[SIZE], hls::stream<DTYPE> XX_I[SIZE]);
