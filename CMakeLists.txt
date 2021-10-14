cmake_minimum_required(VERSION 3.20)
project(so_long C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(get_next_line)
include_directories(libft)

add_executable(so_long
        get_next_line/get_next_line.c
        get_next_line/get_next_line_utils.c
        so_long.c
        so_long.h)
