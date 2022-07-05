cmake_minimum_required(VERSION 3.0.0)
project(Claculator_Project VERSION 1.0.0)


add_subdirectory(my_math)
add_subdirectory(my_print)

add_executable(calculator
		main.cpp)

target_link_libraries(calculator
		my_math
		my_print)

#set(A 000)
set(ENV VARB "111")
set(A "123" CACHE STRING "This command sets variable A is persistent cache")

message(${A})
#message($ENV{VARB})
#message($CACHE{A})

set(Name Alice CACHE STRING "Name variable")
#set(Name Bob CACHE STRING "Name modified variable" FORCE)
#set(Name Charlie CACHE STRING "Name modified twice variable")
message($CACHE{Name})


#SYSTEM CACHE VARIABLES
message("CMAKE_VERSION=${CMAKE_VERSION}")
message("CMAKE_MAJOR_VERSION=${CMAKE_MAJOR_VERSION}")
message("CMAKE_MINOR_VERSION=${CMAKE_MINOR_VERSION}")
message("CMAKE_PATCH_VERSION=${CMAKE_PATCH_VERSION}")
message("CMAKE_CACHE_MAJOR_VERSION=${CMAKE_CACHE_MAJOR_VERSION}")
message("CMAKE_CACHE_MINOR_VERSION=${CMAKE_CACHE_MINOR_VERSION}")
message("CMAKE_CACHE_PATH_VERSION=${CMAKE_CACHE_PATCH_VERSION}")


message("CMAKE_PROJECT_NAME=${CMAKE_PROJECT_NAME}")
message("PROJECT_NAME=${PROJECT_NAME}")
