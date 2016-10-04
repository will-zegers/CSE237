############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 2015 Xilinx Inc. All rights reserved.
############################################################
open_project fir128_optimized
set_top fir
add_files ../Workspaces/cse237c_wzegers/project1/fir128_optimized/fir.cpp
add_files ../Workspaces/cse237c_wzegers/project1/fir128_optimized/fir.h
add_files -tb ../Workspaces/cse237c_wzegers/project1/fir128/fir_test.cpp
add_files -tb ../Workspaces/cse237c_wzegers/project1/fir128/input.dat
add_files -tb ../Workspaces/cse237c_wzegers/project1/fir128/out.gold.dat
open_solution "solution1"
set_part {xc7z020clg484-1}
create_clock -period 3 -name default
#source "./fir128_optimized/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
