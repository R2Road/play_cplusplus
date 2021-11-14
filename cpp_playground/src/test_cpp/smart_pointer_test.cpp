#include "pch.h"
#include "smart_pointer_test.h"

#include <memory>
#include <utility>

#include "base/r2_eTestResult.h"

namespace smart_pointer_test
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

			std::cout << r2::split;

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

			std::cout << r2::split;

			{
				std::cout << "# Make Shared #" << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "auto test_sp = std::make_shared<int>( 10 );" << r2::linefeed;
				auto test_sp = std::make_shared<int>( 10 );

				std::cout << "\t\t - Print : " << *test_sp << r2::linefeed;
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}



namespace smart_pointer_test
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