############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 2015 Xilinx Inc. All rights reserved.
############################################################
open_project phase_detector
set_top phasedetector
add_files ./cordiccart2pol.cpp
add_files ./fir.cpp
add_files ./phasedetector.cpp
add_files ./phasedetector.h
add_files -tb ./input_i.dat
add_files -tb ./input_q.dat
add_files -tb ./out.gold.dat
add_files -tb ./phasedetector_test.cpp
open_solution "optimized2"
set_part {xc7z020clg484-1}
create_clock -period 10 -name default
#source "./phase_detector/solution2/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
