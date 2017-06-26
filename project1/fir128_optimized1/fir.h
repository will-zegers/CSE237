/*
	Filename: fir.h
		Header file
		FIR lab wirtten for WES/CSE237C class at UCSD.

*/
#ifndef FIR_H_
#define FIR_H_

#include "ap_int.h"
const int N=128;
#ifdef BIT_ACCURATE
typedef ap_int<32>	coef_t;
typedef ap_int<32>	data_t;
typedef ap_int<32>	acc_t;
#else
typedef int	coef_t;
typedef int	data_t;
typedef int	acc_t;
#endif

void fir (
  data_t *y,
  data_t x
  );

#endif
