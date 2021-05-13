#include "pch.h"
#include "template_practice_part_01_test.h"

#include <algorithm>

#include "r2_eTestResult.h"

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

	r2::iTest::TitleFunc BufferWithTemplate::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Buffer With Template";
		};
	}

	r2::iTest::DoFunc BufferWithTemplate::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				Buffer<64> buffer;
				std::cout << "\t + " << "Buffer<64> buffer" << r2::linefeed;

				std::cout << "\t\t";
				for( const auto c : buffer.b )
				{
					std::cout << c;
				}

				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
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

	r2::iTest::TitleFunc VaridicMax::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Varidic Max";
		};
	}

	r2::iTest::DoFunc VaridicMax::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << "\t + " << "FindMax( 1, 2, 30, 4, 5, 60, 7 )" << r2::linefeed;
				std::cout << "\t\t" "Result : " << FindMax( 1, 2, 30, 4, 5, 60, 7 );
				std::cout << r2::linefeed;
				std::cout << r2::linefeed;

				std::cout << "\t + " << "FindMax( 1, 2, 30 )" << r2::linefeed;
				std::cout << "\t\t" "Result : " << FindMax( 1, 2, 30 );
				std::cout << r2::linefeed;
				std::cout << r2::linefeed;

				std::cout << "\t + " << "FindMax( 1, 2 )" << r2::linefeed;
				std::cout << "\t\t" "Result : " << FindMax( 1, 2 );
				std::cout << r2::linefeed;
				std::cout << r2::linefeed;

				std::cout << "\t + " << "FindMax( 1 )" << r2::linefeed;
				std::cout << "\t\t" "Result : " << FindMax( 1 );
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << "\t + " << "std::max( { 1, 2, 30, 4, 5, 60, 7 } )" << r2::linefeed;
				std::cout << "\t\t" "Result : " << std::max( { 1, 2, 30, 4, 5, 60, 7 } );
				std::cout << r2::linefeed;
				std::cout << r2::linefeed;

				std::cout << "\t + " << "std::max( { 1, 2, 30 } )" << r2::linefeed;
				std::cout << "\t\t" "Result : " << std::max( { 1, 2, 30 } );
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}