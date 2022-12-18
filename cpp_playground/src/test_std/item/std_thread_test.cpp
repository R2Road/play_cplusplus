#include "std_thread_test.h"

#include <conio.h>
#include <chrono>
#include <sstream>
#include <thread>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_StopWatch.h"

#pragma warning( disable : 4477 ) // for "%x" and std::this_thread::get_id()

namespace std_thread_test
{
	void thread_func_1()
	{
		std::this_thread::sleep_for( std::chrono::milliseconds( 10 ) );

		for( auto i = 0; 8 > i; ++i )
		{
			std::cout << "thread_func_1 : " << i << r2cm::linefeed;
		}
	}

	void thread_func_2()
	{
		std::this_thread::sleep_for( std::chrono::milliseconds( 10 ) );

		for( auto i = 0; 8 > i; ++i )
		{
			std::cout << "thread_func_2 : " << i << r2cm::linefeed;
		}
	}

	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				std::thread t1;

				std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "std::thread t1;" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "- ID : " << t1.get_id() << r2cm::linefeed;
				std::cout << r2cm::tab3 << "- Joinable : " << ( t1.joinable() ? "O" : "X" ) << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::thread t1( thread_func_1 );
				std::thread t2( thread_func_2 );

				std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "std::thread t1( thread_func_1 );" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "- ID : " << t1.get_id() << r2cm::linefeed;
				std::cout << r2cm::tab3 << "- Joinable : " << ( t1.joinable() ? "O" : "X" ) << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "std::thread t2( thread_func_2 );" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "- ID : " << t2.get_id() << r2cm::linefeed;
				std::cout << r2cm::tab3 << "- Joinable : " << ( t2.joinable() ? "O" : "X" ) << r2cm::linefeed2;

				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "+ Wait 4 Thread End" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "t1.join();" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "t2.join();" << r2cm::linefeed;

				std::cout << r2cm::split;

				t1.join();
				t2.join();
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}



namespace std_thread_test
{
	void empty_thread_func( int ) {}

	r2cm::iItem::TitleFunctionT Declaration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Declaration";
		};
	}
	r2cm::iItem::DoFunctionT Declaration::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				std::thread test_thread( empty_thread_func, 3 );
				test_thread.join();

				std::cout << r2cm::tab << "+ Declaration With Function" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "void empty_thread_func( int ) {}" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "std::thread test_thread( empty_thread_func, 3 );" << r2cm::linefeed2;
			}

			std::cout << r2cm::split;

			{
				class ThreadTestClass
				{
				public:
					ThreadTestClass( int ) {}
					void operator()() const {}
				};

				std::thread test_thread{ ThreadTestClass( 3 ) };
				test_thread.join();

				std::cout << r2cm::tab << "+ Declaration With Function Object" << r2cm::linefeed2;

				std::cout << r2cm::tab2 << "class ThreadTestClass" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "{" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "public:" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "ThreadTestClass( int ) {}" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "void operator()() const {}" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "}" << r2cm::linefeed2;

				std::cout << r2cm::tab2 << "std::thread test_thread{ ThreadTestClass( 3 ) };" << r2cm::linefeed2;
			}

			std::cout << r2cm::split;

			{
				std::thread test_thread( []( int, int ) {}, 3, 4 );
				test_thread.join();

				std::cout << r2cm::tab << "+ Declaration With Lambda" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "std::thread test_thread( []() {}, 3, 4 );" << r2cm::linefeed2;
			}

			std::cout << r2cm::split;

			{
				class ThreadTestClass
				{
				public:
					void process() const {}
				};

				ThreadTestClass thread_test_class;

				std::thread test_thread( &ThreadTestClass::process, &thread_test_class );
				test_thread.join();

				std::cout << r2cm::tab << "+ Declaration With Class Method" << r2cm::linefeed2;

				std::cout << r2cm::tab2 << "class ThreadTestClass" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "{" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "public:" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "void process() const {}" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "}" << r2cm::linefeed2;

				std::cout << r2cm::tab2 << "ThreadTestClass thread_test_class;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "std::thread test_thread( &ThreadTestClass::process, &thread_test_class );" << r2cm::linefeed2;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}



namespace std_thread_test
{
	r2cm::iItem::TitleFunctionT CopyAssaignment::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Copy Assaignment";
		};
	}
	r2cm::iItem::DoFunctionT CopyAssaignment::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			std::thread t1;
			std::thread t2(
				[]( int, int )
				{
					std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );
				}, 3, 4
			);

			{
				std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;

				std::cout << r2cm::tab2 << "std::thread t1;" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "- ID : " << t1.get_id() << r2cm::linefeed;
				std::cout << r2cm::tab3 << "- Joinable : " << ( t1.joinable() ? "O" : "X" ) << r2cm::linefeed2;

				std::cout << r2cm::tab2 << "std::thread t2(" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "[]( int, int )" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "{" << r2cm::linefeed;
				std::cout << r2cm::tab4 << "std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "}, 3, 4" << r2cm::linefeed;
				std::cout << r2cm::tab2 << ");" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "- ID : " << t2.get_id() << r2cm::linefeed;
				std::cout << r2cm::tab3 << "- Joinable : " << ( t2.joinable() ? "O" : "X" ) << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				t1 = std::move( t2 );

				std::cout << r2cm::tab << "+ Assignment" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "t1 = std::move( t2 );" << r2cm::linefeed2;

				std::cout << r2cm::tab2 << "t1" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "- ID : " << t1.get_id() << r2cm::linefeed;
				std::cout << r2cm::tab3 << "- Joinable : " << ( t1.joinable() ? "O" : "X" ) << r2cm::linefeed2;

				std::cout << r2cm::tab2 << "t2" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "- ID : " << t2.get_id() << r2cm::linefeed;
				std::cout << r2cm::tab3 << "- Joinable : " << ( t2.joinable() ? "O" : "X" ) << r2cm::linefeed;
			}

			t1.join();

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}



