#include "pch.h"
#include "c_time_test.h"

#include <conio.h>
#include <ctime> // time.h : c // time(), clock()
#include <errno.h>
#include <time.h>

#include <Windows.h>

#include "r2cm/r2cm_constant.h"

namespace c_time_test
{
	r2cm::iItem::TitleFuncT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "C Time : Basic";
		};
	}
	r2cm::iItem::DoFuncT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Process" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "time() : " << time( NULL ) << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				time_t tt;

				std::cout << r2cm::tab << "+ Process" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "time_t tt;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "time( &tt ) : " << time( &tt ) << r2cm::linefeed;
				std::cout << r2cm::tab2 << "tt : " << tt << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT Y_M_D_H_S::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "C Time : Y_M_D_H_S";
		};
	}
	r2cm::iItem::DoFuncT Y_M_D_H_S::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				time_t tt;
				time( &tt );

				struct tm time_infos;
				errno_t er = localtime_s( &time_infos, &tt );
				if( 0 == er )
				{
					std::cout << r2cm::tab << "+ Process" << r2cm::linefeed2;
					std::cout << r2cm::tab2 << "time_t tt;" << r2cm::linefeed;
					std::cout << r2cm::tab2 << "time( &tt );" << r2cm::linefeed2;
					std::cout << r2cm::tab2 << "struct tm time_infos;" << r2cm::linefeed;
					std::cout << r2cm::tab2 << "localtime_s( &time_infos, &tt );" << r2cm::linefeed2;

					std::cout << r2cm::tab2 << time_infos.tm_year + 1900 << r2cm::linefeed;
					std::cout << r2cm::tab2 << time_infos.tm_mon + 1 << r2cm::linefeed;
					std::cout << r2cm::tab2 << time_infos.tm_mday << r2cm::linefeed;
					std::cout << r2cm::tab2 << time_infos.tm_hour << " : " << time_infos.tm_min << " : " << time_infos.tm_sec << r2cm::linefeed;
				}
				else
				{
					std::cout << r2cm::tab << "Failed : localtime_s" << r2cm::linefeed;
				}
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



	r2cm::iItem::TitleFuncT Clock::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "C Time : Clock";
		};
	}
	r2cm::iItem::DoFuncT Clock::GetDoFunction()
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
				SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), { 0, 20 } );

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