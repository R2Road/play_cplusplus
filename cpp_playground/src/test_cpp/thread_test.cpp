#include "pch.h"
#include "thread_test.h"

#include <conio.h>
#include <chrono>
#include <sstream>
#include <thread>

#include "base/r2_eTestResult.h"
#include "renderer/r2_FrameManager.h"

#pragma warning( disable : 4477 ) // for "%x" and std::this_thread::get_id()

namespace thread_test
{
	void thread_func_1()
	{
		std::this_thread::sleep_for( std::chrono::milliseconds( 10 ) );

		for( auto i = 0; 8 > i; ++i )
		{
			std::cout << "thread_func_1 : " << i << r2::linefeed;
		}
	}

	void thread_func_2()
	{
		std::this_thread::sleep_for( std::chrono::milliseconds( 10 ) );

		for( auto i = 0; 8 > i; ++i )
		{
			std::cout << "thread_func_2 : " << i << r2::linefeed;
		}
	}

	r2::iTest::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Basic";
		};
	}
	r2::iTest::DoFunc Basic::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::thread t1;

				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "std::thread t1;" << r2::linefeed;
				std::cout << r2::tab3 << "- ID : " << t1.get_id() << r2::linefeed;
				std::cout << r2::tab3 << "- Joinable : " << ( t1.joinable() ? "O" : "X" ) << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::thread t1( thread_func_1 );
				std::thread t2( thread_func_2 );

				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "std::thread t1( thread_func_1 );" << r2::linefeed;
				std::cout << r2::tab3 << "- ID : " << t1.get_id() << r2::linefeed;
				std::cout << r2::tab3 << "- Joinable : " << ( t1.joinable() ? "O" : "X" ) << r2::linefeed2;
				std::cout << r2::tab2 << "std::thread t2( thread_func_2 );" << r2::linefeed;
				std::cout << r2::tab3 << "- ID : " << t2.get_id() << r2::linefeed;
				std::cout << r2::tab3 << "- Joinable : " << ( t2.joinable() ? "O" : "X" ) << r2::linefeed2;

				std::cout << r2::linefeed;

				std::cout << r2::tab << "+ Wait 4 Thread End" << r2::linefeed2;
				std::cout << r2::tab2 << "t1.join();" << r2::linefeed;
				std::cout << r2::tab2 << "t2.join();" << r2::linefeed;

				std::cout << r2::split;

				t1.join();
				t2.join();
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}



namespace thread_test
{
	void empty_thread_func( int ) {}

	r2::iTest::TitleFunc Declaration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Declaration";
		};
	}
	r2::iTest::DoFunc Declaration::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::thread test_thread( empty_thread_func, 3 );
				test_thread.join();

				std::cout << r2::tab << "+ Declaration With Function" << r2::linefeed2;
				std::cout << r2::tab2 << "void empty_thread_func( int ) {}" << r2::linefeed2;
				std::cout << r2::tab2 << "std::thread test_thread( empty_thread_func, 3 );" << r2::linefeed2;
			}

			std::cout << r2::split;

			{
				class ThreadTestClass
				{
				public:
					ThreadTestClass( int ) {}
					void operator()() const {}
				};

				std::thread test_thread{ ThreadTestClass( 3 ) };
				test_thread.join();

				std::cout << r2::tab << "+ Declaration With Function Object" << r2::linefeed2;

				std::cout << r2::tab2 << "class ThreadTestClass" << r2::linefeed;
				std::cout << r2::tab2 << "{" << r2::linefeed;
				std::cout << r2::tab2 << "public:" << r2::linefeed;
				std::cout << r2::tab3 << "ThreadTestClass( int ) {}" << r2::linefeed;
				std::cout << r2::tab3 << "void operator()() const {}" << r2::linefeed;
				std::cout << r2::tab2 << "}" << r2::linefeed2;

				std::cout << r2::tab2 << "std::thread test_thread{ ThreadTestClass( 3 ) };" << r2::linefeed2;
			}

			std::cout << r2::split;

			{
				std::thread test_thread( []( int, int ) {}, 3, 4 );
				test_thread.join();

				std::cout << r2::tab << "+ Declaration With Lambda" << r2::linefeed2;
				std::cout << r2::tab2 << "std::thread test_thread( []() {}, 3, 4 );" << r2::linefeed2;
			}

			std::cout << r2::split;

			{
				class ThreadTestClass
				{
				public:
					void process() const {}
				};

				ThreadTestClass thread_test_class;

				std::thread test_thread( &ThreadTestClass::process, &thread_test_class );
				test_thread.join();

				std::cout << r2::tab << "+ Declaration With Class Method" << r2::linefeed2;

				std::cout << r2::tab2 << "class ThreadTestClass" << r2::linefeed;
				std::cout << r2::tab2 << "{" << r2::linefeed;
				std::cout << r2::tab2 << "public:" << r2::linefeed;
				std::cout << r2::tab3 << "void process() const {}" << r2::linefeed;
				std::cout << r2::tab2 << "}" << r2::linefeed2;

				std::cout << r2::tab2 << "ThreadTestClass thread_test_class;" << r2::linefeed;
				std::cout << r2::tab2 << "std::thread test_thread( &ThreadTestClass::process, &thread_test_class );" << r2::linefeed2;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}



