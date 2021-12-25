#include "pch.h"
#include "atomic_test.h"

#include <atomic>
#include <string>
#include <type_traits>

#include "base/r2_eTestResult.h"

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
				std::cout << r2::tab << "+ Test" << r2::linefeed2;

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

			return r2::eTestResult::RunTest;
		};
	}
}