#include "pch.h"
#include "assert_test.h"

#include <cassert>

#include "r2_eTestResult.h"

namespace assert_test
{
	const r2::iNode::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Assert : Basic";
		};
	}

	const r2::iNode::DoFunc Basic::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "== Assert ==" << std::endl << std::endl;

			std::cout << std::endl;

			{
				std::cout << "\t" << "+ assert( 1 > 2 && \"What The Fuck\" );" << std::endl << std::endl;
				assert( 1 > 2 && "What The Fuck" );
			}

			std::cout << std::endl << std::endl;

			return r2::eTestResult::RunTest;
		};
	}
}