namespace std_thread_test
{
	r2cm::iItem::TitleFunctionT WaitProcess_SleepFor::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Wait Process : Sleep For";
		};
	}
	r2cm::iItem::DoFunctionT WaitProcess_SleepFor::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab2 << "std::thread test_thread( []()" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "{" << r2cm::linefeed;
				std::cout << r2cm::tab4 << "printf( \"\\t\\tstart thread \\n\" );" << r2cm::linefeed2;
				std::cout << r2cm::tab4 << "std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );" << r2cm::linefeed2;
				std::cout << r2cm::tab4 << "printf( \"\\t\\tend thread \\n\" );" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "}" << r2cm::linefeed;
				std::cout << r2cm::tab2 << ");" << r2cm::linefeed;

				std::cout << r2cm::linefeed;

				std::thread test_thread( []()
					{
						printf( "\t\tstart thread \n" );

						std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );

						printf( "\t\tend thread \n" );
					}
				);
				test_thread.join();
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}



namespace std_thread_test
{
	r2cm::iItem::TitleFunctionT WaitProcess_Yield::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Wait Process : Yield";
		};
	}
	r2cm::iItem::DoFunctionT WaitProcess_Yield::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab2 << "auto thread_process = []()" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "{" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "for( int count = 0; 10 > count; ++count )" << r2cm::linefeed2;
				std::cout << r2cm::tab3 << "{" << r2cm::linefeed;
				std::cout << r2cm::tab4 << "printf( \"\\t\\t\" \"thread %x : yield % d\" \"\\n\", std::this_thread::get_id(), count );" << r2cm::linefeed2;
				std::cout << r2cm::tab4 << "std::this_thread::yield();" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "}" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "}" << r2cm::linefeed;

				std::cout << r2cm::linefeed;

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


				std::cout << r2cm::linefeed;
				std::cout << r2cm::tab2 << "Note : 양보 받을 놈이 없으면 아무 소용 없다." << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}



namespace std_thread_test
{
	r2cm::iItem::TitleFunctionT ThisThread_SleepFor::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "ThisThread : SleepFor";
		};
	}
	r2cm::iItem::DoFunctionT ThisThread_SleepFor::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << clm( r2cm::eColor::FG_Green ) << "# 음수 값을 넣어도 문제는 발생하지 않는다." << clm() << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( r2cm::StopWatch stop_watch );

				PROCESS_MAIN( stop_watch.Start() );
				PROCESS_MAIN( std::this_thread::sleep_for( std::chrono::milliseconds( -100 ) ) );
				PROCESS_MAIN( stop_watch.Stop() );

				std::cout << r2cm::linefeed;

				stop_watch.PrintElapsedTime_All();
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}