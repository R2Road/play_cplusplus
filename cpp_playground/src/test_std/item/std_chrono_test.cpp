#include "std_chrono_test.h"

#include <conio.h>
#include <chrono>
#include <ctime> // time.h : c // time(), clock()

#include "r2cm/r2cm_constant.h"

namespace std_chrono_test
{
	r2cm::iItem::TitleFunctionT Epoch::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Epoch";
		};
	}
	r2cm::iItem::DoFunctionT Epoch::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			// REF : https://en.cppreference.com/w/cpp/chrono/time_point/time_since_epoch

			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			char str[128];

			const auto sc_default = std::chrono::time_point<std::chrono::system_clock>{};
			const auto sc_now = std::chrono::system_clock::now();

			{
				std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "const auto sc_default = std::chrono::time_point<std::chrono::system_clock>{};" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "const auto sc_now = std::chrono::system_clock::now();" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Process : Epoch" << r2cm::linefeed2;

				auto epoch_time = std::chrono::system_clock::to_time_t( sc_default );
				ctime_s( str, sizeof( str ), &epoch_time );

				std::cout << r2cm::tab2 << "auto epoch_time = std::chrono::system_clock::to_time_t( sc_default );" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "ctime_s( str, sizeof( str ), &epoch_time );" << r2cm::linefeed3;
				std::cout << r2cm::tab << "## epoch: " << str;

				std::cout << r2cm::linefeed;
				std::cout << r2cm::tab << "시간의 시작점" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Process : Today" << r2cm::linefeed2;

				auto today_time = std::chrono::system_clock::to_time_t( sc_now );
				ctime_s( str, sizeof( str ), &today_time );

				std::cout << r2cm::tab2 << "auto today_time = std::chrono::system_clock::to_time_t( sc_now );" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "ctime_s( str, sizeof( str ), &today_time );" << r2cm::linefeed3;
				std::cout << r2cm::tab << "## today: " << str;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Chrono::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Chrono";
		};
	}
	r2cm::iItem::DoFunctionT Chrono::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
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

					std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed2;
					std::cout << "[ANY KEY] Exit" << r2cm::linefeed;

					std::cout << r2cm::split;

					{
						std::cout << r2cm::tab << "std::chrono::system_clock::now();" << r2cm::linefeed;
						std::cout << r2cm::tab2 << ( std::chrono::system_clock::now() - system_start_time_point ).count() << r2cm::linefeed;
					}

					std::cout << r2cm::split;

					{
						std::cout << r2cm::tab << "std::chrono::steady_clock::now();" << r2cm::linefeed;
						std::cout << r2cm::tab2 << ( std::chrono::steady_clock::now() - steady_start_time_point ).count() << r2cm::linefeed;
					}

					std::cout << r2cm::split;

					{
						const std::chrono::nanoseconds nano = std::chrono::duration_cast<std::chrono::nanoseconds>( std::chrono::steady_clock::now() - steady_start_time_point );

						std::cout << r2cm::tab << "std::chrono::nanoseconds" << r2cm::linefeed;
						std::cout << r2cm::tab2 << "nanoseconds : " << nano.count() << r2cm::linefeed;
					}

					std::cout << r2cm::split;

					{
						const std::chrono::microseconds micro = std::chrono::duration_cast<std::chrono::microseconds>( std::chrono::steady_clock::now() - steady_start_time_point );

						std::cout << r2cm::tab << "std::chrono::microseconds" << r2cm::linefeed;
						std::cout << r2cm::tab2 << "microseconds : " << micro.count() << r2cm::linefeed;
					}

					std::cout << r2cm::split;

					{
						const std::chrono::milliseconds micro = std::chrono::duration_cast<std::chrono::milliseconds>( std::chrono::steady_clock::now() - steady_start_time_point );

						std::cout << r2cm::tab << "std::chrono::milliseconds" << r2cm::linefeed;
						std::cout << r2cm::tab2 << "milliseconds : " << micro.count() << r2cm::linefeed;
					}

					std::cout << r2cm::split;

					{
						const std::chrono::seconds sec = std::chrono::duration_cast<std::chrono::seconds>( std::chrono::steady_clock::now() - steady_start_time_point );

						std::cout << r2cm::tab << "std::chrono::seconds" << r2cm::linefeed;
						std::cout << r2cm::tab2 << "seconds : " << sec.count() << r2cm::linefeed;
					}

					std::cout << r2cm::split;

					{
						const std::chrono::minutes min = std::chrono::duration_cast<std::chrono::minutes>( std::chrono::steady_clock::now() - steady_start_time_point );

						std::cout << r2cm::tab << "std::chrono::minutes" << r2cm::linefeed;
						std::cout << r2cm::tab2 << "minutes : " << min.count() << r2cm::linefeed;
					}

					std::cout << r2cm::split;

					{
						const std::chrono::hours hour = std::chrono::duration_cast<std::chrono::hours>( std::chrono::steady_clock::now() - steady_start_time_point );

						std::cout << r2cm::tab << "std::chrono::hours" << r2cm::linefeed;
						std::cout << r2cm::tab2 << "hours : " << hour.count() << r2cm::linefeed;
					}

					std::cout << r2cm::split;

					{
						std::chrono::duration<double> default_time = std::chrono::system_clock::now() - system_start_time_point;

						std::cout << r2cm::tab << "std::chrono::duration<double> default_time = std::chrono::system_clock::now() - system_start_time_point;" << r2cm::linefeed;
						std::cout << r2cm::tab2 << default_time.count() << r2cm::linefeed;
					}

					std::cout << r2cm::split;

					last_time = current_time;
				}

				if( _kbhit() )
				{
					_getch();
					break;
				}
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::None;
		};
	}
}