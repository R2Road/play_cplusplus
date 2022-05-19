#include "BitOperationMenu.h"

#include "r2cm/r2cm_constant.h"
#include "r2cm/r2cm_Director.h"

#include "item/bit_operation_test.h"

#include "C_CPP_Menu.h"

r2cm::MenuUp BitOperationMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, C_CPP_Menu::GetTitle() ) );

	{
		ret->AddItem( '1', bit_operation_test::Basic::GetInstance() );
		ret->AddItem( '2', bit_operation_test::Complement::GetInstance() );
		ret->AddItem( '3', bit_operation_test::Add_Remove_Toggle::GetInstance() );
		ret->AddItem( '4', bit_operation_test::Mask::GetInstance() );
		ret->AddItem( '5', bit_operation_test::XOR_Swap::GetInstance() );


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