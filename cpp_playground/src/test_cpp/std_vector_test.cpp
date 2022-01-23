#include "pch.h"
#include "std_vector_test.h"

#include <vector>

#include "base/r2_eTestResult.h"

namespace std_vector_test
{
	r2::iTest::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector : Basic";
		};
	}
	r2::iTest::DoFunc Basic::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()()  << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Resize" << r2::linefeed2;

				std::vector<int> test_vector = { 1, 2, 3, 4 };
				std::cout << r2::tab2 << "std::vector<int> test_vector = { 1, 2, 3, 4 };" << r2::linefeed;
				std::cout << r2::tab2 << "- Print : ";
				for( const auto i : test_vector )
				{
					std::cout << i;
				}

				std::cout << r2::linefeed2;

				test_vector.resize( 10 );
				std::cout << r2::tab2 << "test_vector.resize( 10 );" << r2::linefeed;
				std::cout << r2::tab2 << "- Print : ";
				for( const auto i : test_vector )
				{
					std::cout << i;
				}

				std::cout << r2::linefeed2;

				test_vector.resize( 2 );
				std::cout << r2::tab2 << "test_vector.resize( 2 );" << r2::linefeed;
				std::cout << r2::tab2 << "- Print : ";
				for( const auto i : test_vector )
				{
					std::cout << i;
				}

				std::cout << r2::linefeed2;

				test_vector.resize( 20 );
				std::cout << r2::tab2 << "test_vector.resize( 10 );" << r2::linefeed;
				std::cout << r2::tab2 << "- Print : ";
				for( const auto i : test_vector )
				{
					std::cout << i;
				}

				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}