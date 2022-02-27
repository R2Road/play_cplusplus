#include "pch.h"
#include "r2_EnumMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestEndAction.h"
#include "r2_RootMenu.h"

#include "test_cpp/enum_test.h"

namespace r2
{
	MenuUp EnumMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddChild( '1', enum_test::Basic::GetInstance() );
			ret->AddChild( '2', enum_test::Convert::GetInstance() );


			ret->AddSplit();


			ret->AddChild(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->eTestEndAction
				{
					director.Setup( r2::RootMenu::Create( director ) );
					return r2::eTestEndAction::None;
				}
			);
		}

		return ret;
	}
}