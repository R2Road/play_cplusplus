#include "std_atomic_test.h"

#include <atomic>
#include <memory>
#include <thread>
#include <type_traits>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

struct TestStruct1
{
	int i;
};

struct TestStruct2
{
	int i;
	float f;
};

struct TestStruct3
{
	int i;
	float f;
	bool b;
};

namespace std_atomic_test
{
	template<typename T>
	class IsLockFreePrinter
	{
	public:
		void Print()
		{
			std::atomic<T> atm;

			std::cout << r2cm::tab2 << "std::atomic<" << typeid( T ).name() << "> atm;" << r2cm::linefeed;
			std::cout << r2cm::tab3 << "- type size : " << sizeof( T ) << " byte" << r2cm::linefeed;
			std::cout << r2cm::tab3 << "- atm.is_lock_free() : " << ( atm.is_lock_free() ? "O" : "X" ) << r2cm::linefeed2;
		}		
	};

	r2cm::iItem::TitleFunctionT IsLockFree::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Is Lock Free";
		};
	}
	r2cm::iItem::DoFunctionT IsLockFree::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Test 1" << r2cm::linefeed2;

				IsLockFreePrinter<bool>().Print();
				IsLockFreePrinter<char>().Print();
				IsLockFreePrinter<short>().Print();
				IsLockFreePrinter<int>().Print();
				IsLockFreePrinter<float>().Print();
				IsLockFreePrinter<double>().Print();
				IsLockFreePrinter<int64_t>().Print();
				IsLockFreePrinter<void*>().Print();
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Test 2" << r2cm::linefeed2;

				IsLockFreePrinter<TestStruct1>().Print();

				std::cout << r2cm::tab << "# 멤버가 2개 이상인 struct 의 atomic을 만들면 어쩔때는 static assert가 걸리고 어쩔때는 안걸린다." << r2cm::linefeed;
				std::cout << r2cm::tab << "# vs2017에 버그가 있는듯." << r2cm::linefeed2;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}

	r2cm::iItem::TitleFunctionT LockFreeTest1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Lock Free Test 1";
		};
	}
	r2cm::iItem::DoFunctionT LockFreeTest1::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( int n = 0 );

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ thread x 5 : 100000 time ++n" << r2cm::linefeed2;
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

			std::cout << r2cm::split;

			EXPECT_NE( 100000 * 5, n );

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}

	r2cm::iItem::TitleFunctionT LockFreeTest2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Lock Free Test 2";
		};
	}
	r2cm::iItem::DoFunctionT LockFreeTest2::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( std::atomic_int32_t n = 0 );

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "thread x 5 : 100000 time ++n" << r2cm::linefeed2;


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

			std::cout << r2cm::split;

			EXPECT_EQ( 100000 * 5, n );

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}