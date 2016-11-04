#include<math.h>
#include "dft.h"
#include "coefficients256.h"

#define N 256

void dft(DTYPE real_sample[SIZE], DTYPE imag_sample[SIZE])
{
	DTYPE w, c, s;
	idx_t idx;

	DTYPE real_temp[N] = {0};
	DTYPE imag_temp[N] = {0};

	for (int i = 0; i < N; i++) {
		w = 2 * M_PI * i / N;
		for (int j = 0; j < N; j++) {
			c = cos(j * w);
			s = -sin(j * w);

			real_temp[i] += (real_sample[j] * c - imag_sample[j] * s);
			imag_temp[i] += (real_sample[j] * s + imag_sample[j] * c);
		}
	}

	for (int i = 0; i < N; i++) {
		real_sample[i] = real_temp[i];
		imag_sample[i] = imag_temp[i];
	}
}
