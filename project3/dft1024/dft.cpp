#include "dft.h"
#include "coefficients1024.h"

void dft(DTYPE xx_R[SIZE], DTYPE xx_I[SIZE], DTYPE XX_R[SIZE], DTYPE XX_I[SIZE])
{
#pragma HLS DATAFLOW

  outer_for:
  for (iter_t i = 0; i < SIZE; ++i) {
#pragma HLS DATAFLOW

    DTYPE temp_R_out[SIZE];
#pragma HLS ARRAY_MAP variable=temp_R_out instance=temp_merged horizontal
    DTYPE temp_I_out[SIZE];
#pragma HLS ARRAY_MAP variable=temp_I_out instance=temp_merged horizontal

    DTYPE c[SIZE];
#pragma HLS ARRAY_MAP variable=c instance=cos_sin_merged horizontal
    DTYPE s[SIZE];
#pragma HLS ARRAY_MAP variable=s instance=cos_sin_merged horizontal

    DTYPE sumR[SIZE], sumI[SIZE];

    for1:
    for (iter_t j = 0; j < SIZE; ++j) {
#pragma HLS PIPELINE
#pragma HLS UNROLL skip_exit_check factor=8

      idx_t idx = (j * i) % SIZE;
      c[j] = cos_coefficients_table[idx];
      s[j] = sin_coefficients_table[idx];
    }

    for2:
    for (iter_t j = 0; j < SIZE; ++j) {
#pragma HLS PIPELINE
#pragma HLS UNROLL skip_exit_check factor=8

      DTYPE c_temp = c[j];
      DTYPE s_temp = s[j];
      DTYPE temp_R_in = xx_R[j];
      DTYPE temp_I_in = xx_I[j];
      temp_R_out[j] = (temp_R_in * c_temp - temp_I_in * s_temp);
      temp_I_out[j] = (temp_R_in * s_temp + temp_I_in * c_temp);
    }

    for3:
    for(iter_t k = 0; k < SIZE; ++k) {
#pragma HLS PIPELINE
#pragma HLS UNROLL skip_exit_check factor=8

      sumR[i] = (k == 0) ? temp_R_out[k] : (DTYPE)(sumR[i] + temp_R_out[k]);
      sumI[i] = (k == 0) ? temp_I_out[k] : (DTYPE)(sumI[i] + temp_I_out[k]);
    }
    XX_R[i] = sumR[i];
    XX_I[i] = sumI[i];
  }
}
