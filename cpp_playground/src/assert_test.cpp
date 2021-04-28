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
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed << r2::linefeed;

			std::cout << r2::linefeed;

			{
				std::cout << "\t" << "+ assert( 1 > 2 && \"What The Fuck\" );" << r2::linefeed << r2::linefeed;
				assert( 1 > 2 && "What The Fuck" );
			}

			std::cout << r2::linefeed << r2::linefeed;

			return r2::eTestResult::RunTest;
		};
	}
}