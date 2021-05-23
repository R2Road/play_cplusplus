#include "pch.h"
#include "time_test.h"

#include <conio.h>
#include <ctime> // time.h : c

#include "r2_eTestResult.h"

namespace time_test
{
	r2::iTest::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Time";
		};
	}
	r2::iTest::DoFunc Basic::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			time_t current_time = 0;
			time_t last_time = 0;

			bool process = true;
			while( process )
			{
				time( &current_time );  /* get current time; same as: timer = time(NULL)  */
				if( last_time != current_time )
				{
					system( "cls" );

					std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;
					std::cout << r2::split;
					std::cout << current_time << r2::linefeed;
					std::cout << r2::split;

					last_time = current_time;
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

			return r2::eTestResult::RunTest;
		};
	}
}