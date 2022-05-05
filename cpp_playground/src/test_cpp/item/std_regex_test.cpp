#include "pch.h"
#include "std_regex_test.h"

#include "r2cm/r2cm_eTestEndAction.h"

namespace std_regex_test
{
	r2cm::iItem::TitleFuncT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Regex : Basic( To do )";
		};
	}
	r2cm::iItem::DoFuncT Basic::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()()  << " #" << r2::linefeed;

			std::cout << r2::split;

			{
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}
}