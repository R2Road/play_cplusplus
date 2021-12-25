#include "pch.h"
#include "atomic_test.h"

#include <atomic>
#include <memory>
#include <type_traits>

#include "base/r2_eTestResult.h"

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

	r2::iTest::TitleFunc IsLockFree::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Is Lock Free";
		};
	}
	r2::iTest::DoFunc IsLockFree::GetDoFunction()
	{
		return []()->r2::eTestResult
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

			return r2::eTestResult::RunTest;
		};
	}
}