#include "pch.h"
#include "time_3_test.h"

#include <conio.h>
#include <chrono>

#include "r2_eTestResult.h"

namespace time_test
{
	r2::iTest::TitleFunc Chrono::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Chrono";
		};
	}
	r2::iTest::DoFunc Chrono::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			const auto system_start_time_point = std::chrono::system_clock::now();
			const auto steady_start_time_point = std::chrono::steady_clock::now();

			std::chrono::milliseconds current_time;
			std::chrono::milliseconds last_time;

			bool process = true;
			while( process )
			{
				current_time = std::chrono::duration_cast<std::chrono::milliseconds>( std::chrono::steady_clock::now() - steady_start_time_point );

				if( last_time.count() + 32 < current_time.count() ) // 30fps
				{
					system( "cls" );

					std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;
					std::cout << "[ESC] Exit" << r2::linefeed;

					std::cout << r2::split;

					{
						std::cout << "\t" << "std::chrono::system_clock::now();" << r2::linefeed;
						std::cout << "\t\t" << ( std::chrono::system_clock::now() - system_start_time_point ).count() << r2::linefeed;
					}

					std::cout << r2::split;

					{
						std::cout << "\t" << "std::chrono::steady_clock::now();" << r2::linefeed;
						std::cout << "\t\t" << ( std::chrono::steady_clock::now() - steady_start_time_point ).count() << r2::linefeed;
					}

					std::cout << r2::split;

					{
						const std::chrono::nanoseconds nano = std::chrono::duration_cast<std::chrono::nanoseconds>( std::chrono::steady_clock::now() - steady_start_time_point );

						std::cout << "\t" << "std::chrono::nanoseconds" << r2::linefeed;
						std::cout << "\t\t" << "nanoseconds : " << nano.count() << r2::linefeed;
					}

					std::cout << r2::split;

					{
						const std::chrono::microseconds micro = std::chrono::duration_cast<std::chrono::microseconds>( std::chrono::steady_clock::now() - steady_start_time_point );

						std::cout << "\t" << "std::chrono::microseconds" << r2::linefeed;
						std::cout << "\t\t" << "microseconds : " << micro.count() << r2::linefeed;
					}

					std::cout << r2::split;

					{
						const std::chrono::seconds sec = std::chrono::duration_cast<std::chrono::seconds>( std::chrono::steady_clock::now() - steady_start_time_point );

						std::cout << "\t" << "std::chrono::seconds" << r2::linefeed;
						std::cout << "\t\t" << "seconds : " << sec.count() << r2::linefeed;
					}

					std::cout << r2::split;

					{
						const std::chrono::minutes min = std::chrono::duration_cast<std::chrono::minutes>( std::chrono::steady_clock::now() - steady_start_time_point );

						std::cout << "\t" << "std::chrono::minutes" << r2::linefeed;
						std::cout << "\t\t" << "minutes : " << min.count() << r2::linefeed;
					}

					std::cout << r2::split;

					{
						const std::chrono::hours hour = std::chrono::duration_cast<std::chrono::hours>( std::chrono::steady_clock::now() - steady_start_time_point );

						std::cout << "\t" << "std::chrono::hours" << r2::linefeed;
						std::cout << "\t\t" << "hours : " << hour.count() << r2::linefeed;
					}

					std::cout << r2::split;

					{
						std::chrono::duration<double> default_time = std::chrono::system_clock::now() - system_start_time_point;

						std::cout << "\t" << "std::chrono::duration<double> default_time = std::chrono::system_clock::now() - system_start_time_point;" << r2::linefeed;
						std::cout << "\t\t" << default_time.count() << r2::linefeed;
					}

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

			return r2::eTestResult::RunTest_Without_Pause;
		};
	}
}