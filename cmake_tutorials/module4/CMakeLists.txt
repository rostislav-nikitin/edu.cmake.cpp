cmake_minimum_required(VERSION 3.0.0)

message("Hello world")
set(NAME BOB Smith)
set (HEIGHT 190)

message("Hello, my name is ${NAME}, my height is ${HEIGHT}cm and my age is ${AGE} years")

set (NAME Alice)
set (Alice Bob)

message(NAME ${NAME} ${${NAME}})
message(NAME${NAME}${${NAME}})
message("NAME ${NAME} ${${NAME}}")

set (NAMEAliceBob Charlie)
message(${NAME${NAME}${${NAME}}})


set (VAR a b c;d "e;f" 2.7 "Hello There")
message("${VAR}")

list(APPEND VAR 1.6 XX)
message("${VAR}")

list(REMOVE_AT VAR 2 -3)
message("${VAR}")

list(REMOVE_ITEM VAR a 2.7)
message("${VAR}")

list(INSERT VAR 2 XX 2.7)
message("${VAR}")

list(REVERSE VAR)
message("${VAR}")

list(REMOVE_DUPLICATES VAR)
message("${VAR}")

list(SORT VAR)
message("${VAR}")
		
list(LENGTH VAR len_var)
message("${len_var}")

list(GET VAR 2 5 6 sub_list)
message("${sub_list}")

list(SUBLIST VAR 2 3 sub_list2)
message("${sub_list2}")

list(JOIN VAR ++ str_list)
message("${str_list}")

list(FIND VAR XX find_var)
message("${find_var}")

message(NULL)
#message(${NOT_EXISTS})

