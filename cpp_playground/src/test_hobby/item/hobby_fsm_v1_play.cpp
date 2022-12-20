#include "hobby_fsm_v1_play.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace
{
	class Machine
	{
	};
}

namespace hobby_fsm_v1_play
{
	r2cm::iItem::TitleFunctionT Machine_Declaration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "fsm v1 : Machine - Declaration";
		};
	}
	r2cm::iItem::DoFunctionT Machine_Declaration::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( Machine m );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}