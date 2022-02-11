#include "pch.h"
#include "r2_PointerMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestEndAction.h"
#include "r2_RootMenu.h"

#include "test_cpp/pointer_test.h"

namespace r2
{
	MenuUp PointerMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, "Pointer" ) );

		{
			ret->AddChild( '1', pointer_test::Basic::GetInstance() );
			ret->AddChild( '2', pointer_test::ConstPointer::GetInstance() );


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