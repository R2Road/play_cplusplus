#include "pch.h"
#include "c_time_test.h"

#include <conio.h>
#include <ctime> // time.h : c // time(), clock()
#include <errno.h>
#include <time.h>

#include "base/r2_eTestResult.h"

namespace c_time_test
{
	r2::iTest::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "C Time : Basic";
		};
	}
	r2::iTest::DoFunc Basic::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Process" << r2::linefeed2;
				std::cout << r2::tab2 << "time() : " << time( NULL ) << r2::linefeed;
			}

			std::cout << r2::split;

			{
				time_t tt;

				std::cout << r2::tab << "+ Process" << r2::linefeed2;
				std::cout << r2::tab2 << "time_t tt;" << r2::linefeed;
				std::cout << r2::tab2 << "time( &tt ) : " << time( &tt ) << r2::linefeed;
				std::cout << r2::tab2 << "tt : " << tt << r2::linefeed;
			}

			std::cout << r2::split;

			{
				time_t tt;
				time( &tt );

				struct tm time_infos;
				errno_t er = localtime_s( &time_infos, &tt );
				if( 0 == er )
				{
					std::cout << r2::tab << "+ Process" << r2::linefeed2;
					std::cout << r2::tab2 << "time_t tt;" << r2::linefeed;
					std::cout << r2::tab2 << "time( &tt );" << r2::linefeed2;
					std::cout << r2::tab2 << "struct tm time_infos;" << r2::linefeed;
					std::cout << r2::tab2 << "localtime_s( &time_infos, &tt );" << r2::linefeed2;

					std::cout << r2::tab2 << time_infos.tm_year + 1900 << r2::linefeed;
					std::cout << r2::tab2 << time_infos.tm_mon + 1 << r2::linefeed;
					std::cout << r2::tab2 << time_infos.tm_mday << r2::linefeed;
					std::cout << r2::tab2 << time_infos.tm_hour << " : " << time_infos.tm_min << " : " << time_infos.tm_sec << r2::linefeed;
				}
				else
				{
					std::cout << r2::tab << "Failed : localtime_s" << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				char str[128];
				time_t tt;
				time( &tt );
				ctime_s( str, sizeof( str ), &tt );

				std::cout << r2::tab << "+ Process" << r2::linefeed2;
				std::cout << r2::tab2 << "char str[128];" << r2::linefeed;
				std::cout << r2::tab2 << "time_t tt;" << r2::linefeed;
				std::cout << r2::tab2 << "time( &tt );" << r2::linefeed2;
				std::cout << r2::tab2 << "ctime_s( str, sizeof( str ), &tt ); : " << str;
			}

			std::cout << r2::split;

			{
				char str[128];

				time_t tt;
				time( &tt );

				struct tm time_infos;
				localtime_s( &time_infos, &tt );

				asctime_s( str, sizeof( str ), &time_infos );

				std::cout << r2::tab << "+ Process" << r2::linefeed2;
				std::cout << r2::tab2 << "char str[128];" << r2::linefeed;
				std::cout << r2::tab2 << "time_t tt;" << r2::linefeed;
				std::cout << r2::tab2 << "time( &tt );" << r2::linefeed;
				std::cout << r2::tab2 << "struct tm time_infos;" << r2::linefeed;
				std::cout << r2::tab2 << "localtime_s( &time_infos, &tt );" << r2::linefeed2;

				std::cout << r2::tab2 << "asctime_s( str, sizeof( str ), &time_infos ); : " << str;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc CTime::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "C Time";
		};
	}
	r2::iTest::DoFunc CTime::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			time_t current_time = 0;

			clock_t current_clock = 0;
			clock_t last_clock = 0;
			clock_t current_sec = 0;

			bool process = true;
			while( process )
			{
				time( &current_time );  /* get current time; same as: timer = time(NULL)  */

				current_clock = clock();
				current_sec = current_clock / CLOCKS_PER_SEC;

				if( last_clock + 16 < current_clock ) // 60fps
				{
					system( "cls" );

					std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;
					std::cout << "[ESC] Exit" << r2::linefeed;

					std::cout << r2::split;

					{
						std::cout << r2::tab << "time( &current_time );" << r2::linefeed;
						std::cout << r2::tab2 << current_time << r2::linefeed;
					}

					std::cout << r2::split;

					{
						std::cout << r2::tab << "current_clock = clock();" << r2::linefeed;
						std::cout << r2::tab2 << "clock : " << current_clock << r2::tab2 << "sec : " << current_sec << r2::linefeed;

						last_clock = current_clock;
					}

					std::cout << r2::split;
				}

				if( _kbhit() )
				{
					switch( _getch() )
					{
					case 27: // ESC
						process = false;
						break;
					}
				}
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest_Without_Pause;
		};
	}
}