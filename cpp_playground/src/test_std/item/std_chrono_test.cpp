#include "std_chrono_test.h"

#include <conio.h>
#include <chrono>
#include <ctime> // time.h : c // time(), clock()

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_WindowUtility.h"

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
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			std::cout << r2cm::tab << "REF : https://en.cppreference.com/w/cpp/chrono/time_point/time_since_epoch" << r2cm::linefeed2;
			std::cout << r2cm::tab << "# Summury #" << r2cm::linefeed;
			std::cout << r2cm::tab << "유닉스 시간( 영어: Unix time )은 시각을 나타내는 방식이다." << r2cm::linefeed;
			std::cout << r2cm::tab << "POSIX 시간이나 Epoch 시간이라고 부르기도 한다." << r2cm::linefeed;
			std::cout << r2cm::tab << "1970년 1월 1일 00:00 : 00 협정 세계시( UTC ) 부터의 경과 시간을 초로 환산하여 정수로 나타낸 것이다" << r2cm::linefeed;

			std::cout << r2cm::split;

			DECLARATION_MAIN( char str[128] );

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Epoch( 시간의 시작점 )" << r2cm::linefeed2;

				DECLARATION_MAIN( const auto sc_default = std::chrono::time_point<std::chrono::system_clock>{} );
				DECLARATION_MAIN( auto epoch_time = std::chrono::system_clock::to_time_t( sc_default ) );
				PROCESS_MAIN( ctime_s( str, sizeof( str ), &epoch_time ) );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( str );
				
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Today" << r2cm::linefeed2;

				DECLARATION_MAIN( const auto sc_now = std::chrono::system_clock::now() );
				DECLARATION_MAIN( auto today_time = std::chrono::system_clock::to_time_t( sc_now ) );
				PROCESS_MAIN( ctime_s( str, sizeof( str ), &today_time ) );

				OUTPUT_VALUE( str );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT SteadyClock::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Chrono : SteadyClock";
		};
	}
	r2cm::iItem::DoFunctionT SteadyClock::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			std::cout << r2cm::tab << "# Summury #" << r2cm::linefeed;
			std::cout << r2cm::tab << "> " << "std::chrono::steady_clock 은 시스템의 시간이다." << r2cm::linefeed;
			std::cout << r2cm::tab << "> " << "OS 가 부팅된 이후 경과한 시간을 반환한다." << r2cm::linefeed;
			std::cout << r2cm::tab << "> " << "네트워크 동기화 되지 않는다." << r2cm::linefeed;

			std::cout << r2cm::split;


			{
				DECLARATION_MAIN( std::chrono::steady_clock::time_point tp = std::chrono::steady_clock::now() );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( std::chrono::duration_cast<std::chrono::hours>( tp.time_since_epoch() ).count() );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( std::chrono::duration_cast<std::chrono::minutes>( tp.time_since_epoch() ).count() );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( std::chrono::duration_cast<std::chrono::seconds>( tp.time_since_epoch() ).count() );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( std::chrono::duration_cast<std::chrono::milliseconds>( tp.time_since_epoch() ).count() );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( std::chrono::duration_cast<std::chrono::nanoseconds>( tp.time_since_epoch() ).count() );
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

			const auto pivot_point = r2cm::WindowUtility::GetCursorPoint();
			while( true )
			{
				current_time = std::chrono::duration_cast<std::chrono::milliseconds>( std::chrono::steady_clock::now() - steady_start_time_point );

				if( last_time.count() + 32 < current_time.count() ) // 30fps
				{
					r2cm::WindowUtility::MoveCursorPointWithClearBuffer( pivot_point );

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



	r2cm::iItem::TitleFunctionT TimePoint::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "TimePoint";
		};
	}
	r2cm::iItem::DoFunctionT TimePoint::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( std::chrono::steady_clock::time_point tp );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( auto sec = std::chrono::time_point_cast<std::chrono::seconds>( tp ) );
				OUTPUT_VALUE( sec.time_since_epoch().count() );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( auto min = std::chrono::time_point_cast<std::chrono::minutes>( tp ) );
				OUTPUT_VALUE( min.time_since_epoch().count() );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( std::chrono::steady_clock::time_point tp = std::chrono::steady_clock::now() );
				
				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( auto sec = std::chrono::time_point_cast<std::chrono::seconds>( tp ) );
				OUTPUT_VALUE( sec.time_since_epoch().count() );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( auto min = std::chrono::time_point_cast<std::chrono::minutes>( tp ) );
				OUTPUT_VALUE( min.time_since_epoch().count() );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( auto hr = std::chrono::time_point_cast<std::chrono::hours>( tp ) );
				OUTPUT_VALUE( hr.time_since_epoch().count() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}