#include "c_time_test.h"

#include <conio.h>
#include <ctime> // time.h : c // time(), clock()
#include <errno.h>
#include <time.h>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_WindowUtility.h"

namespace c_time_test
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "C Time : Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				OUTPUT_VALUE( time( NULL ) );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( time_t tt );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( time( &tt ) );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( tt );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Y_M_D_H_M_S_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "C Time : Y_M_D_H_M_S_1";
		};
	}
	r2cm::iItem::DoFunctionT Y_M_D_H_M_S_1::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( time_t tt );
			DECLARATION_MAIN( tm time_infos );
			DECLARATION_MAIN( errno_t er );

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( time( &tt ) );
				PROCESS_MAIN( er = localtime_s( &time_infos, &tt ) );
				EXPECT_EQ( 0, er );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ 연, 월, 일" << r2cm::linefeed2;
				OUTPUT_VALUE( time_infos.tm_year + 1900 );
				OUTPUT_VALUE( time_infos.tm_mon + 1 );
				OUTPUT_VALUE( time_infos.tm_mday );

				std::cout << r2cm::linefeed2;

				std::cout << r2cm::tab << "+ 시, 분, 초" << r2cm::linefeed2;
				OUTPUT_VALUE( time_infos.tm_hour );
				OUTPUT_VALUE( time_infos.tm_min );
				OUTPUT_VALUE( time_infos.tm_sec );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Y_M_D_H_M_S_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "C Time : Y_M_D_H_M_S 2";
		};
	}
	r2cm::iItem::DoFunctionT Y_M_D_H_M_S_2::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( char str[128] );
				DECLARATION_MAIN( time_t tt );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( time( &tt ) );
				PROCESS_MAIN( ctime_s( str, sizeof( str ), &tt ) );

				std::cout << r2cm::linefeed;
				
				OUTPUT_VALUE( str );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( char str[128] );
				DECLARATION_MAIN( time_t tt );
				DECLARATION_MAIN( struct tm time_infos );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( time( &tt ) );
				PROCESS_MAIN( localtime_s( &time_infos, &tt ) );
				PROCESS_MAIN( asctime_s( str, sizeof( str ), &time_infos ) );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( str );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ 만들어진 날짜 정보 문자열의 끝에는 \\n이 추가된다." << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Clock::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "C Time : Clock";
		};
	}
	r2cm::iItem::DoFunctionT Clock::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( clock_t current_clock = 0 );
			DECLARATION_MAIN( clock_t current_sec = 0 );

			std::cout << r2cm::split;

			std::cout << r2cm::tab << "Message : clock() 은 어플리케이션의 실행 시간을 반환한다." << r2cm::linefeed;
			std::cout << r2cm::tab << "Message : clock() Gives Processing Time" << r2cm::linefeed;

			std::cout << r2cm::split;

			std::cout << "[ANY KEY] Exit" << r2cm::linefeed2;

			const auto pivot_point = r2cm::WindowUtility::GetCursorPoint();
			while( true )
			{
				r2cm::WindowUtility::MoveCursorPointWithClearBuffer( pivot_point );

				PROCESS_MAIN( current_clock = clock() );
				PROCESS_MAIN( current_sec = current_clock / CLOCKS_PER_SEC );

				std::cout << r2cm::tab << "current_clock : " << current_clock << r2cm::tab2 << "current_sec : " << current_sec << r2cm::linefeed;

				if( _kbhit() )
				{
					if( _getch() )
					{
						break;
					}
				}
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}