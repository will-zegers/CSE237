############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 2015 Xilinx Inc. All rights reserved.
############################################################
open_project fft1024
set_top fft
add_files ../../Workspaces/cse237c_wzegers/project4/project4_student/HLS/2_Skeleton_Restructured/fft.cpp
add_files ../../Workspaces/cse237c_wzegers/project4/project4_student/HLS/2_Skeleton_Restructured/fft.h
add_files -tb ../../Workspaces/cse237c_wzegers/project4/project4_student/HLS/2_Skeleton_Restructured/fft_test.cpp
add_files -tb ../../Workspaces/cse237c_wzegers/project4/project4_student/HLS/2_Skeleton_Restructured/out.gold.dat
open_solution "best"
set_part {xc7z020clg484-1}
create_clock -period 10 -name default
#source "./fft1024/best/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
