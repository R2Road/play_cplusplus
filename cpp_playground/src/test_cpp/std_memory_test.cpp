#include "pch.h"
#include "std_memory_test.h"

#include <memory>
#include <utility>

#include "base/r2_eTestResult.h"

namespace std_memory_test
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
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Shared Pointer" << r2::linefeed << r2::linefeed;

				std::cout << r2::tab2 << "- Make Sp" << r2::linefeed;
				std::cout << r2::tab3 << "std::shared_ptr<int> test_sp( new int( 10 ) )" << r2::linefeed;
				std::shared_ptr<int> test_sp( new int( 10 ) );

				std::cout << r2::tab4 << "- Print : " << *test_sp << r2::linefeed << r2::linefeed;


				std::cout << r2::tab2 << "- Copy To Const Sp" << r2::linefeed;
				std::cout << r2::tab3 << "const auto test_sp_2 = test_sp;" << r2::linefeed;
				const auto test_sp_2 = test_sp;

				std::cout << r2::linefeed;


				std::cout << r2::tab2 << "- Change Value with Const Sp" << r2::linefeed;
				std::cout << r2::tab3 << "*test_sp_2 = 11;" << r2::linefeed;
				*test_sp_2 = 11;

				std::cout << r2::tab4 << "- Print : " << *test_sp_2 << r2::linefeed;
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Shared Pointer Has Const Value" << r2::linefeed << r2::linefeed;

				std::cout << r2::tab2 << "- Make Sp Has Const Value" << r2::linefeed;
				std::cout << r2::tab3 << "std::shared_ptr<const int> test_sp( new int( 10 ) )" << r2::linefeed;
				std::shared_ptr<const int> const_test_sp( new int( 10 ) );

				std::cout << r2::tab4 << "- Print : " << *const_test_sp << r2::linefeed;
				std::cout << r2::linefeed;

				std::cout << r2::tab2 << "- Failed : Change Value" << r2::linefeed;
				std::cout << r2::linefeed;

				//*const_test_sp = 11;
				//std::cout << r2::tab << "+ Change Value with Sp Has Const Value" << r2::linefeed;
				//std::cout << r2::tab2 << *const_test_sp << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Make Shared" << r2::linefeed << r2::linefeed;

				std::cout << r2::tab2 << "auto test_sp = std::make_shared<int>( 10 );" << r2::linefeed;
				auto test_sp = std::make_shared<int>( 10 );

				std::cout << r2::tab3 << "- Print : " << *test_sp << r2::linefeed;
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}



namespace std_memory_test
{
	r2::iTest::TitleFunc UniquePointer::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Unique Pointer";
		};
	}
	r2::iTest::DoFunc UniquePointer::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				auto test_up = std::unique_ptr<int>( new int( 3 ) );

				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "auto test_up = std::unique_ptr<int>( new int( 3 ) );" << r2::linefeed;


				std::cout << r2::linefeed;


				//auto test_up_2 = test_up;

				std::cout << r2::tab << "+ Move : Failed" << r2::linefeed2;
				std::cout << r2::tab2 << "auto test_up_2 = test_up;" << r2::linefeed;


				std::cout << r2::linefeed;


				auto test_up_2 = std::move( test_up );

				std::cout << r2::tab << "+ Move : Success" << r2::linefeed2;
				std::cout << r2::tab2 << "auto test_up_2 = std::move( test_up );" << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}