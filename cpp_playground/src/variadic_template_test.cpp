#include "variadic_template_test.h"

#include <iostream>

namespace variadic_template_test
{
	template<typename... Types>
	struct ArgsCount
	{
		static constexpr std::size_t size = sizeof...( Types );
	};

	void SizeOfArgs::Do()
	{
		std::cout << "== Size Of Args ==" << std::endl;

		std::cout << "\t" << "+ ArgsCount<int, float, int, int, bool>::size" << std::endl;
		std::cout << "\t\t" << ArgsCount<int, float, int, int, bool>::size << std::endl;

		std::cout << std::endl << std::endl;
	}
}

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




namespace
{
	template <typename... IntegerList>
	int sum_args_with_fold_1( IntegerList... integer_list ) {
		return ( ... + integer_list ); // fold
	}

	template <typename... IntegerList>
	int sum_args_with_fold_2( IntegerList... integer_list ) {
		return ( integer_list + ... ); // fold
	}

	template<int N, int... IntegerList>
	struct SumArgs
	{
		static constexpr int result = N + SumArgs<IntegerList...>::result;
	};
	template<>
	struct SumArgs<0>
	{
		static constexpr int result = 0;
	};
}
namespace variadic_template_test
{
	void SumValues::Do()
	{
		std::cout << "== Sum Values ==" << std::endl;

		{
			std::cout << "\t" << "+ sum_args_with_fold_1( 1, 2, 3, 4, 5, 6, 7, 8, 9 )" << std::endl;
			std::cout << "\t\t" << "call - sum_args_with_fold_1( Types... integer_list ) return ( ... + integer_list )" << std::endl;

			const auto sum_result = sum_args_with_fold_1( 1, 2, 3, 4, 5, 6, 7, 8, 9 );

			std::cout << "\t\t\t" << sum_result << std::endl;
		}

		std::cout << std::endl << std::endl;

		{
			std::cout << "\t" << "+ sum_args_with_fold_2( 1, 2, 3, 4, 5, 6, 7, 8, 9 )" << std::endl;
			std::cout << "\t\t" << "call - sum_args_with_fold_2( Types... integer_list ) return ( integer_list + ... )" << std::endl;

			const auto sum_result = sum_args_with_fold_2( 1, 2, 3, 4, 5, 6, 7, 8, 9 );

			std::cout << "\t\t\t" << sum_result << std::endl;
		}

		std::cout << std::endl << std::endl;

		{
			std::cout << "\t" << "+ SumArgs<1, 2, 3, 4, 5, 6, 7, 8, 9, 0>::result" << std::endl;
			std::cout << "\t\t" << "0 is End Indicator" << std::endl;

			const auto sum_result = SumArgs<1, 2, 3, 4, 5, 6, 7, 8, 9, 0>::result;

			std::cout << "\t\t\t" << sum_result << std::endl;
		}

		std::cout << std::endl << std::endl;
	}
}




namespace
{
	template <typename I, typename... IntegerList>
	int subtract_args_1( I integer, IntegerList... integer_list ) {
		std::cout << "\t\t" << "call - subtract_args_1( I integer, IntegerList... integer_list ) return ( integer + ... + integer_list )" << std::endl;
		return ( integer - ... - integer_list ); // fold
	}

	void SubtractValues_Test1()
	{
		std::cout << "== Subtract Values ==" << std::endl;

		{
			std::cout << "\t" << "+ subtract_args_1( 100, 2, 3, 4, 5, 6, 7, 8, 9 )" << std::endl;

			const auto sum_result = subtract_args_1( 100, 1, 2, 3, 4, 5, 6, 7, 8, 9 );

			std::cout << "\t\t\t" << sum_result << std::endl;
		}
	}
}
namespace variadic_template_test
{
	void SubtractValues::Do()
	{
		SubtractValues_Test1();

		std::cout << std::endl << std::endl;
	}
}