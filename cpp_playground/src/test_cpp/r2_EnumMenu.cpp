#include "pch.h"
#include "r2_EnumMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_eTestEndAction.h"

#include "test_cpp/item/enum_test.h"

#include "C_CPP_Menu.h"

namespace r2
{
	r2cm::MenuUp EnumMenu::Create( r2cm::Director& director )
	{
		r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

		{
			ret->AddItem( '1', enum_test::Basic::GetInstance() );
			ret->AddItem( '2', enum_test::Convert::GetInstance() );


			ret->AddSplit();


			ret->AddItem(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->r2cm::eTestEndAction
				{
					director.Setup( C_CPP_Menu::Create( director ) );
					return r2cm::eTestEndAction::None;
				}
			);
		}

		return ret;
	}
}