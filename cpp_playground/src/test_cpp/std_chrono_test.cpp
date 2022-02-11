#include "pch.h"
#include "std_chrono_test.h"

#include <conio.h>
#include <chrono>
#include <ctime> // time.h : c // time(), clock()

#include "base/r2_eTestResult.h"

namespace std_chrono_test
{
	r2::iTest::TitleFunc Epoch::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Epoch";
		};
	}
	r2::iTest::DoFunc Epoch::GetDoFunction()
	{
		return []()->r2::eTestEndAction
		{
			// REF : https://en.cppreference.com/w/cpp/chrono/time_point/time_since_epoch

			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			char str[128];

			const auto sc_default = std::chrono::time_point<std::chrono::system_clock>{};
			const auto sc_now = std::chrono::system_clock::now();

			{
				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "const auto sc_default = std::chrono::time_point<std::chrono::system_clock>{};" << r2::linefeed;
				std::cout << r2::tab2 << "const auto sc_now = std::chrono::system_clock::now();" << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Process : Epoch" << r2::linefeed2;

				auto epoch_time = std::chrono::system_clock::to_time_t( sc_default );
				ctime_s( str, sizeof( str ), &epoch_time );

				std::cout << r2::tab2 << "auto epoch_time = std::chrono::system_clock::to_time_t( sc_default );" << r2::linefeed;
				std::cout << r2::tab2 << "ctime_s( str, sizeof( str ), &epoch_time );" << r2::linefeed3;
				std::cout << r2::tab << "## epoch: " << str;

				std::cout << r2::linefeed;
				std::cout << r2::tab << "시간의 시작점" << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Process : Today" << r2::linefeed2;

				auto today_time = std::chrono::system_clock::to_time_t( sc_now );
				ctime_s( str, sizeof( str ), &today_time );

				std::cout << r2::tab2 << "auto today_time = std::chrono::system_clock::to_time_t( sc_now );" << r2::linefeed;
				std::cout << r2::tab2 << "ctime_s( str, sizeof( str ), &today_time );" << r2::linefeed3;
				std::cout << r2::tab << "## today: " << str;
			}

			std::cout << r2::split;

			return r2::eTestEndAction::Pause;
		};
	}



	r2::iTest::TitleFunc Chrono::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Chrono";
		};
	}
	r2::iTest::DoFunc Chrono::GetDoFunction()
	{
		return []()->r2::eTestEndAction
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

			return r2::eTestEndAction::None;
		};
	}
}