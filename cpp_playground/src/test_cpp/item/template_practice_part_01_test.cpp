#include "template_practice_part_01_test.h"

#include <algorithm>

#include "r2cm/r2cm_constant.h"

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

	r2cm::iItem::TitleFuncT BufferWithTemplate::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Buffer With Template";
		};
	}
	r2cm::iItem::DoFuncT BufferWithTemplate::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				Buffer<64> buffer;
				std::cout << r2cm::tab << "+ Buffer<64> buffer" << r2cm::linefeed;

				std::cout << r2cm::tab2;
				for( const auto c : buffer.b )
				{
					std::cout << c;
				}

				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
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

	r2cm::iItem::TitleFuncT VaridicMax::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Varidic Max";
		};
	}
	r2cm::iItem::DoFuncT VaridicMax::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ FindMax( 1, 2, 30, 4, 5, 60, 7 )" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "Result : " << FindMax( 1, 2, 30, 4, 5, 60, 7 );
				std::cout << r2cm::linefeed;
				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "+ FindMax( 1, 2, 30 )" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "Result : " << FindMax( 1, 2, 30 );
				std::cout << r2cm::linefeed;
				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "+ FindMax( 1, 2 )" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "Result : " << FindMax( 1, 2 );
				std::cout << r2cm::linefeed;
				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "+ FindMax( 1 )" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "Result : " << FindMax( 1 );
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ std::max( { 1, 2, 30, 4, 5, 60, 7 } )" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "Result : " << std::max( { 1, 2, 30, 4, 5, 60, 7 } );
				std::cout << r2cm::linefeed;
				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "std::max( { 1, 2, 30 } )" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "Result : " << std::max( { 1, 2, 30 } );
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}