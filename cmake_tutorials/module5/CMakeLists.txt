cmake_minimum_required(VERSION 3.0.0)

set(VAR OFF)
set(VAR2 VAR)

if(${VAR2})
		message("If block executed")
else()
		message("Else block executed")
endif()


set(Name Alice)

if(DEFINED Name)
		message("Name is: ${Name}")
else()
		message("Name is unknown")
endif()

if(DEFINED Age)
		message("Age is: ${Age}")
else()
		message("Age is unknown")
endif()

if(COMMAND target_link_library)
		message("target_link_library is a command")
else()
		message("target_link_library is NOT a command")
endif()

if(EXISTS ./CMakeLists.txt)
		message("File exists")
else()
		message("File NOT exists")
endif()


#BINARY TESTS

set(Name1 Bob)
set(Name2 Bob)

if(Name1 STRLESS Name2)
		message("${Name1} is less then ${Name2}")
elseif(Name1 STRGREATER Name2)
		message("${Name1} is greater then ${Name2}")
elseif(Name1 STREQUAL Name2)
		message("${Name1} is equal to ${Name2}")
else()
		message("WTF?")
endif()

#LOOPS

set(VAR "")
#set(str_len 0)
if(VAR STREQUAL "")
		set(str_len 0)
else()
	string(LENGTH ${VAR} str_len)
endif()

while(NOT str_len STREQUAL 10)
	set(VAR ${VAR}a)
	message (${VAR})
	string(LENGTH ${VAR} str_len)
	message("${str_len}")
endwhile()


foreach(var a b c d e f)
	message(${var})
endforeach()


foreach(var RANGE 10)
	message(${var})
endforeach()
foreach(var RANGE 10 20)
	message(${var})
endforeach()
foreach(var RANGE 10 20 3)
	message(${var})
endforeach()


set(list1 1 2 3)
set(list2 x y z)
set(list3 a b c)

foreach(var IN LISTS list1 list2 list3)
		message("x = ${var}")
endforeach()


#FUNCTION
function(print_name name)
		message("1. My name is ${name}")
endfunction()

function(print_name name)
		message("2. My name is ${name}")

		if(DEFINED ARGV0)
				message("ARGV0=Hello, my name is ${ARGV0}")
		endif()

		if(DEFINED ARGV1)
				message("ARGV1=Hello, my name is ${ARGV1}")
		endif()

		if(DEFINED ARGV2)
				message("ARGV2=Hello, my name is ${ARGV2}")
		endif()

		message("${ARGC}")
		message("${ARGV}")
		message("${ARGN}")
endfunction()

set(Name Charlie)

print_name(${Name})
_print_name(${Name})

print_name(${Name} Bob)


function(fn_scope_test name)
		message("Inside function :: Before name updated :: Name = ${name}")
		set(name "New Value")
		message("Inside function :: After name updated :: Name = ${name}")
endfunction()

set(name "Charlie")

message("Outside function :: Before call :: Name = ${name}")
fn_scope_test(${name})
message("Outside function :: After all :: Name = ${name}")

set(name "Charlie")

function(fn_parent_scope_test)
		#New name variable created and value copied from parent scope
		#Local scope var printed
		message("Inside function :: Before name updated :: Name = ${name}")
		#Parent scope variable set
		set(name "New Value" PARENT_SCOPE)
		#Local scope var printed
		message("Inside function :: After name updated :: Name = ${name}")
endfunction()

set(name "Charlie")

message("Outside function :: Before call :: Name = ${name}")
fn_parent_scope_test()
message("Outside function :: After all :: Name = ${name}")

#MACRO

macro(m_test name)
	# ${name} textly replaced with name parameter value
	message("name=${name}")
	set(name "Bob")
	message("name=${name}")
endmacro()

m_test(Charlie)
message(${name})


function(set_name temp_name)
		set(NameVar ${temp_name} PARENT_SCOPE)
endfunction()

set_name(CMake)

message(${NameVar})


