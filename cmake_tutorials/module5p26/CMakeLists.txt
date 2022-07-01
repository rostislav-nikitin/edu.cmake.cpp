cmake_minimum_required(VERSION 3.0.0)

list(APPEND CMAKE_MODULE_PATH .)

include(my_module)

include(ProcessorCount)
ProcessorCount(pcount)

message(${pcount})
