#include "NewMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_constant.h"

#include "test_cpp/item/new_test.h"

#include "C_CPP_Menu.h"

r2cm::MenuUp NewMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', new_test::Basic::GetInstance() );
		ret->AddItem( '2', new_test::PlacementNew::GetInstance() );


		ret->AddSplit();


		ret->AddItem(
			27
			, []()->const char* { return "Return To Root"; }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( C_CPP_Menu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
	}

	return ret;
}