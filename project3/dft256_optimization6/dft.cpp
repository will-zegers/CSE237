#include "dft.h"
#include "coefficients256.h"

void dft(DTYPE xx_R[SIZE], DTYPE xx_I[SIZE], DTYPE XX_R[SIZE], DTYPE XX_I[SIZE])
{
	for (int i = 0; i < SIZE; ++i) {
#pragma HLS DATAFLOW
		DTYPE temp_R_out[SIZE], temp_I_out[SIZE];
		DTYPE sumR[SIZE], sumI[SIZE];
		DTYPE c[SIZE], s[SIZE];

		for1:
		for (int j = 0; j < SIZE; ++j) {
			idx_t idx = (j * i) % SIZE;
			c[j] = cos_coefficients_table[idx];
			s[j] = sin_coefficients_table[idx];
		}

		for2:
		for (int j = 0; j < SIZE; ++j) {
			DTYPE c_temp = c[j];
			DTYPE s_temp = s[j];
			DTYPE temp_R_in = xx_R[j];
			DTYPE temp_I_in = xx_I[j];
			temp_R_out[j] = (temp_R_in * c_temp - temp_I_in * s_temp);
			temp_I_out[j] = (temp_R_in * s_temp + temp_I_in * c_temp);
		}

		for3:
		for(int k = 0; k < SIZE; ++k) {
			sumR[i] = (k == 0) ? temp_R_out[k] : sumR[i] + temp_R_out[k];
			sumI[i] = (k == 0) ? temp_I_out[k] : sumI[i] + temp_I_out[k];
		}

		XX_R[i] = sumR[i];
		XX_I[i] = sumI[i];
	}
}
