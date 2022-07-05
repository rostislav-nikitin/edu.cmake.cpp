CMakeLists.txt - lists
* Targets
  * Executable
    * add_executable({executable_name} {dependency1} {dependency2} ... {dependencyN})
  * Library
    * add_library({library_name} {dependency1} {dependency2} ... {dependencyN})
* Includes
  * Info: adds compiler option -I{directory}
  * Usage: target_include_directories({target_name} {directory1} {directory2} ... {directoryN})
* Links
  * Info: adds compiler option -L{library_name}
  * Usge: target_link_libraries({target_name} {library1} {library2} ... {libraryN})
* SubDirectory
  * Info: just another sub directory with a CMakeLists.txt file
  * Scope: in new scope except set(VARNAME, VALUE, PARENT_SCOPE) -- then in the parent CMakeLists.txt scope
  * Usage: add_subdirectory({sub_directory_name})
  * Other: Exceutes CMakeLists.txt
* Function
  * Declaration:
	function({NAME} arg1 agr2 ... argN)
		#CODE
	endfunction()

	Example 1:
	
		function(fn arg1)
			message("${arg}=${${arg1}}")
		endfunction()

		set(VAR1 "Some val")
		fn(VAR1)
		Output:
			VAR1=Some val

	Example 2:
	
		function(fn arg1)
			message("Value is ${arg1}")
		endfunction()

		set(VAR1 "Some val")
		fn(${VAR1})
		Output:
			Value is Some val
  * Scope: in new function scope except set(VARNAME, VALUE, PARENT_SCOPE) -- then in the parent CMakeLists.txt scope
  * Args: 
    * ARGC - total number of args
    * ARGV - list of all args
    * ARGN - list of optional args
    *ARG0, ARG1, ... ARGN -- args by special name
  * Call: {function_name}(arg1 arg2 ... argN)
  * Macro
    * Declaration:
	macro({NAME} arg1 agr2 ... argN)
		#CODE
	endmacro()
    * Scope: in scope of parent CMakeLists.txt
    * Other: Textual replacements to args values
* Modules
  * Standard modules
    * Located: /usr/local/share/CMake-3.16/Modules
    * Scope: in scope of parent CMakeLists.txt
    * Include: include({module_name})
    * Idea: provide to users some standatd functionality
  * User modules
    * Located: Usually in a same directory where CMakeLists.txt located (or in subdir).
    * File: {module_name}.cmake
    * Scope: in scope of parent CMakeLists.txt
    * Include: include({module_name})
    * Other: By default CMake looks for standard modules. But if you want user module should be found add path with module to the  CMAKE_MODULE_PATH list:
    * list(APPEND  CMAKE_MODULE_PATH  {path-to-module-directory})
    * include({my_module})
    * Idead: to structure the code in a separate modules instead of one long CMakeLists.txt file
	
* Variables
  * Local/Parent scope
    * set
      * set({variable_name}, {value} [,PARENT_SCOPE])
    * get
      * message("${variable_name}")
  * Cached
    * set
      * set({variable_name}, {value} CACHE STRING "variable description")
    * get:
      * message("${variable_name}") -- priority: first look local variable, it not found look cached one
      * message("$CACHE{variable_name}") -- priority: first look local variable, it not found look cached one
  * Environment
    * set
      * set(ENV{variable_name}, {value})
    * get
      * message("$ENV{variable_name}")
			
* Variables types
  * String
    * set({variable_name} "item1 item2") -- creates string: "item1 item2"
    * string(LENGTH {string_variable_name} {sting_length_variable_to_set_pseudo_return_just_set_parent_scope_variable})
  * List
    * set({variable_name} item1 item2;item3 "item4;item5") -- creates list: item1;item2;item3;item4;item5
    * list(APPEND {list_name} item1 item2 ... itemN)
