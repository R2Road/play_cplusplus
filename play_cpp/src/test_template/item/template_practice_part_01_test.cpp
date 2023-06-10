#include "template_practice_part_01_test.h"

#include <algorithm>

#include "r2tm/r2tm_ostream.h"

namespace template_practice_part_01_test
{
	template<int N>
	struct Buffer
	{
		Buffer() :
			b()
			, size( N )
		{
			memset( b, 'a', sizeof( b ) );
		}

		char b[N];
		std::size_t size;
	};

	r2tm::TitleFunctionT BufferWithTemplate::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Buffer With Template";
		};
	}
	r2tm::DoFunctionT BufferWithTemplate::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				Buffer<64> buffer;
				std::cout << r2tm::tab << "+ Buffer<64> buffer" << r2tm::linefeed;

				std::cout << r2tm::tab2;
				for( const auto c : buffer.b )
				{
					std::cout << c;
				}

				LF();
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}

namespace template_practice_part_01_test
{
	//template<typename... Types>
	//class FindMax;

	template <typename T>
	T FindMax( T arg1 ) {
		return arg1;
	}

	template <typename T>
	T FindMax( T arg1, T arg2 ) {
		return std::max( arg1, arg2 );
	}

	template<typename T, typename... Types>
	T FindMax( T arg1, T arg2, Types... args )
	{
		return FindMax( FindMax( arg1, arg2 ), args... );
	};

	r2tm::TitleFunctionT VaridicMax::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Varidic Max";
		};
	}
	r2tm::DoFunctionT VaridicMax::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				std::cout << r2tm::tab << "+ FindMax( 1, 2, 30, 4, 5, 60, 7 )" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "Result : " << FindMax( 1, 2, 30, 4, 5, 60, 7 );
				LF();
				LF();

				std::cout << r2tm::tab << "+ FindMax( 1, 2, 30 )" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "Result : " << FindMax( 1, 2, 30 );
				LF();
				LF();

				std::cout << r2tm::tab << "+ FindMax( 1, 2 )" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "Result : " << FindMax( 1, 2 );
				LF();
				LF();

				std::cout << r2tm::tab << "+ FindMax( 1 )" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "Result : " << FindMax( 1 );
				LF();
			}

			LS();

			{
				std::cout << r2tm::tab << "+ std::max( { 1, 2, 30, 4, 5, 60, 7 } )" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "Result : " << std::max( { 1, 2, 30, 4, 5, 60, 7 } );
				LF();
				LF();

				std::cout << r2tm::tab << "std::max( { 1, 2, 30 } )" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "Result : " << std::max( { 1, 2, 30 } );
				LF();
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}