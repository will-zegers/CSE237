############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 2015 Xilinx Inc. All rights reserved.
############################################################
open_project fir_top
set_top fir
add_files ./fir.cpp
add_files ./fir.h
add_files -tb ./fir_test.cpp
add_files -tb ./input_i.dat
add_files -tb ./input_q.dat
add_files -tb ./out.gold.dat
open_solution "optimized1"
set_part {xc7z020clg484-1}
create_clock -period 10 -name default
#source "./fir_top/baseline/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
