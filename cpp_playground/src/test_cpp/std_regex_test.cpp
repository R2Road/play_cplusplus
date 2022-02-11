#include "pch.h"
#include "std_regex_test.h"

#include "base/r2_eTestEndAction.h"

namespace std_regex_test
{
	r2::iTest::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Regex : Basic( To do )";
		};
	}
	r2::iTest::DoFunc Basic::GetDoFunction()
	{
		return []()->r2::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()()  << " #" << r2::linefeed;

			std::cout << r2::split;

			{
			}

			std::cout << r2::split;

			return r2::eTestEndAction::Pause;
		};
	}
}