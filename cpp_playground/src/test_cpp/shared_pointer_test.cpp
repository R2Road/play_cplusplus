#include "pch.h"
#include "shared_pointer_test.h"

#include <memory>

#include "base/r2_eTestResult.h"

namespace
{
	void Test1()
	{
		std::cout << "# Shared Pointer #" << r2::linefeed << r2::linefeed;

		std::cout << "\t" << "+ Make Sp" << r2::linefeed;
		std::cout << "\t\t" << "std::shared_ptr<int> test_sp( new int( 10 ) )" << r2::linefeed;
		std::shared_ptr<int> test_sp( new int( 10 ) );

		std::cout << "\t\t\t - Print : " << *test_sp << r2::linefeed << r2::linefeed;


		std::cout << "\t" << "+ Copy To Const Sp" << r2::linefeed;
		std::cout << "\t\t" << "const auto test_sp_2 = test_sp;" << r2::linefeed;
		const auto test_sp_2 = test_sp;

		std::cout << r2::linefeed;


		std::cout << "\t" << "+ Change Value with Const Sp" << r2::linefeed;
		std::cout << "\t\t" << "*test_sp_2 = 11;" << r2::linefeed;
		*test_sp_2 = 11;

		std::cout << "\t\t\t - Print : " << *test_sp_2 << r2::linefeed;
		std::cout << r2::linefeed;
	}

	void Test2()
	{
		std::cout << "# Shared Pointer Has Const Value #" << r2::linefeed << r2::linefeed;

		std::cout << "\t" << "+ Make Sp Has Const Value" << r2::linefeed;
		std::cout << "\t\t" << "std::shared_ptr<const int> test_sp( new int( 10 ) )" << r2::linefeed;
		std::shared_ptr<const int> const_test_sp( new int( 10 ) );

		std::cout << "\t\t\t - Print : " << *const_test_sp << r2::linefeed;
		std::cout << r2::linefeed;

		std::cout << "\t" << "+ Failed : Change Value" << r2::linefeed;
		std::cout << r2::linefeed;

		//*const_test_sp = 11;
		//std::cout << "\t" << "+ Change Value with Sp Has Const Value" << r2::linefeed;
		//std::cout << "\t\t" << *const_test_sp << r2::linefeed;
	}

	void Test3()
	{
		std::cout << "# Make Shared #" << r2::linefeed << r2::linefeed;

		std::cout << "\t" << "auto test_sp = std::make_shared<int>( 10 );" << r2::linefeed;
		auto test_sp = std::make_shared<int>( 10 );

		std::cout << "\t\t - Print : " << *test_sp << r2::linefeed;
		std::cout << r2::linefeed;
	}
}

namespace shared_pointer_test
{
	r2::iTest::TitleFunc SharedPointer::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Shared Pointer";
		};
	}
	r2::iTest::DoFunc SharedPointer::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			Test1();

			std::cout << r2::linefeed << r2::linefeed;

			Test2();

			std::cout << r2::linefeed << r2::linefeed;

			Test3();

			return r2::eTestResult::RunTest;
		};
	}
}