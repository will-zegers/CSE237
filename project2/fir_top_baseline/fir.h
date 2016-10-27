/*
	Filename: fir.h
		Header file
		FIR lab wirtten for 237C class at UCSD.

*/
#ifndef FIR_H_
#define FIR_H_

#include <ap_fixed.h>
#include <stdint.h>

const uint8_t N = 32;

typedef ap_int<2>      coef_t;
typedef ap_fixed<19,7> data_t;
typedef ap_fixed<19,7> acc_t;
typedef ap_uint<6>     iter_t;


void fir (
  data_t I,
  data_t Q,

  data_t *X,
  data_t *Y
  );



#endif
