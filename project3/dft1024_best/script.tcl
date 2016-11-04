############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 2015 Xilinx Inc. All rights reserved.
############################################################
open_project dft1024
set_top dft
add_files D:/Workspaces/cse237c_wzegers/project3/dft1024/coefficients1024.h
add_files D:/Workspaces/cse237c_wzegers/project3/dft1024/dft.cpp
add_files D:/Workspaces/cse237c_wzegers/project3/dft1024/dft.h
add_files -tb D:/Workspaces/cse237c_wzegers/project3/dft1024/dft_test.cpp
add_files -tb D:/Workspaces/cse237c_wzegers/project3/dft1024/out.gold.dat
open_solution "best"
set_part {xc7z020clg484-1}
create_clock -period 10 -name default
#source "./dft1024/best/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
