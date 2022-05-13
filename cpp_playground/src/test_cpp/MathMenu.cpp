#include "MathMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_constant.h"
#include "RootMenu.h"

namespace r2
{
	r2cm::MenuUp MathMenu::Create( r2cm::Director& director )
	{
		r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

		{
			ret->AddSplit();


			ret->AddItem(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->r2cm::eItemLeaveAction
				{
					director.Setup( RootMenu::Create( director ) );
					return r2cm::eItemLeaveAction::None;
				}
			);
		}

		return ret;
	}
}