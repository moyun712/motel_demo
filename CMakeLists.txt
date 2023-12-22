cmake_minimum_required(VERSION 3.27.0)
project(dsd02 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_BUILD_TYPE "Debug")

include_directories(include lib)

set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/build)


add_executable(dsd02
        cmd/menu.c
        include/mod.h
        service/mod.c
        include/mod_repo.h
        data/linklist_mod_repo.c
)
add_executable(dsd01
        cmd/menu.c
        include/mod.h
        service/mod.c
        include/mod_repo.h
        data/graph_mod_repo.c
)

