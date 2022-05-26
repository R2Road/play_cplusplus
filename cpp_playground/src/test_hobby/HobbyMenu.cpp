#include "HobbyMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_constant.h"
#include "RootMenu.h"

#include "test_hobby/item/fsm_v1_test.h"
#include "test_hobby/item/infinite_number_test.h"
#include "test_hobby/item/vector3_test.h"

#include "ArrayBasedListMenu.h"
#include "MemoryPoolMenu.h"

r2cm::MenuUp HobbyMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem(
			'1'
			, []()->const char* { return MemoryPoolMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( MemoryPoolMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
		ret->AddItem( '2', fsm_v1_test::Basic::GetInstance() );


		ret->AddSplit();


		ret->AddItem( 'q', infinite_number_test::Basic::GetInstance() );


		ret->AddSplit();


		ret->AddItem( 'a', vector3_test::OperatorPlus::GetInstance() );
		ret->AddItem( 's', vector3_test::OperatorPlusEqual::GetInstance() );
		ret->AddItem( 'd', vector3_test::OperatorMinus::GetInstance() );
		ret->AddItem( 'f', vector3_test::OperatorMinusEqual::GetInstance() );
		ret->AddItem( 'g', vector3_test::OperatorMultiply_With_Scalar::GetInstance() );
		ret->AddItem( 'h', vector3_test::OperatorMultiplyEqual_With_Scalar::GetInstance() );


		ret->AddSplit();


		ret->AddItem(
			'z'
			, []()->const char* { return ArrayBasedListMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( ArrayBasedListMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);


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