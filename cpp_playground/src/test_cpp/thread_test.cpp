#include "pch.h"
#include "thread_test.h"

#include <conio.h>
#include <chrono>
#include <thread>

#include "base/r2_eTestResult.h"
#include "renderer/r2_FrameManager.h"

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