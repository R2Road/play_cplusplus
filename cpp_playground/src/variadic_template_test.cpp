#include "pch.h"
#include "variadic_template_test.h"

#include "r2_eTestResult.h"

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
	const r2::iTest::TitleFunc SizeOfArgs::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Size Of Args";
		};
	}
	const r2::iTest::DoFunc SizeOfArgs::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << "\t" << "+ ArgsCount<int, float, int, int, bool>::size" << r2::linefeed;
				std::cout << "\t\t" << ArgsCount<int, float, int, int, bool>::size << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
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
		std::cout << "\t\t" << "call - print( T arg, Types... args ) : " << arg << r2::linefeed;
		print( args... );
	}

	template <typename... Types>
	void print_args_1( Types... args ) {
		std::cout << "\t\t" << "call - print_args_1( Types... args )" << r2::linefeed;
		print( args... );
		std::cout << r2::linefeed;
	}


	template <typename... Types>
	void print_args_2( Types... args ) {
		std::cout << "\t\t" << "call - print_args_2( Types... args )" << r2::linefeed;
		std::cout << "\t\t\t - ";
		( std::cout << ... << args ) << r2::linefeed;
	}
}
namespace variadic_template_test
{
	const r2::iTest::TitleFunc PrintValues::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Print Values";
		};
	}
	const r2::iTest::DoFunc PrintValues::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << "\t" << "+ print_args_1( 1, 2, 3, 4, \"variadic_template_test\", 3.141592 )" << r2::linefeed;

				print_args_1( 1, 2, 3, 4, "variadic_template_test", 3.141592 );
			}

			std::cout << r2::split;

			{
				std::cout << "\t" << "+ print_args_2( 1, 2, 3, 4, \"variadic_template_test\", 3.141592 )" << r2::linefeed;

				print_args_2( 1, 2, 3, 4, "variadic_template_test", 3.141592 );
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
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
	const r2::iTest::TitleFunc SumValues::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Sum Values";
		};
	}
	const r2::iTest::DoFunc SumValues::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << "\t" << "+ sum_args_with_fold_1( 1, 2, 3, 4, 5, 6, 7, 8, 9 )" << r2::linefeed;
				std::cout << "\t\t" << "return ( ... + integer_list )" << r2::linefeed;

				const auto sum_result = sum_args_with_fold_1( 1, 2, 3, 4, 5, 6, 7, 8, 9 );

				std::cout << "\t\t\t" << sum_result << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << "\t" << "+ sum_args_with_fold_2( 1, 2, 3, 4, 5, 6, 7, 8, 9 )" << r2::linefeed;
				std::cout << "\t\t" << "return ( integer_list + ... )" << r2::linefeed;

				const auto sum_result = sum_args_with_fold_2( 1, 2, 3, 4, 5, 6, 7, 8, 9 );

				std::cout << "\t\t\t" << sum_result << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << "\t" << "+ SumArgs<1>::result" << r2::linefeed;

				const auto sum_result = SumArgs<1>::result;

				std::cout << "\t\t\t" << sum_result << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << "\t" << "+ SumArgs<1, 2, 3, 4, 5, 6, 7, 8, 9>::result" << r2::linefeed;

				const auto sum_result = SumArgs<1, 2, 3, 4, 5, 6, 7, 8, 9>::result;

				std::cout << "\t\t\t" << sum_result << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
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
		return ( integer_list - ... - integer ); // fold
	}

	template <typename I, typename... IntegerList>
	int subtract_args_with_fold_4( I integer, IntegerList... integer_list ) {
		return ( integer - ... - integer_list ); // fold
	}
}
namespace variadic_template_test
{
	const r2::iTest::TitleFunc SubtractValues::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Subtract Values";
		};
	}
	const r2::iTest::DoFunc SubtractValues::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << "\t" << "+ int subtract_args_with_fold_1(IntegerList... integer_list )" << r2::linefeed;
				std::cout << "\t\t" << "return ( integer_list - ... );" << r2::linefeed;
				std::cout << r2::linefeed;

				{
					std::cout << "\t\t" << "Call : subtract_args_with_fold_1( 10, 5 );" << r2::linefeed;

					std::cout << "\t\t\t" << subtract_args_with_fold_1( 10, 5 ) << r2::linefeed;
				}

				std::cout << r2::linefeed;

				{
					std::cout << "\t\t" << "Call : subtract_args_with_fold_1( 5, 10 );" << r2::linefeed;

					std::cout << "\t\t\t" << subtract_args_with_fold_1( 5, 10 ) << r2::linefeed;
				}

				std::cout << r2::linefeed;

				{
					std::cout << "\t\t" << "Call : subtract_args_with_fold_1( 100, 1, 2, 3, 4, 5, 6, 7, 8, 9 );" << r2::linefeed;

					std::cout << "\t\t\t" << subtract_args_with_fold_1( 100, 1, 2, 3, 4, 5, 6, 7, 8, 9 ) << r2::linefeed;
				}

				std::cout << r2::linefeed;

				{
					std::cout << "\t\t" << "Test : ( 100 - ( 1 - ( 2 - ( 3 - ( 4 - ( 5 - ( 6 - ( 7 - ( 8 - 9 ) ) ) ) ) ) ) ) );" << r2::linefeed;

					std::cout << "\t\t\t" << ( 100 - ( 1 - ( 2 - ( 3 - ( 4 - ( 5 - ( 6 - ( 7 - ( 8 - 9 ) ) ) ) ) ) ) ) ) << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				std::cout << "\t" << "+ int subtract_args_with_fold_2(IntegerList... integer_list )" << r2::linefeed;
				std::cout << "\t\t" << "return ( ... - integer_list );" << r2::linefeed;
				std::cout << r2::linefeed;

				{
					std::cout << "\t\t" << "Call : subtract_args_with_fold_2( 100, 1, 2, 3, 4, 5, 6, 7, 8, 9 )" << r2::linefeed;

					std::cout << "\t\t\t" << subtract_args_with_fold_2( 100, 1, 2, 3, 4, 5, 6, 7, 8, 9 ) << r2::linefeed;
				}

				std::cout << r2::linefeed;

				{
					std::cout << "\t\t" << "Test : ( ( ( ( ( ( ( ( ( 100 - 1 ) - 2 ) - 3 ) - 4 ) - 5 ) - 6 ) - 7 ) - 8 ) - 9 );" << r2::linefeed;

					std::cout << "\t\t\t" << ( ( ( ( ( ( ( ( ( 100 - 1 ) - 2 ) - 3 ) - 4 ) - 5 ) - 6 ) - 7 ) - 8 ) - 9 ) << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				std::cout << "\t" << "+ int subtract_args_with_fold_3( I integer, IntegerList... integer_list )" << r2::linefeed;
				std::cout << "\t\t" << "return ( integer_list - ... - integer );" << r2::linefeed;
				std::cout << r2::linefeed;

				std::cout << "\t\t" << "Call : subtract_args_with_fold_3( 100, 1, 2, 3, 4, 5, 6, 7, 8, 9 )" << r2::linefeed;

				std::cout << "\t\t\t" << subtract_args_with_fold_4( 100, 1, 2, 3, 4, 5, 6, 7, 8, 9 ) << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << "\t" << "+ int subtract_args_with_fold_4( I integer, IntegerList... integer_list )" << r2::linefeed;
				std::cout << "\t\t" << "return ( integer - ... - integer_list );" << r2::linefeed;
				std::cout << r2::linefeed;

				std::cout << "\t\t" << "Call : subtract_args_with_fold_4( 100, 1, 2, 3, 4, 5, 6, 7, 8, 9 )" << r2::linefeed;

				std::cout << "\t\t\t" << subtract_args_with_fold_3( 100, 1, 2, 3, 4, 5, 6, 7, 8, 9 ) << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}