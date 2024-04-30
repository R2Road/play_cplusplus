#include "template_variadic_test.h"

#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_Inspector.h"

namespace
{
	template<typename... Types>
	struct ArgsCount
	{
		static constexpr std::size_t size = sizeof...( Types );
	};
}
namespace template_variadic_test
{
	r2tm::TitleFunctionT SizeOfArgs::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Size Of Args";
		};
	}
	r2tm::DoFunctionT SizeOfArgs::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				std::cout << r2tm::tab << "+ Declaration" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "template<typename... Types>" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "struct ArgsCount" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "{" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "static constexpr std::size_t size = sizeof...( Types );" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "}" << r2tm::linefeed;
			}

			LS();

			{
				std::cout << r2tm::tab << "+ ArgsCount<int, float, int, int, bool>::size" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "> " << ArgsCount<int, float, int, int, bool>::size << r2tm::linefeed;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}




namespace
{
	template <typename T>
	void print( T arg ) {
		std::cout << r2tm::tab2 << "call - print( T arg ) : " << arg << r2tm::linefeed;
	}

	template <typename T, typename... Types>
	void print( T arg, Types... args ) {
		std::cout << r2tm::tab2 << "call - print( T arg, Types... args ) : " << arg << r2tm::linefeed;
		print( args... );
	}

	template <typename... Types>
	void print_args_1( Types... args ) {
		std::cout << r2tm::tab2 << "call - print_args_1( Types... args )" << r2tm::linefeed;
		print( args... );
	}


	template <typename... Types>
	void print_args_2( Types... args ) {
		( std::cout << ... << args );
	}

