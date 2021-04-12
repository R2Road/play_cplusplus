#include "pch.h"
#include "shared_pointer_test.h"

#include <memory>

#include "r2_eTestResult.h"

namespace
{
	void Test1()
	{
		std::cout << "== Shared Pointer ==" << std::endl << std::endl;

		std::cout << "\t" << "+ Make Sp" << std::endl;
		std::cout << "\t\t" << "std::shared_ptr<int> test_sp( new int( 10 ) )" << std::endl;
		std::shared_ptr<int> test_sp( new int( 10 ) );

		std::cout << "\t\t\t - Print : " << *test_sp << std::endl << std::endl;


		std::cout << "\t" << "+ Copy To Const Sp" << std::endl;
		std::cout << "\t\t" << "const auto test_sp_2 = test_sp;" << std::endl;
		const auto test_sp_2 = test_sp;

		std::cout << std::endl;


		std::cout << "\t" << "+ Change Value with Const Sp" << std::endl;
		std::cout << "\t\t" << "*test_sp_2 = 11;" << std::endl;
		*test_sp_2 = 11;

		std::cout << "\t\t\t - Print : " << *test_sp_2 << std::endl;
		std::cout << std::endl;
	}

	void Test2()
	{
		std::cout << "== Shared Pointer Has Const Value ==" << std::endl << std::endl;

		std::cout << "\t" << "+ Make Sp Has Const Value" << std::endl;
		std::cout << "\t\t" << "std::shared_ptr<const int> test_sp( new int( 10 ) )" << std::endl;
		std::shared_ptr<const int> const_test_sp( new int( 10 ) );

		std::cout << "\t\t\t - Print : " << *const_test_sp << std::endl;
		std::cout << std::endl;

		std::cout << "\t" << "+ Failed : Change Value" << std::endl;
		std::cout << std::endl;

		//*const_test_sp = 11;
		//std::cout << "\t" << "+ Change Value with Sp Has Const Value" << std::endl;
		//std::cout << "\t\t" << *const_test_sp << std::endl;
	}

	void Test3()
	{
		std::cout << "== Make Shared ==" << std::endl << std::endl;

		std::cout << "\t" << "auto test_sp = std::make_shared<int>( 10 );" << std::endl;
		auto test_sp = std::make_shared<int>( 10 );

		std::cout << "\t\t - Print : " << *test_sp << std::endl;
		std::cout << std::endl;
	}
}

namespace shared_pointer_test
{
	const r2::iNode::TitleFunc SharedPtr::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Memory : Shared Pointer";
		};
	}
	const r2::iNode::DoFunc SharedPtr::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			Test1();

			std::cout << std::endl << std::endl;

			Test2();

			std::cout << std::endl << std::endl;

			Test3();

			return r2::eTestResult::RunTest;
		};
	}
}