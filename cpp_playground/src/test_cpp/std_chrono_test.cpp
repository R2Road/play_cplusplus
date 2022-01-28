#include "pch.h"
#include "std_chrono_test.h"

#include <conio.h>
#include <chrono>

#include "base/r2_eTestResult.h"

namespace std_chrono_test
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
			std::chrono::milliseconds last_time = std::chrono::duration_cast<std::chrono::milliseconds>( std::chrono::steady_clock::now() - steady_start_time_point );

			while( true )
			{
				current_time = std::chrono::duration_cast<std::chrono::milliseconds>( std::chrono::steady_clock::now() - steady_start_time_point );

				if( last_time.count() + 32 < current_time.count() ) // 30fps
				{
					system( "cls" );

					std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed2;
					std::cout << "[ANY KEY] Exit" << r2::linefeed;

					std::cout << r2::split;

					{
						std::cout << r2::tab << "std::chrono::system_clock::now();" << r2::linefeed;
						std::cout << r2::tab2 << ( std::chrono::system_clock::now() - system_start_time_point ).count() << r2::linefeed;
					}

					std::cout << r2::split;

					{
						std::cout << r2::tab << "std::chrono::steady_clock::now();" << r2::linefeed;
						std::cout << r2::tab2 << ( std::chrono::steady_clock::now() - steady_start_time_point ).count() << r2::linefeed;
					}

					std::cout << r2::split;

					{
						const std::chrono::nanoseconds nano = std::chrono::duration_cast<std::chrono::nanoseconds>( std::chrono::steady_clock::now() - steady_start_time_point );

						std::cout << r2::tab << "std::chrono::nanoseconds" << r2::linefeed;
						std::cout << r2::tab2 << "nanoseconds : " << nano.count() << r2::linefeed;
					}

					std::cout << r2::split;

					{
						const std::chrono::microseconds micro = std::chrono::duration_cast<std::chrono::microseconds>( std::chrono::steady_clock::now() - steady_start_time_point );

						std::cout << r2::tab << "std::chrono::microseconds" << r2::linefeed;
						std::cout << r2::tab2 << "microseconds : " << micro.count() << r2::linefeed;
					}

					std::cout << r2::split;

					{
						const std::chrono::milliseconds micro = std::chrono::duration_cast<std::chrono::milliseconds>( std::chrono::steady_clock::now() - steady_start_time_point );

						std::cout << r2::tab << "std::chrono::milliseconds" << r2::linefeed;
						std::cout << r2::tab2 << "milliseconds : " << micro.count() << r2::linefeed;
					}

					std::cout << r2::split;

					{
						const std::chrono::seconds sec = std::chrono::duration_cast<std::chrono::seconds>( std::chrono::steady_clock::now() - steady_start_time_point );

						std::cout << r2::tab << "std::chrono::seconds" << r2::linefeed;
						std::cout << r2::tab2 << "seconds : " << sec.count() << r2::linefeed;
					}

					std::cout << r2::split;

					{
						const std::chrono::minutes min = std::chrono::duration_cast<std::chrono::minutes>( std::chrono::steady_clock::now() - steady_start_time_point );

						std::cout << r2::tab << "std::chrono::minutes" << r2::linefeed;
						std::cout << r2::tab2 << "minutes : " << min.count() << r2::linefeed;
					}

					std::cout << r2::split;

					{
						const std::chrono::hours hour = std::chrono::duration_cast<std::chrono::hours>( std::chrono::steady_clock::now() - steady_start_time_point );

						std::cout << r2::tab << "std::chrono::hours" << r2::linefeed;
						std::cout << r2::tab2 << "hours : " << hour.count() << r2::linefeed;
					}

					std::cout << r2::split;

					{
						std::chrono::duration<double> default_time = std::chrono::system_clock::now() - system_start_time_point;

						std::cout << r2::tab << "std::chrono::duration<double> default_time = std::chrono::system_clock::now() - system_start_time_point;" << r2::linefeed;
						std::cout << r2::tab2 << default_time.count() << r2::linefeed;
					}

					std::cout << r2::split;

					last_time = current_time;
				}

				if( _kbhit() )
				{
					_getch();
					break;
				}
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest_Without_Pause;
		};
	}
}