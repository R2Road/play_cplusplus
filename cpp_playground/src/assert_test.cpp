#include "assert_test.h"

#include <cassert>
#include <iostream>

namespace assert_test
{
	r2::eTestResult Basic::Do()
	{
		std::cout << "== Assert ==" << std::endl << std::endl;

		std::cout << std::endl;

		{
			std::cout << "\t" << "+ assert( 1 > 2 && \"What The Fuck\" );" << std::endl << std::endl;
			assert( 1 > 2 && "What The Fuck" );
		}

		std::cout << std::endl << std::endl;

		return r2::eTestResult::RunTest;
	}
}