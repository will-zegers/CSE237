#include "dft.h"
#include "coefficients256.h"

void dft(DTYPE xx_R[SIZE], DTYPE xx_I[SIZE], DTYPE XX_R[SIZE], DTYPE XX_I[SIZE])
{

	DTYPE temp_R, temp_I;
	DTYPE c, s;
	idx_t idx;

	for (int i = 0; i < SIZE; ++i) {
		temp_R = 0;
		temp_I = 0;

	for (int j = 0; j < SIZE; j++) {
			idx = (j * i) % SIZE;
			c = cos_coefficients_table[idx];
			s = sin_coefficients_table[idx];

			temp_R += (xx_R[j] * c - xx_I[j] * s);
			temp_I += (xx_R[j] * s + xx_I[j] * c);
		}
		XX_R[i] = temp_R;
		XX_I[i] = temp_I;
	}
}
