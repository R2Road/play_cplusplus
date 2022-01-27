#include "pch.h"
#include "c_random_test.h"

#include <cstdlib> // rand, srand
#include <ctime>
#include <errno.h>
#include <time.h>

#include "base/r2_eTestResult.h"


namespace c_random_test
{
	r2::iTest::TitleFunc Rand::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "C Rand : Basic";
		};
	}
	r2::iTest::DoFunc Rand::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Process" << r2::linefeed2;

				for( int i = 0; 10 > i; ++i )
				{
					std::cout << r2::tab2 << "rand() : " << rand() << r2::linefeed;
				}

				std::cout << r2::linefeed;
				std::cout << r2::tab << "# Message : Same Value Printed When Every Single Execute" << r2::linefeed;
				std::cout << r2::tab << "# Message : 프로그램 새로 기동해도 rand() 가 반환하는 값과 순서는 같다." << r2::linefeed;
			}

			std::cout << r2::split;

			{
				srand( 1 );

				std::cout << r2::tab << "+ Process" << r2::linefeed2;
				std::cout << r2::tab2 << "srand( 1 );" << r2::linefeed2;

				for( int i = 0; 10 > i; ++i )
				{
					std::cout << r2::tab2 << "rand() : " << rand() << r2::linefeed;
				}

				std::cout << r2::linefeed;
				std::cout << r2::tab << "# Message : srand( 1 ) is Default" << r2::linefeed;
				std::cout << r2::tab << "# Message : srand( n ) is init rand() Sequence" << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc C_Time::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "C Time : Basic";
		};
	}
	r2::iTest::DoFunc C_Time::GetDoFunction()
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

			return r2::eTestResult::RunTest;
		};
	}
}