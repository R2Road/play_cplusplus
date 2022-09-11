#include "using_test.h"

#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_Inspector.h"

namespace using_test
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Using : Basic( to do )";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}