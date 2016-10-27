#ifndef CORDICCART2POL_H
#define CORDICCART2POL_H

#include <ap_int.h>
#include <ap_fixed.h>

#define NO_ITER 16

typedef ap_fixed<19,3> data_t;
typedef ap_uint<6> iter_t;

void cordiccart2pol(data_t x, data_t y, data_t * r,  data_t * theta);

#endif
