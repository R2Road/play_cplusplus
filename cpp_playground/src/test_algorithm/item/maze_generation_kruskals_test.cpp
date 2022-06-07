#include "maze_generation_kruskals_test.h"

#include "r2cm/r2cm_constant.h"
#include "r2cm/r2cm_Inspector.h"

namespace maze_generation_kruskals_test
{
	r2cm::iItem::TitleFuncT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Kruskals : Basic";
		};
	}
	r2cm::iItem::DoFuncT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed2;

			std::cout << r2cm::split;

			{
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}