	template <typename... Types>
	void print_args_3( Types... args ) {
		( print( args ), ... );
	}
}
namespace template_variadic_test
{
	r2tm::TitleFunctionT PrintValues::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Print Values";
		};
	}
	r2tm::DoFunctionT PrintValues::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				PROCESS_MAIN( print_args_1( 1, 2, 3, 4, "template_variadic_test", 3.141592 ) );
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Declaration" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "template <typename... Types>" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "void print_args_2( Types... args )" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "{" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "( std::cout << ... << args );" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "}" << r2tm::linefeed2;

				PROCESS_MAIN( print_args_2( 1, 2, 3, 4, "template_variadic_test", 3.141592 ) );
				LF();
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Declaration" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "template <typename... Types>" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "void print_args_3( Types... args )" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "{" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "( print( args ), ... );" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "}" << r2tm::linefeed2;

				PROCESS_MAIN( print_args_3( 1, 2, 3, 4, "template_variadic_test", 3.141592 ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
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
namespace template_variadic_test
{
	r2tm::TitleFunctionT SumValues::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Sum Values";
		};
	}
	r2tm::DoFunctionT SumValues::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				std::cout << r2tm::tab << "+ sum_args_with_fold_1( 1, 2, 3, 4, 5, 6, 7, 8, 9 )" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "return ( ... + integer_list )" << r2tm::linefeed;

				const auto sum_result = sum_args_with_fold_1( 1, 2, 3, 4, 5, 6, 7, 8, 9 );

				std::cout << r2tm::tab3 << sum_result << r2tm::linefeed;
			}

			LS();

			{
				std::cout << r2tm::tab << "+ sum_args_with_fold_2( 1, 2, 3, 4, 5, 6, 7, 8, 9 )" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "return ( integer_list + ... )" << r2tm::linefeed;

				const auto sum_result = sum_args_with_fold_2( 1, 2, 3, 4, 5, 6, 7, 8, 9 );

				std::cout << r2tm::tab3 << sum_result << r2tm::linefeed;
			}

			LS();

			{
				std::cout << r2tm::tab << "+ SumArgs<1>::result" << r2tm::linefeed;

				const auto sum_result = SumArgs<1>::result;

				std::cout << r2tm::tab3 << sum_result << r2tm::linefeed;
			}

			LS();

			{
				std::cout << r2tm::tab << "+ SumArgs<1, 2, 3, 4, 5, 6, 7, 8, 9>::result" << r2tm::linefeed;

				const auto sum_result = SumArgs<1, 2, 3, 4, 5, 6, 7, 8, 9>::result;

				std::cout << r2tm::tab3 << sum_result << r2tm::linefeed;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
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
namespace template_variadic_test
{
	r2tm::TitleFunctionT SubtractValues::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Subtract Values";
		};
	}
	r2tm::DoFunctionT SubtractValues::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				std::cout << r2tm::tab << "+ int subtract_args_with_fold_1(IntegerList... integer_list )" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "return ( integer_list - ... );" << r2tm::linefeed;
				LF();

				{
					std::cout << r2tm::tab2 << "Call : subtract_args_with_fold_1( 10, 5 );" << r2tm::linefeed;

					std::cout << r2tm::tab3 << subtract_args_with_fold_1( 10, 5 ) << r2tm::linefeed;
				}

				LF();

				{
					std::cout << r2tm::tab2 << "Call : subtract_args_with_fold_1( 5, 10 );" << r2tm::linefeed;

					std::cout << r2tm::tab3 << subtract_args_with_fold_1( 5, 10 ) << r2tm::linefeed;
				}

				LF();

				{
					std::cout << r2tm::tab2 << "Call : subtract_args_with_fold_1( 100, 1, 2, 3, 4, 5, 6, 7, 8, 9 );" << r2tm::linefeed;

					std::cout << r2tm::tab3 << subtract_args_with_fold_1( 100, 1, 2, 3, 4, 5, 6, 7, 8, 9 ) << r2tm::linefeed;
				}

				LF();

				{
					std::cout << r2tm::tab2 << "Test : ( 100 - ( 1 - ( 2 - ( 3 - ( 4 - ( 5 - ( 6 - ( 7 - ( 8 - 9 ) ) ) ) ) ) ) ) );" << r2tm::linefeed;

					std::cout << r2tm::tab3 << ( 100 - ( 1 - ( 2 - ( 3 - ( 4 - ( 5 - ( 6 - ( 7 - ( 8 - 9 ) ) ) ) ) ) ) ) ) << r2tm::linefeed;
				}
			}

			LS();

			{
				std::cout << r2tm::tab << "+ int subtract_args_with_fold_2(IntegerList... integer_list )" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "return ( ... - integer_list );" << r2tm::linefeed;
				LF();

				{
					std::cout << r2tm::tab2 << "Call : subtract_args_with_fold_2( 100, 1, 2, 3, 4, 5, 6, 7, 8, 9 )" << r2tm::linefeed;

					std::cout << r2tm::tab3 << subtract_args_with_fold_2( 100, 1, 2, 3, 4, 5, 6, 7, 8, 9 ) << r2tm::linefeed;
				}

				LF();

				{
					std::cout << r2tm::tab2 << "Test : ( ( ( ( ( ( ( ( ( 100 - 1 ) - 2 ) - 3 ) - 4 ) - 5 ) - 6 ) - 7 ) - 8 ) - 9 );" << r2tm::linefeed;

					std::cout << r2tm::tab3 << ( ( ( ( ( ( ( ( ( 100 - 1 ) - 2 ) - 3 ) - 4 ) - 5 ) - 6 ) - 7 ) - 8 ) - 9 ) << r2tm::linefeed;
				}
			}

			LS();

			{
				std::cout << r2tm::tab << "+ int subtract_args_with_fold_3( I integer, IntegerList... integer_list )" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "return ( integer_list - ... - integer );" << r2tm::linefeed;
				LF();

				std::cout << r2tm::tab2 << "Call : subtract_args_with_fold_3( 100, 1, 2, 3, 4, 5, 6, 7, 8, 9 )" << r2tm::linefeed;

				std::cout << r2tm::tab3 << subtract_args_with_fold_4( 100, 1, 2, 3, 4, 5, 6, 7, 8, 9 ) << r2tm::linefeed;
			}

			LS();

			{
				std::cout << r2tm::tab << "+ int subtract_args_with_fold_4( I integer, IntegerList... integer_list )" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "return ( integer - ... - integer_list );" << r2tm::linefeed;
				LF();

				std::cout << r2tm::tab2 << "Call : subtract_args_with_fold_4( 100, 1, 2, 3, 4, 5, 6, 7, 8, 9 )" << r2tm::linefeed;

				std::cout << r2tm::tab3 << subtract_args_with_fold_3( 100, 1, 2, 3, 4, 5, 6, 7, 8, 9 ) << r2tm::linefeed;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}



namespace
{
	template<typename RETURN_T, typename ... ARGS_T>
	class VariadicFunctor
	{
	public:
		using F = std::function<RETURN_T(ARGS_T...)>;

		void Add( const F& f )
		{
			f( 1, 2.f, "test" );
		}
	};
}
namespace template_variadic_test
{
	r2tm::TitleFunctionT Test::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Test";
		};
	}
	r2tm::DoFunctionT Test::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				VariadicFunctor<int, int, float, const char*> f;

				class C
				{
				public:
					int Do( int i, float f, const char* s ) const
					{
						OUTPUT_VALUE( i );
						OUTPUT_VALUE( f );
						OUTPUT_VALUE( s );

						return i;
					}
				} c;

				f.Add( [c2 = &c]( int i, float f, const char* s )->int
				{
					return c2->Do( i, f, s );
				} );
			}

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}