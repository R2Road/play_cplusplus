#include "variadic_template_test.h"

#include <iostream>
#include <memory>

namespace
{
	template <typename T>
	void print( T arg ) {
		std::cout << "\t\t" << "call - print( T arg ) : " << arg;
	}

	template <typename T, typename... Types>
	void print( T arg, Types... args ) {
		std::cout << "\t\t" << "call - print( T arg, Types... args ) : " << arg << std::endl;
		print( args... );
	}

	template <typename... Types>
	void print_args( Types... args ) {
		std::cout << "\t\t" << "call - print_args( Types... args )" << std::endl;
		print( args... );
	}

	void Test1()
	{
		std::cout << "== PrintValues ==" << std::endl;

		std::cout << "\t" << "+ print( 1, 2, 3, 4, ""variadic_template_test"", 3.141592 )" << std::endl;

		print_args( 1, 2, 3, 4, "variadic_template_test", 3.141592 );
	}
}

namespace variadic_template_test
{
	void PrintValues::Do()
	{
		Test1();

		std::cout << std::endl << std::endl;
	}
}