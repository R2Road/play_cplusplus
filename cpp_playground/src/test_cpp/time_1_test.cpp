#include "../pch.h"
#include "time_1_test.h"

#include <conio.h>
#include <ctime> // time.h : c // time(), clock()

#include "base/r2_eTestResult.h"

namespace time_test
{
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
						std::cout << "\t" << "time( &current_time );" << r2::linefeed;
						std::cout << "\t\t" << current_time << r2::linefeed;
					}

					std::cout << r2::split;

					{
						std::cout << "\t" << "current_clock = clock();" << r2::linefeed;
						std::cout << "\t\t" << "clock : " << current_clock << "\t\t" "sec : " << current_sec << r2::linefeed;

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