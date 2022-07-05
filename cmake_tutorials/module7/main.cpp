#include <iostream>

#include "my_math/addition.h"
#include "my_math/division.h"
#include "my_print/print_result.h"


int main()
{
		float x, y, result_add, result_div;
		std::cout << "Enter first number:" << std::endl;
		std::cin >> x;
		std::cout << "Enter second number:" << std::endl;
		std::cin >> y;

		result_add = addition(x, y);
		print_result("Addition", result_add);
		result_div = division(x, y);
		print_result("Division", result_div);

		return 0;
}
