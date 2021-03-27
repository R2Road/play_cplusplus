#include "variadic_template_test.h"

#include <iostream>

namespace
{
	template<typename... Types>
	struct ArgsCount
	{
		static constexpr std::size_t size = sizeof...( Types );
	};
}
namespace variadic_template_test
{
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
}
namespace variadic_template_test
{
	void PrintValues::Do()
	{
		std::cout << "== PrintValues ==" << std::endl;

		std::cout << "\t" << "+ print( 1, 2, 3, 4, ""variadic_template_test"", 3.141592 )" << std::endl;

		print_args( 1, 2, 3, 4, "variadic_template_test", 3.141592 );

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


	template<int... IntegerList>
	struct SumArgs;

	template<>
	struct SumArgs<>
	{
		static constexpr int result = 0;
	};

	template<int N, int... IntegerList>
	struct SumArgs<N, IntegerList...>
	{
		static constexpr int result = N + SumArgs<IntegerList...>::result;
	};
}
namespace variadic_template_test
{
	void SumValues::Do()
	{
		std::cout << "== Sum Values ==" << std::endl;

		{
			std::cout << "\t" << "+ sum_args_with_fold_1( 1, 2, 3, 4, 5, 6, 7, 8, 9 )" << std::endl;
			std::cout << "\t\t" << "return ( ... + integer_list )" << std::endl;

			const auto sum_result = sum_args_with_fold_1( 1, 2, 3, 4, 5, 6, 7, 8, 9 );

			std::cout << "\t\t\t" << sum_result << std::endl;
		}

		std::cout << std::endl << std::endl;

		{
			std::cout << "\t" << "+ sum_args_with_fold_2( 1, 2, 3, 4, 5, 6, 7, 8, 9 )" << std::endl;
			std::cout << "\t\t" << "return ( integer_list + ... )" << std::endl;

			const auto sum_result = sum_args_with_fold_2( 1, 2, 3, 4, 5, 6, 7, 8, 9 );

			std::cout << "\t\t\t" << sum_result << std::endl;
		}

		std::cout << std::endl << std::endl;

		{
			std::cout << "\t" << "+ SumArgs<1>::result" << std::endl;

			const auto sum_result = SumArgs<1>::result;

			std::cout << "\t\t\t" << sum_result << std::endl;
		}

		std::cout << std::endl << std::endl;

		{
			std::cout << "\t" << "+ SumArgs<1, 2, 3, 4, 5, 6, 7, 8, 9>::result" << std::endl;

			const auto sum_result = SumArgs<1, 2, 3, 4, 5, 6, 7, 8, 9>::result;

			std::cout << "\t\t\t" << sum_result << std::endl;
		}

		std::cout << std::endl << std::endl;
	}
}




namespace
{
	template <typename... IntegerList>
	int subtract_args_with_fold_1(IntegerList... integer_list ) {
		return ( integer_list - ... ); // fold
	}

	template <typename... IntegerList>
	int subtract_args_with_fold_2( IntegerList... integer_list ) {
		return ( ... - integer_list ); // fold
	}

