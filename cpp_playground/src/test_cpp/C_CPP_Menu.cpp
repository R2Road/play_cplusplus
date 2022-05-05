#include "pch.h"
#include "C_CPP_Menu.h"

#include "base/r2cm_Director.h"
#include "base/r2cm_eTestEndAction.h"

#include "RootMenu.h"

r2cm::MenuUp C_CPP_Menu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, C_CPP_Menu::GetTitle() ) );

	{
		//ret->AddItem( '1', c_random_test::Rand::GetInstance() );


		ret->AddSplit();


		ret->AddItem(
			27
			, []()->const char* { return "Return To Root"; }
			, [&director]()->r2cm::eTestEndAction
			{
				director.Setup( RootMenu::Create( director ) );
				return r2cm::eTestEndAction::None;
			}
		);
	}

	return ret;
}