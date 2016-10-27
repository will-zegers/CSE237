/*
	Filename: fir.h
		Header file
		FIR lab wirtten for 237C class at UCSD.

*/
#ifndef PHASE_DETECTOR_H_
#define PHASE_DETECTOR_H_

#include <ap_fixed.h>
#include <stdint.h>

const uint8_t N = 32;

#define NO_ITER 16

typedef ap_int<2>      coef_t;
typedef ap_fixed<20,8> data_t;
typedef ap_fixed<20,7> acc_t;
typedef ap_uint<6>     iter_t;

void phasedetector (
  data_t I,
  data_t Q,

  data_t *R,
  data_t *theta
  );

void cordiccart2pol(data_t x, data_t y, data_t * r, data_t * theta);

void fir (
  data_t I,
  data_t Q,

  data_t *X,
  data_t *Y
  );

#endif
