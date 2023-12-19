cmake_minimum_required(VERSION 3.28.1)
project(dsd02)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include lib)

add_executable(dsd02 
        cmd/menu.c
        include/inv.h
        service/inv.c
        data/linklist_inv_repo.c
        )

add_executable(dsd01
        cmd/menu.c
        include/inv.h
        service/inv.c
        data/graph_inv_repo.c)




