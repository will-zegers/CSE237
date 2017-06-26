############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 2015 Xilinx Inc. All rights reserved.
############################################################
open_project dft256
set_top dft
add_files ../../Workspaces/cse237c_wzegers/project3/dft256/dft.h
add_files ../../Workspaces/cse237c_wzegers/project3/dft256/dft.cpp
add_files ../../Workspaces/cse237c_wzegers/project3/dft256/coefficients256.h
add_files -tb ../../Workspaces/cse237c_wzegers/project3/dft256/out.gold.dat
add_files -tb ../../Workspaces/cse237c_wzegers/project3/dft256/dft_test.cpp
open_solution "dataflow"
set_part {xc7z020clg484-1}
create_clock -period 10 -name default
#source "./dft256/dataflow/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
