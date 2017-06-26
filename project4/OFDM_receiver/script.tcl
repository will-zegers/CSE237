############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 2015 Xilinx Inc. All rights reserved.
############################################################
open_project ofdm
set_top ofdm_receiver
add_files ../../Workspaces/cse237c_wzegers/project4/project4_student/HLS/3_OFDM/fft.cpp
add_files ../../Workspaces/cse237c_wzegers/project4/project4_student/HLS/3_OFDM/fft.h
add_files ../../Workspaces/cse237c_wzegers/project4/project4_student/HLS/3_OFDM/ofdm_recvr.cpp
add_files ../../Workspaces/cse237c_wzegers/project4/project4_student/HLS/3_OFDM/qpsk_decode.cpp
add_files -tb ../../Workspaces/cse237c_wzegers/project4/project4_student/HLS/3_OFDM/input.dat
add_files -tb ../../Workspaces/cse237c_wzegers/project4/project4_student/HLS/3_OFDM/ofdm_test.cpp
add_files -tb ../../Workspaces/cse237c_wzegers/project4/project4_student/HLS/3_OFDM/out.gold.dat
open_solution "baseline"
set_part {xc7z020clg484-1}
create_clock -period 10 -name default
#source "./ofdm/baseline/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
