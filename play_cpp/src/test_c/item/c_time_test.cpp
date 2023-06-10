#include "c_time_test.h"

#include <conio.h>
#include <ctime> // time.h : c // time(), clock()
#include <errno.h>
#include <time.h>

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_WindowUtility.h"

namespace c_time_test
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "C Time : Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_VALUE( time( NULL ) );
			}

			LS();

			{
				DECLARATION_MAIN( time_t tt );

				LF();

				OUTPUT_VALUE( time( &tt ) );

				LF();

				OUTPUT_VALUE( tt );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Y_M_D_H_M_S_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "C Time : Y_M_D_H_M_S_1";
		};
	}
	r2tm::DoFunctionT Y_M_D_H_M_S_1::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( time_t tt );
			DECLARATION_MAIN( tm time_infos );
			DECLARATION_MAIN( errno_t er );

			LS();

			{
				PROCESS_MAIN( time( &tt ) );
				PROCESS_MAIN( er = localtime_s( &time_infos, &tt ) );
				EXPECT_EQ( 0, er );
			}

			LS();

			{
				std::cout << r2tm::tab << "+ 연, 월, 일" << r2tm::linefeed2;
				OUTPUT_VALUE( time_infos.tm_year + 1900 );
				OUTPUT_VALUE( time_infos.tm_mon + 1 );
				OUTPUT_VALUE( time_infos.tm_mday );

				std::cout << r2tm::linefeed2;

				std::cout << r2tm::tab << "+ 시, 분, 초" << r2tm::linefeed2;
				OUTPUT_VALUE( time_infos.tm_hour );
				OUTPUT_VALUE( time_infos.tm_min );
				OUTPUT_VALUE( time_infos.tm_sec );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Y_M_D_H_M_S_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "C Time : Y_M_D_H_M_S 2";
		};
	}
	r2tm::DoFunctionT Y_M_D_H_M_S_2::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				DECLARATION_MAIN( char str[128] );
				DECLARATION_MAIN( time_t tt );

				LF();

				PROCESS_MAIN( time( &tt ) );
				PROCESS_MAIN( ctime_s( str, sizeof( str ), &tt ) );

				LF();
				
				OUTPUT_VALUE( str );
			}

			LS();

			{
				DECLARATION_MAIN( char str[128] );
				DECLARATION_MAIN( time_t tt );
				DECLARATION_MAIN( struct tm time_infos );

				LF();

				PROCESS_MAIN( time( &tt ) );
				PROCESS_MAIN( localtime_s( &time_infos, &tt ) );
				PROCESS_MAIN( asctime_s( str, sizeof( str ), &time_infos ) );

				LF();

				OUTPUT_VALUE( str );
			}

			LS();

			{
				std::cout << r2tm::tab << "+ 만들어진 날짜 정보 문자열의 끝에는 \\n이 추가된다." << r2tm::linefeed;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Clock::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "C Time : Clock";
		};
	}
	r2tm::DoFunctionT Clock::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( clock_t current_clock = 0 );
			DECLARATION_MAIN( clock_t current_sec = 0 );

			LS();

			std::cout << r2tm::tab << "Message : clock() 은 어플리케이션의 실행 시간을 반환한다." << r2tm::linefeed;
			std::cout << r2tm::tab << "Message : clock() Gives Processing Time" << r2tm::linefeed;

			LS();

			std::cout << "[ANY KEY] Exit" << r2tm::linefeed2;

			const auto pivot_point = r2tm::WindowUtility::GetCursorPoint();
			while( true )
			{
				r2tm::WindowUtility::MoveCursorPointWithClearBuffer( pivot_point );

				PROCESS_MAIN( current_clock = clock() );
				PROCESS_MAIN( current_sec = current_clock / CLOCKS_PER_SEC );

				std::cout << r2tm::tab << "current_clock : " << current_clock << r2tm::tab2 << "current_sec : " << current_sec << r2tm::linefeed;

				if( _kbhit() )
				{
					if( _getch() )
					{
						break;
					}
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}