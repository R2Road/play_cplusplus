#include "std_atomic_test.h"

#include <atomic>
#include <memory>
#include <thread>
#include <type_traits>

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace std_atomic_test
{
	r2tm::TitleFunctionT Declaration_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "<std::atomic> : Declaration 1";
		};
	}
	r2tm::DoFunctionT Declaration_1::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_NOTE( "Primitive Type 가능" );
			OUTPUT_NOTE( "크기 변화는 없다" );

			LS();

			{
				OUTPUT_SUBJECT( "기본 생성자" );

				LF();

				{
					DECLARATION_MAIN( std::atomic<bool> a );
					OUTPUT_SIZE( a );
					OUTPUT_BINARIES( &a, 1 );
				}

				LF();

				{
					DECLARATION_MAIN( std::atomic<char> a );
					OUTPUT_SIZE( a );
					OUTPUT_BINARIES( &a, 1 );
				}

				LF();

				{
					DECLARATION_MAIN( std::atomic<int> a );
					OUTPUT_SIZE( a );
					OUTPUT_BINARIES( &a, 1 );
				}
			}

			LS();

			{
				OUTPUT_SUBJECT( "초기값 할당 가능" );

				LF();

				{
					DECLARATION_MAIN( std::atomic<int64_t> a( 7 ) );
					OUTPUT_SIZE( a );
					OUTPUT_BINARIES( &a, 1 );
				}

				LF();

				{
					DECLARATION_MAIN( std::atomic<void*> a = nullptr );
					OUTPUT_SIZE( a );
					OUTPUT_BINARIES( &a, 1 );
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Declaration_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "<std::atomic> : Declaration 2";
		};
	}
	r2tm::DoFunctionT Declaration_2::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_NOTE( "Primitive Type 1개를 멤버로 가지는 Type 가능" );

			LS();

			{
				OUTPUT_SUBJECT( "User Defined Type 1" );

				LF();

				OUTPUT_SOURCE_READY_N_BEGIN;
				struct S
				{
					int i;
				};
				OUTPUT_SOURCE_END;

				LF();

				DECLARATION_MAIN( std::atomic<S> a );
				OUTPUT_SIZE( a );
				OUTPUT_BINARIES( &a, 1 );
			}

			LS();

			{
				OUTPUT_SUBJECT( "User Defined Type 2" );

				LF();

				OUTPUT_SOURCE_READY_N_BEGIN;
				struct S
				{
					int i;
					float f;
				};
				OUTPUT_SOURCE_END;

				LF();

				OUTPUT_CODE( std::atomic<S> a );

				LF();

				OUTPUT_NOTE( "Not Working" );
				OUTPUT_NOTE( "static_assert 에 의한 C2338 발생" );
			}

			LS();

			OUTPUT_NOTE( "멤버가 2개 이상인 struct 의 atomic을 만들면" );
			OUTPUT_NOTE( "static assert가 걸렸다 말았다 한다." );
			OUTPUT_NOTE( "vs2017에 버그가 있는듯." );

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT IsLockFree::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "<std::atomic> : Is Lock Free";
		};
	}
	r2tm::DoFunctionT IsLockFree::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_SUBJECT( "Primitive Type" );

				LF();

				OUTPUT_VALUE( std::atomic<bool>().is_lock_free() );
				OUTPUT_VALUE( std::atomic<char>().is_lock_free() );
				OUTPUT_VALUE( std::atomic<short>().is_lock_free() );
				OUTPUT_VALUE( std::atomic<int>().is_lock_free() );
				OUTPUT_VALUE( std::atomic<float>().is_lock_free() );
				OUTPUT_VALUE( std::atomic<double>().is_lock_free() );
				OUTPUT_VALUE( std::atomic<int64_t>().is_lock_free() );
				OUTPUT_VALUE( std::atomic<void*>().is_lock_free() );
			}

			LS();

			{
				OUTPUT_SUBJECT( "User Defined Type 1" );

				LF();

				OUTPUT_SOURCE_READY_N_BEGIN;
				struct S
				{
					int i;
				};
				OUTPUT_SOURCE_END;

				LF();

				OUTPUT_VALUE( std::atomic<S>().is_lock_free() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}

	r2tm::TitleFunctionT LockFreeTest1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "<std::atomic> : Lock Free Test 1";
		};
	}
	r2tm::DoFunctionT LockFreeTest1::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( int n = 0 );

			LS();

			OUTPUT_SOURCE_READY_N_BEGIN;
			const auto l = [&n]( int index, int attmpt )
			{
				printf( "\t\tThread Start : %d\n", index );

				for( int i = 0; attmpt > i; ++i )
				{
					++n;
				}

				printf( "\t\tThread End : %d\n", index );
			};
			OUTPUT_SOURCE_END;

			LS();

			{
				DECLARATION_MAIN( std::thread test_thread_1( l, 1, 100000 ) );
				DECLARATION_MAIN( std::thread test_thread_2( l, 2, 100000 ) );
				DECLARATION_MAIN( std::thread test_thread_3( l, 3, 100000 ) );
				DECLARATION_MAIN( std::thread test_thread_4( l, 4, 100000 ) );
				DECLARATION_MAIN( std::thread test_thread_5( l, 5, 100000 ) );
				test_thread_1.join();
				test_thread_2.join();
				test_thread_3.join();
				test_thread_4.join();
				test_thread_5.join();
			}

			LS();

			EXPECT_NE( 100000 * 5, n );
			OUTPUT_VALUE( n );

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}

	r2tm::TitleFunctionT LockFreeTest2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "<std::atomic> : Lock Free Test 2";
		};
	}
	r2tm::DoFunctionT LockFreeTest2::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( std::atomic_int32_t n = 0 );

			LS();

			{
				std::cout << r2tm::tab << "thread x 5 : 100000 time ++n" << r2tm::linefeed2;


				auto thread_process = [&n]( int index, int attmpt )
				{
					printf( "\t\tThread Start : %d\n", index );

					for( int i = 0; attmpt > i; ++i )
					{
						++n;
					}

					printf( "\t\tThread End : %d\n", index );
				};

				std::thread test_thread_1( thread_process, 1, 100000 );
				std::thread test_thread_2( thread_process, 2, 100000 );
				std::thread test_thread_3( thread_process, 3, 100000 );
				std::thread test_thread_4( thread_process, 4, 100000 );
				std::thread test_thread_5( thread_process, 5, 100000 );
				test_thread_1.join();
				test_thread_2.join();
				test_thread_3.join();
				test_thread_4.join();
				test_thread_5.join();
			}

			LS();

			EXPECT_EQ( 100000 * 5, n );
			OUTPUT_VALUE( n );

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}