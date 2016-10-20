/*
	Filename: fir.cpp
		Complex FIR or Match filter
		firI1 and firI2 share coef_t c[N]
		firQ1 and firQ2 share coef_t c[N]
		
	INPUT:
		I: signal for I sample
		I: signal for Q sample

	OUTPUT:
		X: filtered output
		Y: filtered output

*/

#include "fir.h"

void fir_base(
	coef_t c[],
	data_t *shift_reg,
	data_t *y,
	data_t x
	) {

	acc_t acc;
	acc = 0;

	MAC_AND_TDL:
	for (iter_t i = N-1; i > 0; i--) {
#pragma HLS UNROLL skip_exit_check
		shift_reg[i] = shift_reg[i-1];
		acc = (c[i] == 1) ? acc + shift_reg[i] : acc - shift_reg[i];
	}
	shift_reg[0] = x;
	acc = (c[0] == 1) ? acc + x : acc - x;

	*y = acc;
}

void Ifir_base (
	data_t *shift_reg,
	data_t *y,
	data_t x
	) {

	coef_t c[N] = {1,    -1,    1,    -1,    -1,    -1,    1,    1,    -1,    -1,    -1,    1,    1,    -1,    1,    -1,    -1,    -1,    -1,    1,    1,    1,    1,    1,    -1,    -1,    1,    1,    1,    -1,    -1,    -1};
#pragma HLS RESOURCE variable=c core=ROM_2P
#pragma HLS ARRAY_PARTITION variable=c cyclic factor=4 dim=1

	fir_base(c, shift_reg, y, x);
}

void Qfir_base (
	data_t *shift_reg,
	data_t *y,
	data_t x
	) {

	coef_t c[N] = {-1,    -1,    1,    -1,    1,    -1,    1,    -1,    -1,    -1,    -1,    1,    -1,    1,    -1,    1,    1,    -1,    1,    -1,    -1,    1,    -1,    1,    1,    1,    1,    -1,    1,    -1,    1,    1};
#pragma HLS ARRAY_PARTITION variable=c cyclic factor=4 dim=1
#pragma HLS RESOURCE variable=c core=ROM_2P

	fir_base(c, shift_reg, y, x);
}

void firI1 (
  data_t *y,
  data_t x
  ) {
#pragma HLS INLINE recursive

	static data_t shift_reg[N];
#pragma HLS ARRAY_PARTITION variable=shift_reg cyclic factor=4 dim=1
#pragma HLS RESOURCE variable=shift_reg core=RAM_T2P_BRAM

	Ifir_base(shift_reg, y, x);
}

void firI2 (
  data_t *y,
  data_t x
  ) {
#pragma HLS INLINE recursive

	static data_t shift_reg[N];
#pragma HLS ARRAY_PARTITION variable=shift_reg cyclic factor=4 dim=1
#pragma HLS RESOURCE variable=shift_reg core=RAM_T2P_BRAM

	Ifir_base(shift_reg, y, x);
}

void firQ1 (
  data_t *y,
  data_t x
  ) {
#pragma HLS INLINE recursive

	static data_t shift_reg[N];
#pragma HLS ARRAY_PARTITION variable=shift_reg cyclic factor=4 dim=1
#pragma HLS RESOURCE variable=shift_reg core=RAM_T2P_BRAM

	Qfir_base(shift_reg, y, x);
}

void firQ2 (
  data_t *y,
  data_t x
  ) {
#pragma HLS INLINE recursive

	static data_t shift_reg[N];
#pragma HLS ARRAY_PARTITION variable=shift_reg cyclic factor=4 dim=1
#pragma HLS RESOURCE variable=shift_reg core=RAM_T2P_BRAM

	Qfir_base(shift_reg, y, x);
}

void fir (
  data_t I,
  data_t Q,

  data_t *X,
  data_t *Y
  ) {


	data_t IinIfir, QinQfir, QinIfir, IinQfir;

//	//Calculate X
	firI1(&IinIfir, I);
	firQ1(&QinQfir, Q);

//	//Calculate Y
	firI2(&QinIfir, Q);
	firQ2(&IinQfir, I);

	*X = IinIfir + QinQfir;
	*Y = QinIfir - IinQfir;
}
