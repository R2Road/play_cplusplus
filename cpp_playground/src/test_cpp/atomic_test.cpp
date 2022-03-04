#include "pch.h"
#include "atomic_test.h"

#include <atomic>
#include <memory>
#include <thread>
#include <type_traits>

#include "base/r2_eTestEndAction.h"

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

namespace atomic_test
{
	template<typename T>
	class IsLockFreePrinter
	{
	public:
		void Print()
		{
			std::atomic<T> atm;

			std::cout << r2::tab2 << "std::atomic<" << typeid( T ).name() << "> atm;" << r2::linefeed;
			std::cout << r2::tab3 << "- type size : " << sizeof( T ) << " byte" << r2::linefeed;
			std::cout << r2::tab3 << "- atm.is_lock_free() : " << ( atm.is_lock_free() ? "O" : "X" ) << r2::linefeed2;
		}		
	};

	r2::iItem::TitleFuncT IsLockFree::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Is Lock Free";
		};
	}
	r2::iItem::DoFuncT IsLockFree::GetDoFunction()
	{
		return []()->r2::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Test 1" << r2::linefeed2;

				IsLockFreePrinter<bool>().Print();
				IsLockFreePrinter<char>().Print();
				IsLockFreePrinter<short>().Print();
				IsLockFreePrinter<int>().Print();
				IsLockFreePrinter<float>().Print();
				IsLockFreePrinter<double>().Print();
				IsLockFreePrinter<int64_t>().Print();
				IsLockFreePrinter<void*>().Print();
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Test 2" << r2::linefeed2;

				IsLockFreePrinter<TestStruct1>().Print();

				std::cout << r2::tab << "# 멤버가 2개 이상인 struct 의 atomic을 만들면 어쩔때는 static assert가 걸리고 어쩔때는 안걸린다." << r2::linefeed;
				std::cout << r2::tab << "# vs2017에 버그가 있는듯." << r2::linefeed2;
			}

			std::cout << r2::split;

			return r2::eTestEndAction::Pause;
		};
	}

	r2::iItem::TitleFuncT LockFreeTest1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Lock Free Test 1";
		};
	}
	r2::iItem::DoFuncT LockFreeTest1::GetDoFunction()
	{
		return []()->r2::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "int n = 0;" << r2::linefeed2;

				int n = 0;

				std::cout << r2::tab2 << "thread x 5 : 100000 time ++n" << r2::linefeed2;


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


				std::cout << r2::linefeed;
				std::cout << r2::tab2 << "n = " << n << r2::linefeed2;
			}

			std::cout << r2::split;

			return r2::eTestEndAction::Pause;
		};
	}

	r2::iItem::TitleFuncT LockFreeTest2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Lock Free Test 2";
		};
	}
	r2::iItem::DoFuncT LockFreeTest2::GetDoFunction()
	{
		return []()->r2::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "std::atomic_int32_t n = 0;" << r2::linefeed2;

				std::atomic_int32_t n = 0;

				std::cout << r2::tab2 << "thread x 5 : 100000 time ++n" << r2::linefeed2;


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


				std::cout << r2::linefeed;
				std::cout << r2::tab2 << "n = " << n << r2::linefeed2;
			}

			std::cout << r2::split;

			return r2::eTestEndAction::Pause;
		};
	}
}