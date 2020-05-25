cmake_minimum_required(VERSION 3.16)
project(graphs C)

set(CMAKE_C_STANDARD 11)

add_executable(graphs main.c linkedlist.c linkedlist.h graph.c graph.h que.c que.h stack.c stack.h edgeList.c edgeList.h)