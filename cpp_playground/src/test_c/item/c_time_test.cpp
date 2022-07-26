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
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

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



	r2cm::iItem::TitleFunctionT Y_M_D_H_S::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "C Time : Y_M_D_H_S";
		};
	}
	r2cm::iItem::DoFunctionT Y_M_D_H_S::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

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

			{
				char str[128];
				time_t tt;
				time( &tt );
				ctime_s( str, sizeof( str ), &tt );

				std::cout << r2cm::tab << "+ Process" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "char str[128];" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "time_t tt;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "time( &tt );" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "ctime_s( str, sizeof( str ), &tt ); : " << str;
			}

			std::cout << r2cm::split;

			{
				char str[128];

				time_t tt;
				time( &tt );

				struct tm time_infos;
				localtime_s( &time_infos, &tt );

				asctime_s( str, sizeof( str ), &time_infos );

				std::cout << r2cm::tab << "+ Process" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "char str[128];" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "time_t tt;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "time( &tt );" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "struct tm time_infos;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "localtime_s( &time_infos, &tt );" << r2cm::linefeed2;

				std::cout << r2cm::tab2 << "asctime_s( str, sizeof( str ), &time_infos ); : " << str;
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
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed2;
			std::cout << "[ANY KEY] Exit" << r2cm::linefeed;

			std::cout << r2cm::split;

			clock_t current_clock = 0;
			clock_t current_sec = 0;

			std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
			std::cout << r2cm::tab2 << "clock_t current_clock = 0;" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "clock_t current_sec = 0;" << r2cm::linefeed;

			std::cout << r2cm::split;

			std::cout << r2cm::tab << "+ Process" << r2cm::linefeed2;
			std::cout << r2cm::tab2 << "current_clock = clock();" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "current_sec = current_clock / CLOCKS_PER_SEC;" << r2cm::linefeed;

			std::cout << r2cm::split;

			std::cout << r2cm::linefeed;
			std::cout << r2cm::split;

			std::cout << r2cm::tab << "Message : clock() Gives Processing Time" << r2cm::linefeed;

			while( true )
			{
				r2cm::WindowUtility::MoveCursorPoint( { 0, 20 } );

				current_clock = clock();
				current_sec = current_clock / CLOCKS_PER_SEC;

				std::cout << r2cm::tab << "current_clock : " << current_clock << r2cm::tab2 << "current_sec : " << current_sec;

				if( _kbhit() )
				{
					if( _getch() )
					{
						break;
					}
				}
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::None;
		};
	}
}