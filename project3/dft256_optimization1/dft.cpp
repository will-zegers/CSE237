#include<math.h>
#include "dft.h"
#include "coefficients256.h"

void dft(DTYPE real_sample_in[SIZE], DTYPE imag_sample_in[SIZE])
{
	DTYPE w, c, s;
	idx_t idx;

	DTYPE real_temp[SIZE] = {0};
	DTYPE imag_temp[SIZE] = {0};

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			idx = (j * i) % SIZE;
			c = cos_coefficients_table[idx];
			s = sin_coefficients_table[idx];

			real_temp[i] += (real_sample_in[j] * c - imag_sample_in[j] * s);
			imag_temp[i] += (real_sample_in[j] * s + imag_sample_in[j] * c);
		}
	}

	for (int i = 0; i < SIZE; i++) {
		real_sample_in[i] = real_temp[i];
		imag_sample_in[i] = imag_temp[i];
	}
}
