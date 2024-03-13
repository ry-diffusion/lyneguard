cmake_minimum_required(VERSION 3.10)
project(Lyneguard)

add_library(lyneguard STATIC lyneguard.c control.c)

target_include_directories(lyneguard PRIVATE ../kernel)
