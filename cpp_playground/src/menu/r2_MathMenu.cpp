#include "pch.h"
#include "r2_MathMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestResult.h"
#include "r2_RootMenu.h"

namespace r2
{
	MenuUp MathMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddSplit();


			ret->AddChild(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->eTestEndAction
				{
					director.Setup( r2::RootMenu::Create( director ) );
					return eTestEndAction::ChangeScene;
				}
			);
		}

		return ret;
	}
}