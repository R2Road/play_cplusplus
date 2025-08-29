#include "play_c_array.hpp"

#include "r2tm/r2tm_color_modifier.hpp"
#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

namespace play_c_array
{
	void print_array( const int length, const int array[] )
	{
		std::cout << r2tm::tab << "Print :";
		for( int i = 0; length > i; ++i )
		{
			std::cout << " " << array[i];
		}
		LF();
	}

	r2tm::TitleFunctionT Init::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "array : Init";
		};
	}
	r2tm::DoFunctionT Init::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECL_MAIN( const int length = 5 );

			LS();

			{
				OUTPUT_SOURCE_READY_N_BEGIN;
				int array[length];
				OUTPUT_SOURCE_END;

				LF();

				print_array( length, array );
			}

			LS();

			{
				OUTPUT_SOURCE_READY_N_BEGIN;
				const int array[length] = { 0 };
				OUTPUT_SOURCE_END;

				LF();

				print_array( length, array );
			}

			LS();

			{
				OUTPUT_SOURCE_READY_N_BEGIN;
				const int array[5] = { 0, };
				OUTPUT_SOURCE_END;

				LF();

				print_array( length, array );
			}

			LS();

			{
				OUTPUT_SOURCE_READY_N_BEGIN;
				const int array[5] = { '\0', };
				OUTPUT_SOURCE_END;

				LF();

				print_array( length, array );
			}

			LS();

			{
				OUTPUT_SOURCE_READY_N_BEGIN;
				const int array[5] = {};
				OUTPUT_SOURCE_END;

				LF();

				print_array( length, array );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Address::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "array : Address";
		};
	}
	r2tm::DoFunctionT Address::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_SUBJECT( "배열은 열 우선으로 메모리가 배치된다." );

			LS();

			{
				DECL_MAIN( const int w = 3 );
				DECL_MAIN( const int h = 2 );
				DECL_MAIN( int a[w][h] = {} );

				SS();

				OUTPUT_VALUE( ( int64_t )a );

				SS();

				for( int x = 0; w > x; ++x )
				{
					for( int y = 0; h > y; ++y )
					{
						std::cout
							<< "   a"
							<< "[" << x << "]"
							<< "[" << y << "]"
							<< "    "
							<< "address : " << ( int64_t )&a[x][y]
							<< "    "
							<< "offset  : " << clm( r2tm::eColor::FG_LightYellow ) << ( ( int64_t )&a[x][y] - ( int64_t )&a ) << clm()
							<< r2tm::linefeed
						;
					}
				}

				SS();

				for( int y = 0; h > y; ++y )
				{
					for( int x = 0; w > x; ++x )
					{
						std::cout
							<< "   a"
							<< "[" << x << "]"
							<< "[" << y << "]"
							<< "    "
							<< "address : " << ( int64_t )&a[x][y]
							<< "    "
							<< "offset  : " << clm( r2tm::eColor::FG_LightYellow ) << ( ( int64_t )&a[x][y] - ( int64_t )&a ) << clm()
							<< r2tm::linefeed
							;
					}
				}
			}

			LS();

			{
				OUTPUT_NOTE( "배열에 접근하는 방식에 따라서" );
				OUTPUT_NOTE( "cache hit 에 유리하도록 선언/접근 방식을 조절하자." );

				LF();

				OUTPUT_CODE( int a[w][h] );
				OUTPUT_CODE( int a[h][w] );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}