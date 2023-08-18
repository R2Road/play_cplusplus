#include "std_thread_test.h"

#include <conio.h>
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
}



namespace std_thread_test
{
	void empty_thread_func( int ) {}

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

			{
				OUTPUT_SUBJECT( "Declaration With Function" );

				LF();

				DECLARATION_MAIN( std::thread test_thread( empty_thread_func, 3 ) );
				PROCESS_MAIN( test_thread.join() );
			}

			LS();

			{
				OUTPUT_SUBJECT( "Declaration With Function Object" );

				LF();

				OUTPUT_SOURCE_READY_N_BEGIN;
				class ThreadTestClass
				{
				public:
					ThreadTestClass( int ) {}
					void operator()() const {}
				};
				OUTPUT_SOURCE_END;

				LF();

				DECLARATION_MAIN( std::thread test_thread{ ThreadTestClass( 3 ) } );
				PROCESS_MAIN( test_thread.join() );
			}

			LS();

			{
				OUTPUT_SUBJECT( "Declaration With Lambda" );

				LF();

				DECLARATION_MAIN( std::thread test_thread( []( int, int ) {}, 3, 4 ) );
				PROCESS_MAIN( test_thread.join() );
			}

			LS();

			{
				OUTPUT_SUBJECT( "Declaration With Class Method" );

				LF();

				OUTPUT_SOURCE_READY_N_BEGIN;
				class ThreadTestClass
				{
				public:
					void process() const {}
				};
				OUTPUT_SOURCE_END;

				LF();

				DECLARATION_MAIN( ThreadTestClass thread_test_class );
				DECLARATION_MAIN( std::thread test_thread( &ThreadTestClass::process, &thread_test_class ) );
				PROCESS_MAIN( test_thread.join() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}



namespace std_thread_test
{
	void thread_func_1()
	{
		std::this_thread::sleep_for( std::chrono::milliseconds( 10 ) );

		for( auto i = 0; 8 > i; ++i )
		{
			std::cout << "thread_func_1 : " << i << r2tm::linefeed;
		}
	}

	void thread_func_2()
	{
		std::this_thread::sleep_for( std::chrono::milliseconds( 10 ) );

		for( auto i = 0; 8 > i; ++i )
		{
			std::cout << "thread_func_2 : " << i << r2tm::linefeed;
		}
	}

	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				std::thread t1( thread_func_1 );
				std::thread t2( thread_func_2 );

				std::cout << r2tm::tab << "+ Declaration" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "std::thread t1( thread_func_1 );" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "- ID : " << t1.get_id() << r2tm::linefeed;
				std::cout << r2tm::tab3 << "- Joinable : " << ( t1.joinable() ? "O" : "X" ) << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "std::thread t2( thread_func_2 );" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "- ID : " << t2.get_id() << r2tm::linefeed;
				std::cout << r2tm::tab3 << "- Joinable : " << ( t2.joinable() ? "O" : "X" ) << r2tm::linefeed2;

				LF();

				std::cout << r2tm::tab << "+ Wait 4 Thread End" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "t1.join();" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "t2.join();" << r2tm::linefeed;

				LS();

				t1.join();
				t2.join();
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}



namespace std_thread_test
{
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

			std::thread t1;
			std::thread t2(
				[]( int, int )
				{
					std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );
				}, 3, 4
			);

			{
				std::cout << r2tm::tab << "+ Declaration" << r2tm::linefeed2;

				std::cout << r2tm::tab2 << "std::thread t1;" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "- ID : " << t1.get_id() << r2tm::linefeed;
				std::cout << r2tm::tab3 << "- Joinable : " << ( t1.joinable() ? "O" : "X" ) << r2tm::linefeed2;

				std::cout << r2tm::tab2 << "std::thread t2(" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "[]( int, int )" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "{" << r2tm::linefeed;
				std::cout << r2tm::tab4 << "std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "}, 3, 4" << r2tm::linefeed;
				std::cout << r2tm::tab2 << ");" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "- ID : " << t2.get_id() << r2tm::linefeed;
				std::cout << r2tm::tab3 << "- Joinable : " << ( t2.joinable() ? "O" : "X" ) << r2tm::linefeed;
			}

			LS();

			{
				t1 = std::move( t2 );

				std::cout << r2tm::tab << "+ Assignment" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "t1 = std::move( t2 );" << r2tm::linefeed2;

				std::cout << r2tm::tab2 << "t1" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "- ID : " << t1.get_id() << r2tm::linefeed;
				std::cout << r2tm::tab3 << "- Joinable : " << ( t1.joinable() ? "O" : "X" ) << r2tm::linefeed2;

				std::cout << r2tm::tab2 << "t2" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "- ID : " << t2.get_id() << r2tm::linefeed;
				std::cout << r2tm::tab3 << "- Joinable : " << ( t2.joinable() ? "O" : "X" ) << r2tm::linefeed;
			}

			t1.join();

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}



namespace std_thread_test
{
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

			{
				std::cout << r2tm::tab2 << "std::thread test_thread( []()" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "{" << r2tm::linefeed;
				std::cout << r2tm::tab4 << "printf( \"\\t\\tstart thread \\n\" );" << r2tm::linefeed2;
				std::cout << r2tm::tab4 << "std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );" << r2tm::linefeed2;
				std::cout << r2tm::tab4 << "printf( \"\\t\\tend thread \\n\" );" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "}" << r2tm::linefeed;
				std::cout << r2tm::tab2 << ");" << r2tm::linefeed;

				LF();

				std::thread test_thread( []()
					{
						printf( "\t\tstart thread \n" );

						std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );

						printf( "\t\tend thread \n" );
					}
				);
				test_thread.join();
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}



namespace std_thread_test
{
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

			{
				std::cout << r2tm::tab2 << "auto thread_process = []()" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "{" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "for( int count = 0; 10 > count; ++count )" << r2tm::linefeed2;
				std::cout << r2tm::tab3 << "{" << r2tm::linefeed;
				std::cout << r2tm::tab4 << "printf( \"\\t\\t\" \"thread %x : yield % d\" \"\\n\", std::this_thread::get_id(), count );" << r2tm::linefeed2;
				std::cout << r2tm::tab4 << "std::this_thread::yield();" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "}" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "}" << r2tm::linefeed;

				LF();

				auto thread_process = []()
				{
					for( int count = 0; 10 > count; ++count )
					{
						printf( "\t\t" "thread %x : yield %d" "\n", std::this_thread::get_id(), count );
						std::this_thread::yield();
					}
				};

				std::thread test_thread_1( thread_process );
				std::thread test_thread_2( thread_process );
				std::thread test_thread_3( thread_process );
				std::thread test_thread_4( thread_process );

				test_thread_1.join();
				test_thread_2.join();
				test_thread_3.join();
				test_thread_4.join();


				LF();
				std::cout << r2tm::tab2 << "Note : 양보 받을 놈이 없으면 아무 소용 없다." << r2tm::linefeed;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}



namespace std_thread_test
{
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