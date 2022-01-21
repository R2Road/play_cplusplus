#include "pch.h"
#include "assert_test.h"

#include <cassert>

#include "base/r2_eTestResult.h"

namespace assert_test
{
	r2::iTest::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Assert : Basic";
		};
	}

	r2::iTest::DoFunc Basic::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ assert( 1 > 2 && \"What The Fuck\" );" << r2::linefeed << r2::linefeed;
				assert( 1 > 2 && "What The Fuck" );
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc DebugBreak::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Debug Break";
		};
	}
	r2::iTest::DoFunc DebugBreak::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ __debugbreak();" << r2::linefeed;

				__debugbreak();
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}