#include "pch.h"
#include "variadic_template_test.h"

#include "base/r2_eTestEndAction.h"

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
	r2::iItem::TitleFuncT SizeOfArgs::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Size Of Args";
		};
	}
	r2::iItem::DoFunc SizeOfArgs::GetDoFunction()
	{
		return []()->r2::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "template<typename... Types>" << r2::linefeed;
				std::cout << r2::tab2 << "struct ArgsCount" << r2::linefeed;
				std::cout << r2::tab2 << "{" << r2::linefeed;
				std::cout << r2::tab3 << "static constexpr std::size_t size = sizeof...( Types );" << r2::linefeed;
				std::cout << r2::tab2 << "}" << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ ArgsCount<int, float, int, int, bool>::size" << r2::linefeed2;
				std::cout << r2::tab2 << "> " << ArgsCount<int, float, int, int, bool>::size << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestEndAction::Pause;
		};
	}
}




namespace
{
	template <typename T>
	void print( T arg ) {
		std::cout << r2::tab2 << "call - print( T arg ) : " << arg;
	}

	template <typename T, typename... Types>
	void print( T arg, Types... args ) {
		std::cout << r2::tab2 << "call - print( T arg, Types... args ) : " << arg << r2::linefeed;
		print( args... );
	}

	template <typename... Types>
	void print_args_1( Types... args ) {
		std::cout << r2::tab2 << "call - print_args_1( Types... args )" << r2::linefeed;
		print( args... );
		std::cout << r2::linefeed;
	}