	template <typename I, typename... IntegerList>
	int subtract_args_with_fold_3( I integer, IntegerList... integer_list ) {
		return ( integer - ... - integer_list ); // fold
	}
}
namespace variadic_template_test
{
	void SubtractValues::Do()
	{
		std::cout << "== Subtract Values ==" << std::endl;

		{
			std::cout << "\t" << "+ int subtract_args_with_fold_1(IntegerList... integer_list )" << std::endl;
			std::cout << "\t\t" << "return ( integer_list - ... );" << std::endl;
			std::cout << std::endl;

			{
				std::cout << "\t\t" << "Call : subtract_args_with_fold_1( 10, 5 );" << std::endl;

				std::cout << "\t\t\t" << subtract_args_with_fold_1( 10, 5 ) << std::endl;
			}

			std::cout << std::endl;

			{
				std::cout << "\t\t" << "Call : subtract_args_with_fold_1( 5, 10 );" << std::endl;

				std::cout << "\t\t\t" << subtract_args_with_fold_1( 5, 10 ) << std::endl;
			}

			std::cout << std::endl;

			{
				std::cout << "\t\t" << "Call : subtract_args_with_fold_1( 100, 1, 2, 3, 4, 5, 6, 7, 8, 9 );" << std::endl;

				std::cout << "\t\t\t" << subtract_args_with_fold_1( 100, 1, 2, 3, 4, 5, 6, 7, 8, 9 ) << std::endl;

				std::cout << "\t\t\t" << "?????????????????????" << std::endl;
			}

			std::cout << std::endl;

			{
				std::cout << "\t\t" << "Call : subtract_args_with_fold_1( 10, 1, 1 );" << std::endl;

				std::cout << "\t\t\t" << subtract_args_with_fold_1( 10, 1, 1 ) << std::endl;

				std::cout << "\t\t\t" << "?????????????????????" << std::endl;
			}

			std::cout << std::endl;

			{
				std::cout << "\t\t" << "Call : subtract_args_with_fold_1( 1, 1, 1 );" << std::endl;

				std::cout << "\t\t\t" << subtract_args_with_fold_1( 1, 1, 1 ) << std::endl;

				std::cout << "\t\t\t" << "?????????????????????" << std::endl;
			}

			std::cout << std::endl;

			{
				std::cout << "\t\t" << "Call : subtract_args_with_fold_1( 1, 1, 2 );" << std::endl;

				std::cout << "\t\t\t" << subtract_args_with_fold_1( 1, 1, 2 ) << std::endl;

				std::cout << "\t\t\t" << "?????????????????????" << std::endl;
			}

			std::cout << std::endl;

			{
				std::cout << "\t\t" << "Call : subtract_args_with_fold_1( 1, 1, 2, 3 );" << std::endl;

				std::cout << "\t\t\t" << subtract_args_with_fold_1( 1, 1, 2, 3 ) << std::endl;

				std::cout << "\t\t\t" << "?????????????????????" << std::endl;
			}

			std::cout << std::endl;

			{
				std::cout << "\t\t" << "Test : ( 100 - 1 ) + ( 2 - 3 ) + ( 4 - 5 ) + ( 6 - 7 ) + ( 8 - 9 );" << std::endl;

				std::cout << "\t\t\t" << ( ( 100 - 1 ) + ( 2 - 3 ) + ( 4 - 5 ) + ( 6 - 7 ) + ( 8 - 9 ) ) << std::endl;

				std::cout << "\t\t\t" << "Maybe????" << std::endl;
			}
		}

		std::cout << std::endl << std::endl;

		{
			std::cout << "\t" << "+ int subtract_args_with_fold_2(IntegerList... integer_list )" << std::endl;
			std::cout << "\t\t" << "return ( ... - integer_list );" << std::endl;
			std::cout << std::endl;

			std::cout << "\t\t" << "Call : subtract_args_with_fold_2( 100, 1, 2, 3, 4, 5, 6, 7, 8, 9 )" << std::endl;

			std::cout << "\t\t\t" << subtract_args_with_fold_2( 100, 1, 2, 3, 4, 5, 6, 7, 8, 9 ) << std::endl;
		}

		std::cout << std::endl << std::endl;

		{
			std::cout << "\t" << "+ int subtract_args_with_fold_3( I integer, IntegerList... integer_list )" << std::endl;
			std::cout << "\t\t" << "return ( integer - ... - integer_list );" << std::endl;
			std::cout << std::endl;

			std::cout << "\t\t" << "Call : subtract_args_with_fold_3( 100, 1, 2, 3, 4, 5, 6, 7, 8, 9 )" << std::endl;

			std::cout << "\t\t\t" << subtract_args_with_fold_3( 100, 1, 2, 3, 4, 5, 6, 7, 8, 9 ) << std::endl;
		}

		std::cout << std::endl << std::endl;
	}
}