namespace thread_test
{
	r2::iTest::TitleFunc CopyAssaignment::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Copy Assaignment";
		};
	}
	r2::iTest::DoFunc CopyAssaignment::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			std::thread t1;
			std::thread t2(
				[]( int, int )
				{
					std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );
				}, 3, 4
			);

			{
				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;

				std::cout << r2::tab2 << "std::thread t1;" << r2::linefeed;
				std::cout << r2::tab3 << "- ID : " << t1.get_id() << r2::linefeed;
				std::cout << r2::tab3 << "- Joinable : " << ( t1.joinable() ? "O" : "X" ) << r2::linefeed2;

				std::cout << r2::tab2 << "std::thread t2(" << r2::linefeed;
				std::cout << r2::tab3 << "[]( int, int )" << r2::linefeed;
				std::cout << r2::tab3 << "{" << r2::linefeed;
				std::cout << r2::tab4 << "std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );" << r2::linefeed;
				std::cout << r2::tab3 << "}, 3, 4" << r2::linefeed;
				std::cout << r2::tab2 << ");" << r2::linefeed;
				std::cout << r2::tab3 << "- ID : " << t2.get_id() << r2::linefeed;
				std::cout << r2::tab3 << "- Joinable : " << ( t2.joinable() ? "O" : "X" ) << r2::linefeed;
			}

			std::cout << r2::split;

			{
				t1 = std::move( t2 );

				std::cout << r2::tab << "+ Assignment" << r2::linefeed2;
				std::cout << r2::tab2 << "t1 = std::move( t2 );" << r2::linefeed2;

				std::cout << r2::tab2 << "t1" << r2::linefeed;
				std::cout << r2::tab3 << "- ID : " << t1.get_id() << r2::linefeed;
				std::cout << r2::tab3 << "- Joinable : " << ( t1.joinable() ? "O" : "X" ) << r2::linefeed2;

				std::cout << r2::tab2 << "t2" << r2::linefeed;
				std::cout << r2::tab3 << "- ID : " << t2.get_id() << r2::linefeed;
				std::cout << r2::tab3 << "- Joinable : " << ( t2.joinable() ? "O" : "X" ) << r2::linefeed;
			}

			t1.join();

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}



namespace thread_test
{
	r2::iTest::TitleFunc WaitProcess_SleepFor::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Wait Process : Sleep For";
		};
	}
	r2::iTest::DoFunc WaitProcess_SleepFor::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab2 << "std::thread test_thread( []()" << r2::linefeed;
				std::cout << r2::tab3 << "{" << r2::linefeed;
				std::cout << r2::tab4 << "printf( \"\\t\\tstart thread \\n\" );" << r2::linefeed2;
				std::cout << r2::tab4 << "std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );" << r2::linefeed2;
				std::cout << r2::tab4 << "printf( \"\\t\\tend thread \\n\" );" << r2::linefeed;
				std::cout << r2::tab3 << "}" << r2::linefeed;
				std::cout << r2::tab2 << ");" << r2::linefeed;

				std::cout << r2::linefeed;

				std::thread test_thread( []()
					{
						printf( "\t\tstart thread \n" );

						std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );

						printf( "\t\tend thread \n" );
					}
				);
				test_thread.join();
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}



namespace thread_test
{
	r2::iTest::TitleFunc WaitProcess_Yield::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Wait Process : Yield";
		};
	}
	r2::iTest::DoFunc WaitProcess_Yield::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab2 << "auto thread_process = []()" << r2::linefeed;
				std::cout << r2::tab2 << "{" << r2::linefeed;
				std::cout << r2::tab3 << "for( int count = 0; 10 > count; ++count )" << r2::linefeed2;
				std::cout << r2::tab3 << "{" << r2::linefeed;
				std::cout << r2::tab4 << "printf( \"\\t\\t\" \"thread %x : yield % d\" \"\\n\", std::this_thread::get_id(), count );" << r2::linefeed2;
				std::cout << r2::tab4 << "std::this_thread::yield();" << r2::linefeed;
				std::cout << r2::tab3 << "}" << r2::linefeed;
				std::cout << r2::tab2 << "}" << r2::linefeed;

				std::cout << r2::linefeed;

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


				std::cout << r2::linefeed;
				std::cout << r2::tab2 << "Note : 양보 받을 놈이 없으면 아무 소용 없다." << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}