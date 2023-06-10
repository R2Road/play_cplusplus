#include "std_chrono_test.h"

#include <conio.h>
#include <chrono>
#include <ctime> // time.h : c // time(), clock()

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_WindowUtility.h"

namespace std_chrono_test
{
	r2tm::TitleFunctionT Epoch::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Epoch";
		};
	}
	r2tm::DoFunctionT Epoch::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			std::cout << r2tm::tab << "REF : https://en.cppreference.com/w/cpp/chrono/time_point/time_since_epoch" << r2tm::linefeed2;
			std::cout << r2tm::tab << "# Summury #" << r2tm::linefeed;
			std::cout << r2tm::tab << "���н� �ð�( ����: Unix time )�� �ð��� ��Ÿ���� ����̴�." << r2tm::linefeed;
			std::cout << r2tm::tab << "POSIX �ð��̳� Epoch �ð��̶�� �θ��⵵ �Ѵ�." << r2tm::linefeed;
			std::cout << r2tm::tab << "1970�� 1�� 1�� 00:00 : 00 ���� �����( UTC ) ������ ��� �ð��� �ʷ� ȯ���Ͽ� ������ ��Ÿ�� ���̴�" << r2tm::linefeed;

			LS();

			DECLARATION_SUB( char str[128] );

			LS();

			{
				std::cout << r2tm::tab << "+ Epoch( �ð��� ������ )" << r2tm::linefeed2;

				DECLARATION_MAIN( const auto sc_default = std::chrono::time_point<std::chrono::system_clock>{} );
				DECLARATION_MAIN( auto epoch_time = std::chrono::system_clock::to_time_t( sc_default ) );
				PROCESS_MAIN( ctime_s( str, sizeof( str ), &epoch_time ) );

				LF();

				OUTPUT_VALUE( str );
				
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT SystemClock::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Chrono : SystemClock";
		};
	}
	r2tm::DoFunctionT SystemClock::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			std::cout << r2tm::tab << "# Summury #" << r2tm::linefeed;
			std::cout << r2tm::tab << "> " << "std::chrono::system_clock �� �ý��� �ð��̴�." << r2tm::linefeed;
			std::cout << r2tm::tab << "> " << "epoch ���� ����� �ð��� ��ȯ�Ѵ�." << r2tm::linefeed;
			std::cout << r2tm::tab << "> " << "��Ʈ��ũ ����ȭ �� �� �ִ�." << r2tm::linefeed;
			std::cout << r2tm::tab << "> " << "OS�� �ð� ���� �����ϸ� �ٲ� �� �ִ�." << r2tm::linefeed;

			LS();

			DECLARATION_MAIN( std::chrono::system_clock::time_point tp = std::chrono::system_clock::now() );

			LS();

			{
				DECLARATION_MAIN( char str[128] );
				DECLARATION_MAIN( auto today_time = std::chrono::system_clock::to_time_t( tp ) );
				PROCESS_MAIN( ctime_s( str, sizeof( str ), &today_time ) );
				OUTPUT_VALUE( str );
			}

			LS();

			{
				OUTPUT_VALUE( std::chrono::system_clock::to_time_t( tp ) );

				LF();

				OUTPUT_VALUE( std::chrono::duration_cast<std::chrono::hours>( tp.time_since_epoch() ).count() );

				LF();

				OUTPUT_VALUE( std::chrono::duration_cast<std::chrono::minutes>( tp.time_since_epoch() ).count() );

				LF();

				OUTPUT_VALUE( std::chrono::duration_cast<std::chrono::seconds>( tp.time_since_epoch() ).count() );

				LF();

				OUTPUT_VALUE( std::chrono::duration_cast<std::chrono::milliseconds>( tp.time_since_epoch() ).count() );

				LF();

				OUTPUT_VALUE( std::chrono::duration_cast<std::chrono::nanoseconds>( tp.time_since_epoch() ).count() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT SteadyClock::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Chrono : SteadyClock";
		};
	}
	r2tm::DoFunctionT SteadyClock::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			std::cout << r2tm::tab << "# Summury #" << r2tm::linefeed;
			std::cout << r2tm::tab << "> " << "std::chrono::steady_clock �� �� ����� ���� �ð��̴�." << r2tm::linefeed;
			std::cout << r2tm::tab << "> " << "OS �� ���õ� ���� ����� �ð��� ��ȯ�Ѵ�." << r2tm::linefeed;
			std::cout << r2tm::tab << "> " << "��Ʈ��ũ ����ȭ ���� �ʴ´�." << r2tm::linefeed;

			LS();

			DECLARATION_MAIN( std::chrono::steady_clock::time_point tp = std::chrono::steady_clock::now() );

			LS();

			{
				OUTPUT_VALUE( std::chrono::duration_cast<std::chrono::hours>( tp.time_since_epoch() ).count() );

				LF();

				OUTPUT_VALUE( std::chrono::duration_cast<std::chrono::minutes>( tp.time_since_epoch() ).count() );

				LF();

				OUTPUT_VALUE( std::chrono::duration_cast<std::chrono::seconds>( tp.time_since_epoch() ).count() );

				LF();

				OUTPUT_VALUE( std::chrono::duration_cast<std::chrono::milliseconds>( tp.time_since_epoch() ).count() );

				LF();

				OUTPUT_VALUE( std::chrono::duration_cast<std::chrono::nanoseconds>( tp.time_since_epoch() ).count() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT SteadyClock_Duration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Chrono : SteadyClock :Duration";
		};
	}
	r2tm::DoFunctionT SteadyClock_Duration::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				DECLARATION_MAIN( const std::chrono::steady_clock::duration d( 30000000 ) );
				OUTPUT_VALUE( d.count() );
			}

			LS();

			DECLARATION_MAIN( const std::chrono::steady_clock::duration d( std::chrono::nanoseconds( 30000000 ) ) );
			OUTPUT_VALUE( d.count() );

			LF();

			{
				DECLARATION_MAIN( const auto nns = std::chrono::duration_cast<std::chrono::nanoseconds>( d ) );
				OUTPUT_VALUE( nns.count() );

				LF();

				DECLARATION_MAIN( const auto mcs = std::chrono::duration_cast<std::chrono::microseconds>( d ) );
				OUTPUT_VALUE( mcs.count() );

				LF();

				DECLARATION_MAIN( const auto ms = std::chrono::duration_cast<std::chrono::milliseconds>( d ) );
				OUTPUT_VALUE( ms.count() );

				LF();

				DECLARATION_MAIN( const auto sec = std::chrono::duration_cast<std::chrono::seconds>( d ) );
				OUTPUT_VALUE( sec.count() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Demo::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Chrono : Demo";
		};
	}
	r2tm::DoFunctionT Demo::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			const auto system_start_time_point = std::chrono::system_clock::now();
			const auto steady_start_time_point = std::chrono::steady_clock::now();

			std::chrono::milliseconds current_time;
			std::chrono::milliseconds last_time = std::chrono::duration_cast<std::chrono::milliseconds>( std::chrono::steady_clock::now() - steady_start_time_point );

			const auto pivot_point = r2tm::WindowUtility::GetCursorPoint();
			while( true )
			{
				current_time = std::chrono::duration_cast<std::chrono::milliseconds>( std::chrono::steady_clock::now() - steady_start_time_point );

				if( last_time.count() + 32 < current_time.count() ) // 30fps
				{
					r2tm::WindowUtility::MoveCursorPointWithClearBuffer( pivot_point );

					LS();

					{
						std::cout << r2tm::tab << "std::chrono::system_clock::now();" << r2tm::linefeed;
						std::cout << r2tm::tab2 << ( std::chrono::system_clock::now() - system_start_time_point ).count() << r2tm::linefeed;
					}

					LS();

					{
						std::cout << r2tm::tab << "std::chrono::steady_clock::now();" << r2tm::linefeed;
						std::cout << r2tm::tab2 << ( std::chrono::steady_clock::now() - steady_start_time_point ).count() << r2tm::linefeed;
					}

					LS();

					{
						const std::chrono::nanoseconds nano = std::chrono::duration_cast<std::chrono::nanoseconds>( std::chrono::steady_clock::now() - steady_start_time_point );

						std::cout << r2tm::tab << "std::chrono::nanoseconds" << r2tm::linefeed;
						std::cout << r2tm::tab2 << "nanoseconds : " << nano.count() << r2tm::linefeed;
					}

					LS();

					{
						const std::chrono::microseconds micro = std::chrono::duration_cast<std::chrono::microseconds>( std::chrono::steady_clock::now() - steady_start_time_point );

						std::cout << r2tm::tab << "std::chrono::microseconds" << r2tm::linefeed;
						std::cout << r2tm::tab2 << "microseconds : " << micro.count() << r2tm::linefeed;
					}

					LS();

					{
						const std::chrono::milliseconds micro = std::chrono::duration_cast<std::chrono::milliseconds>( std::chrono::steady_clock::now() - steady_start_time_point );

						std::cout << r2tm::tab << "std::chrono::milliseconds" << r2tm::linefeed;
						std::cout << r2tm::tab2 << "milliseconds : " << micro.count() << r2tm::linefeed;
					}

					LS();

					{
						const std::chrono::seconds sec = std::chrono::duration_cast<std::chrono::seconds>( std::chrono::steady_clock::now() - steady_start_time_point );

						std::cout << r2tm::tab << "std::chrono::seconds" << r2tm::linefeed;
						std::cout << r2tm::tab2 << "seconds : " << sec.count() << r2tm::linefeed;
					}

					LS();

					{
						const std::chrono::minutes min = std::chrono::duration_cast<std::chrono::minutes>( std::chrono::steady_clock::now() - steady_start_time_point );

						std::cout << r2tm::tab << "std::chrono::minutes" << r2tm::linefeed;
						std::cout << r2tm::tab2 << "minutes : " << min.count() << r2tm::linefeed;
					}

					LS();

					{
						const std::chrono::hours hour = std::chrono::duration_cast<std::chrono::hours>( std::chrono::steady_clock::now() - steady_start_time_point );

						std::cout << r2tm::tab << "std::chrono::hours" << r2tm::linefeed;
						std::cout << r2tm::tab2 << "hours : " << hour.count() << r2tm::linefeed;
					}

					LS();

					{
						std::chrono::duration<double> default_time = std::chrono::system_clock::now() - system_start_time_point;

						std::cout << r2tm::tab << "std::chrono::duration<double> default_time = std::chrono::system_clock::now() - system_start_time_point;" << r2tm::linefeed;
						std::cout << r2tm::tab2 << default_time.count() << r2tm::linefeed;
					}

					LS();

					last_time = current_time;
				}

				if( _kbhit() )
				{
					_getch();
					break;
				}
			}

			LS();

			return r2tm::eDoLeaveAction::None;
		};
	}
}