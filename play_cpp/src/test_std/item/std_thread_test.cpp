#include "std_thread_test.h"

#include <conio.h>
#include <ctime> // time.h : c // time(), clock()
#include <chrono>
#include <sstream>
#include <thread>

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_StopWatch.h"

#pragma warning( disable : 4477 ) // for "%x" and std::this_thread::get_id()

namespace std_thread_test
{
	r2tm::TitleFunctionT Declaration_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Declaration 1";
		};
	}
	r2tm::DoFunctionT Declaration_1::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_SUBJECT( "기본 생성자" );

			LS();

			DECLARATION_MAIN( std::thread t );

			LS();

			{
				EXPECT_EQ( std::thread::id(), t.get_id() );
				OUTPUT_VALUE( t.get_id() );

				LF();

				EXPECT_FALSE( t.joinable() );
			}

			LS();

			{
				OUTPUT_CODE( t.join() );

				LF();

				OUTPUT_NOTE( "빈 std::thread에 join 함수를 호출하면..." );
				OUTPUT_COMMENT( "예외가 발생한다." );
				OUTPUT_COMMENT( "터지지는 안는다." );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



#include "std_thread_test_helper_declaration2.hpp"

	r2tm::TitleFunctionT Declaration_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Declaration 2";
		};
	}
	r2tm::DoFunctionT Declaration_2::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_FILE( "src/test_std/item/std_thread_test_helper_declaration2.hpp" );
			using namespace std_thread_test_helper_declaration2;

			LS();

			{
				OUTPUT_SUBJECT( "Function" );

				LF();

				DECLARATION_MAIN( std::thread t( empty_func_1 ) );
				OUTPUT_VALUE( t.get_id() );

				LF();

				PROCESS_MAIN( t.join() );
			}

			LS();

			{
				OUTPUT_SUBJECT( "Function" );

				LF();

				DECLARATION_MAIN( std::thread t( empty_func_2, 3 ) );
				OUTPUT_VALUE( t.get_id() );

				LF();

				PROCESS_MAIN( t.join() );
			}

			LS();

			{
				OUTPUT_SUBJECT( "Lambda" );

				LF();

				DECLARATION_MAIN( std::thread t( []( int, int ) {}, 3, 4 ) );
				OUTPUT_VALUE( t.get_id() );

				LF();

				PROCESS_MAIN( t.join() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Declaration_3::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Declaration 3";
		};
	}
	r2tm::DoFunctionT Declaration_3::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_SUBJECT( "Function Object" );

				LF();

				OUTPUT_SOURCE_READY_N_BEGIN;
				struct S
				{
					void operator()() const {}
				};
				OUTPUT_SOURCE_END;

				LF();

				DECLARATION_MAIN( std::thread t{ S() } );
				OUTPUT_VALUE( t.get_id() );

				LF();

				PROCESS_MAIN( t.join() );
			}

			LS();

			{
				OUTPUT_SUBJECT( "Class + Method" );

				LF();

				OUTPUT_SOURCE_READY_N_BEGIN;
				struct S
				{
					void process() const {}
				};
				OUTPUT_SOURCE_END;

				LF();

				DECLARATION_MAIN( S s );
				DECLARATION_MAIN( std::thread t( &S::process, &s ) );
				OUTPUT_VALUE( t.get_id() );

				LF();

				PROCESS_MAIN( t.join() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Demo::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Demo";
		};
	}
	r2tm::DoFunctionT Demo::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_SOURCE_READY_N_BEGIN;
			struct S
			{
				S( int ) {}
				void operator()() const
				{
					for( int count = 0; 10 > count; ++count )
					{
						printf(
							"\t\t" "thread %x : %d" "\n"
							, std::this_thread::get_id()
							, count
						);
					}
				}
			};
			OUTPUT_SOURCE_END;

			LS();

			DECLARATION_MAIN( std::thread t1( S( 3 ) ) );
			DECLARATION_MAIN( std::thread t2( S( 3 ) ) );

			LS();

			{
				PROCESS_MAIN( t1.join() );
				PROCESS_MAIN( t2.join() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT CopyAssaignment::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Copy Assaignment";
		};
	}
	r2tm::DoFunctionT CopyAssaignment::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_SOURCE_READY_N_BEGIN;
			std::thread t1;
			std::thread t2(
				[]( int, int )
				{
					std::this_thread::sleep_for(
						std::chrono::milliseconds( 100 )
					);
				}, 3, 4
			);
			OUTPUT_SOURCE_END;

			LS();

			{
				OUTPUT_VALUE( t1.get_id() );
				EXPECT_FALSE( t1.joinable() );

				LF();

				OUTPUT_VALUE( t2.get_id() );
				EXPECT_TRUE( t2.joinable() );
			}

			LS();

			{
				OUTPUT_SUBJECT( "Assign" );

				LF();

				PROCESS_MAIN( t1 = std::move( t2 ) );

				LF();

				OUTPUT_NOTE( "Move 만 가능" );
			}

			LS();

			{
				OUTPUT_VALUE( t1.get_id() );
				EXPECT_TRUE( t1.joinable() );

				LF();

				OUTPUT_VALUE( t2.get_id() );
				EXPECT_FALSE( t2.joinable() );
			}

			t1.join();

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT WaitProcess_SleepFor::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Wait Process : Sleep For";
		};
	}
	r2tm::DoFunctionT WaitProcess_SleepFor::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( std::thread t );

			LF();

			OUTPUT_SOURCE_READY_N_BEGIN;
			const auto l = []()
			{
				time_t t = 0;
				
				t = time( NULL );
				printf( "\t\t" "start thread : %lld" "\n", t );

				std::this_thread::sleep_for( std::chrono::milliseconds( 2000 ) );

				t = time( NULL );
				printf( "\t\t" "  end thread : %lld" "\n", t );
			};
			OUTPUT_SOURCE_END;

			LS();

			PROCESS_MAIN( t = std::thread( l ) );

			LS();

			{
				PROCESS_MAIN( t.join() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT WaitProcess_Yield::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Wait Process : Yield";
		};
	}
	r2tm::DoFunctionT WaitProcess_Yield::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_SOURCE_READY_N_BEGIN;
			auto thread_process = []()
			{
				time_t t;

				for( int count = 0; 100 > count; ++count )
				{
					t = time( NULL );
					printf(
						  "\t\t" "thread %x : yield %d" "%lld" "\n"
						, std::this_thread::get_id()
						, count
						, t
					);
					std::this_thread::yield();
				}
			};
			OUTPUT_SOURCE_END;

			LS();

			{
				DECLARATION_MAIN( std::thread t1( thread_process ) );
				DECLARATION_MAIN( std::thread t2( thread_process ) );
				DECLARATION_MAIN( std::thread t3( thread_process ) );
				DECLARATION_MAIN( std::thread t4( thread_process ) );

				LF();

				PROCESS_MAIN( t1.join() );
				PROCESS_MAIN( t2.join() );
				PROCESS_MAIN( t3.join() );
				PROCESS_MAIN( t4.join() );
			}
			
			LS();

			{
				OUTPUT_NOTE( "양보 받을 thread 가 없다면 아무 일도 일어나지 않는다." );
				OUTPUT_NOTE( "...라고 reference에 써있다." );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT ThisThread_SleepFor::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "ThisThread : SleepFor";
		};
	}
	r2tm::DoFunctionT ThisThread_SleepFor::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				std::cout << r2tm::tab << clm( r2tm::eColor::FG_Green ) << "# 음수 값을 넣어도 문제는 발생하지 않는다." << clm() << r2tm::linefeed;
			}

			LS();

			{
				DECLARATION_MAIN( r2tm::StopWatch stop_watch );

				PROCESS_MAIN( stop_watch.Start() );
				PROCESS_MAIN( std::this_thread::sleep_for( std::chrono::milliseconds( -100 ) ) );
				PROCESS_MAIN( stop_watch.Stop() );

				LF();

				stop_watch.PrintElapsedTime_All();
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}