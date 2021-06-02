#include "pch.h"
#include "vector_test.h"

#include <vector>

#include "base/r2_eTestResult.h"

namespace vector_test
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
				std::cout << r2::tab << "+ Resize" << r2::linefeed;
				std::cout << r2::linefeed;

				std::vector<int> test_vector;
				std::cout << r2::tab2 << "std::vector<int> test_vector;" << r2::linefeed;
				std::cout << r2::linefeed;

				test_vector.resize( 10 );
				std::cout << r2::tab2 << "test_vector.resize( 10 );" << r2::linefeed;
				std::cout << r2::tab3 << "- Size : " << test_vector.size() << r2::linefeed;

				std::cout << r2::linefeed;

				test_vector.resize( 5 );
				std::cout << r2::tab2 << "test_vector.resize( 5 );" << r2::linefeed;
				std::cout << r2::tab3 << "- Size : " << test_vector.size() << r2::linefeed;

				std::cout << r2::linefeed;

				std::cout << r2::tab << "Not Need Clear" << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}