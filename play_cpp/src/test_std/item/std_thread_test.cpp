#include "std_thread_test.h"

#include <conio.h>
#include <ctime> // time.h : c // time(), clock()
#include <chrono>
#include <sstream>
#include <thread>

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"
#include "r2tm/r2tm_stop_watch.hpp"

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

			OUT_SUBJECT( "기본 생성자" );

			LS();

			DECL_MAIN( std::thread t );

			LS();

			{
				EXPECT_EQ( std::thread::id(), t.get_id() );
				OUT_VALUE( t.get_id() );

				LF();

				EXPECT_FALSE( t.joinable() );
			}

			LS();

			{
				OUT_CODE( t.join() );

				LF();

				OUT_NOTE( "빈 std::thread에 join 함수를 호출하면..." );
				OUT_COMMENT( "예외가 발생한다." );
				OUT_COMMENT( "터지지는 안는다." );
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

			OUT_FILE( "src/test_std/item/std_thread_test_helper_declaration2.hpp" );
			using namespace std_thread_test_helper_declaration2;

			LS();

			{
				OUT_SUBJECT( "Function" );

				LF();

				DECL_MAIN( std::thread t( empty_func_1 ) );
				OUT_VALUE( t.get_id() );

				LF();

				PROC_MAIN( t.join() );
			}

			LS();

			{
				OUT_SUBJECT( "Function" );

				LF();

				DECL_MAIN( std::thread t( empty_func_2, 3 ) );
				OUT_VALUE( t.get_id() );

				LF();

				PROC_MAIN( t.join() );
			}

			LS();

			{
				OUT_SUBJECT( "Lambda" );

				LF();

				DECL_MAIN( std::thread t( []( int, int ) {}, 3, 4 ) );
				OUT_VALUE( t.get_id() );

				LF();

				PROC_MAIN( t.join() );
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
				OUT_SUBJECT( "Function Object" );

				LF();

				OUT_SOURCE_READY_N_BEGIN;
				struct S
				{
					void operator()() const {}
				};
				OUT_SOURCE_END;

				LF();

				DECL_MAIN( std::thread t{ S() } );
				OUT_VALUE( t.get_id() );

				LF();

				PROC_MAIN( t.join() );
			}

			LS();

			{
				OUT_SUBJECT( "Class + Method" );

				LF();

				OUT_SOURCE_READY_N_BEGIN;
				struct S
				{
					void process() const {}
				};
				OUT_SOURCE_END;

				LF();

				DECL_MAIN( S s );
				DECL_MAIN( std::thread t( &S::process, &s ) );
				OUT_VALUE( t.get_id() );

				LF();

				PROC_MAIN( t.join() );
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

			OUT_SOURCE_READY_N_BEGIN;
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
			OUT_SOURCE_END;

			LS();

			DECL_MAIN( std::thread t1( S( 3 ) ) );
			DECL_MAIN( std::thread t2( S( 3 ) ) );

			LS();

			{
				PROC_MAIN( t1.join() );
				PROC_MAIN( t2.join() );
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

			OUT_SOURCE_READY_N_BEGIN;
			std::thread t1;
			std::thread t2(
				[]( int, int )
				{
					std::this_thread::sleep_for(
						std::chrono::milliseconds( 100 )
					);
				}, 3, 4
			);
			OUT_SOURCE_END;

			LS();

			{
				OUT_VALUE( t1.get_id() );
				EXPECT_FALSE( t1.joinable() );

				LF();

				OUT_VALUE( t2.get_id() );
				EXPECT_TRUE( t2.joinable() );
			}

			LS();

			{
				OUT_SUBJECT( "Assign" );

				LF();

				PROC_MAIN( t1 = std::move( t2 ) );

				LF();

				OUT_NOTE( "Move 만 가능" );
			}

			LS();

			{
				OUT_VALUE( t1.get_id() );
				EXPECT_TRUE( t1.joinable() );

				LF();

				OUT_VALUE( t2.get_id() );
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

			DECL_MAIN( std::thread t );

			LF();

			OUT_SOURCE_READY_N_BEGIN;
			const auto l = []()
			{
				time_t t = 0;
				
				t = time( NULL );
				printf( "\t\t" "start thread : %lld" "\n", t );

				std::this_thread::sleep_for( std::chrono::milliseconds( 2000 ) );

				t = time( NULL );
				printf( "\t\t" "  end thread : %lld" "\n", t );
			};
			OUT_SOURCE_END;

			LS();

			{
				PROC_MAIN( t = std::thread( l ) );
				PROC_MAIN( t.join() );
			}

			LS();

			{
				DECL_MAIN( r2tm::StopWatch stop_watch );

				LF();

				PROC_MAIN( stop_watch.Start() );
				PROC_MAIN( std::this_thread::sleep_for( std::chrono::milliseconds( -100 ) ) );
				PROC_MAIN( stop_watch.Stop() );

				LF();

				PROC_MAIN( stop_watch.PrintElapsedTime_All() );

				LF2();

				OUT_NOTE( "음수 값을 넣어도 문제는 발생하지 않는다." );
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

			OUT_SOURCE_READY_N_BEGIN;
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
			OUT_SOURCE_END;

			LS();

			{
				DECL_MAIN( std::thread t1( thread_process ) );
				DECL_MAIN( std::thread t2( thread_process ) );
				DECL_MAIN( std::thread t3( thread_process ) );
				DECL_MAIN( std::thread t4( thread_process ) );

				LF();

				PROC_MAIN( t1.join() );
				PROC_MAIN( t2.join() );
				PROC_MAIN( t3.join() );
				PROC_MAIN( t4.join() );
			}
			
			LS();

			{
				OUT_NOTE( "양보 받을 thread 가 없다면 아무 일도 일어나지 않는다." );
				OUT_NOTE( "...라고 reference에 써있다." );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}