	template <typename... Types>
	void print_args_2( Types... args ) {
		( std::cout << ... << args );
	}
}
namespace variadic_template_test
{
	r2::iItem::TitleFuncT PrintValues::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Print Values";
		};
	}
	r2::iItem::DoFunc PrintValues::GetDoFunction()
	{
		return []()->r2::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ print_args_1( 1, 2, 3, 4, \"variadic_template_test\", 3.141592 )" << r2::linefeed;

				print_args_1( 1, 2, 3, 4, "variadic_template_test", 3.141592 );
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "template <typename... Types>" << r2::linefeed;
				std::cout << r2::tab2 << "void print_args_2( Types... args )" << r2::linefeed;
				std::cout << r2::tab2 << "{" << r2::linefeed;
				std::cout << r2::tab3 << "( std::cout << ... << args );" << r2::linefeed;
				std::cout << r2::tab2 << "}" << r2::linefeed2;

				std::cout << r2::tab << "+ Call" << r2::linefeed2;
				std::cout << r2::tab2 << "print_args_2( 1, 2, 3, 4, \"variadic_template_test\", 3.141592 )" << r2::linefeed2;

				std::cout << r2::tab2 << "> ";
				print_args_2( 1, 2, 3, 4, "variadic_template_test", 3.141592 );
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestEndAction::Pause;
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
	r2::iItem::TitleFuncT SumValues::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Sum Values";
		};
	}
	r2::iItem::DoFunc SumValues::GetDoFunction()
	{
		return []()->r2::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ sum_args_with_fold_1( 1, 2, 3, 4, 5, 6, 7, 8, 9 )" << r2::linefeed;
				std::cout << r2::tab2 << "return ( ... + integer_list )" << r2::linefeed;

				const auto sum_result = sum_args_with_fold_1( 1, 2, 3, 4, 5, 6, 7, 8, 9 );

				std::cout << r2::tab3 << sum_result << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ sum_args_with_fold_2( 1, 2, 3, 4, 5, 6, 7, 8, 9 )" << r2::linefeed;
				std::cout << r2::tab2 << "return ( integer_list + ... )" << r2::linefeed;

				const auto sum_result = sum_args_with_fold_2( 1, 2, 3, 4, 5, 6, 7, 8, 9 );

				std::cout << r2::tab3 << sum_result << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ SumArgs<1>::result" << r2::linefeed;

				const auto sum_result = SumArgs<1>::result;

				std::cout << r2::tab3 << sum_result << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ SumArgs<1, 2, 3, 4, 5, 6, 7, 8, 9>::result" << r2::linefeed;

				const auto sum_result = SumArgs<1, 2, 3, 4, 5, 6, 7, 8, 9>::result;

				std::cout << r2::tab3 << sum_result << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestEndAction::Pause;
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
	r2::iItem::TitleFuncT SubtractValues::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Subtract Values";
		};
	}
	r2::iItem::DoFunc SubtractValues::GetDoFunction()
	{
		return []()->r2::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ int subtract_args_with_fold_1(IntegerList... integer_list )" << r2::linefeed;
				std::cout << r2::tab2 << "return ( integer_list - ... );" << r2::linefeed;
				std::cout << r2::linefeed;

				{
					std::cout << r2::tab2 << "Call : subtract_args_with_fold_1( 10, 5 );" << r2::linefeed;

					std::cout << r2::tab3 << subtract_args_with_fold_1( 10, 5 ) << r2::linefeed;
				}

				std::cout << r2::linefeed;

				{
					std::cout << r2::tab2 << "Call : subtract_args_with_fold_1( 5, 10 );" << r2::linefeed;

					std::cout << r2::tab3 << subtract_args_with_fold_1( 5, 10 ) << r2::linefeed;
				}

				std::cout << r2::linefeed;

				{
					std::cout << r2::tab2 << "Call : subtract_args_with_fold_1( 100, 1, 2, 3, 4, 5, 6, 7, 8, 9 );" << r2::linefeed;

					std::cout << r2::tab3 << subtract_args_with_fold_1( 100, 1, 2, 3, 4, 5, 6, 7, 8, 9 ) << r2::linefeed;
				}

				std::cout << r2::linefeed;

				{
					std::cout << r2::tab2 << "Test : ( 100 - ( 1 - ( 2 - ( 3 - ( 4 - ( 5 - ( 6 - ( 7 - ( 8 - 9 ) ) ) ) ) ) ) ) );" << r2::linefeed;

					std::cout << r2::tab3 << ( 100 - ( 1 - ( 2 - ( 3 - ( 4 - ( 5 - ( 6 - ( 7 - ( 8 - 9 ) ) ) ) ) ) ) ) ) << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ int subtract_args_with_fold_2(IntegerList... integer_list )" << r2::linefeed;
				std::cout << r2::tab2 << "return ( ... - integer_list );" << r2::linefeed;
				std::cout << r2::linefeed;

				{
					std::cout << r2::tab2 << "Call : subtract_args_with_fold_2( 100, 1, 2, 3, 4, 5, 6, 7, 8, 9 )" << r2::linefeed;

					std::cout << r2::tab3 << subtract_args_with_fold_2( 100, 1, 2, 3, 4, 5, 6, 7, 8, 9 ) << r2::linefeed;
				}

				std::cout << r2::linefeed;

				{
					std::cout << r2::tab2 << "Test : ( ( ( ( ( ( ( ( ( 100 - 1 ) - 2 ) - 3 ) - 4 ) - 5 ) - 6 ) - 7 ) - 8 ) - 9 );" << r2::linefeed;

					std::cout << r2::tab3 << ( ( ( ( ( ( ( ( ( 100 - 1 ) - 2 ) - 3 ) - 4 ) - 5 ) - 6 ) - 7 ) - 8 ) - 9 ) << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ int subtract_args_with_fold_3( I integer, IntegerList... integer_list )" << r2::linefeed;
				std::cout << r2::tab2 << "return ( integer_list - ... - integer );" << r2::linefeed;
				std::cout << r2::linefeed;

				std::cout << r2::tab2 << "Call : subtract_args_with_fold_3( 100, 1, 2, 3, 4, 5, 6, 7, 8, 9 )" << r2::linefeed;

				std::cout << r2::tab3 << subtract_args_with_fold_4( 100, 1, 2, 3, 4, 5, 6, 7, 8, 9 ) << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ int subtract_args_with_fold_4( I integer, IntegerList... integer_list )" << r2::linefeed;
				std::cout << r2::tab2 << "return ( integer - ... - integer_list );" << r2::linefeed;
				std::cout << r2::linefeed;

				std::cout << r2::tab2 << "Call : subtract_args_with_fold_4( 100, 1, 2, 3, 4, 5, 6, 7, 8, 9 )" << r2::linefeed;

				std::cout << r2::tab3 << subtract_args_with_fold_3( 100, 1, 2, 3, 4, 5, 6, 7, 8, 9 ) << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestEndAction::Pause;
		};
	}
}