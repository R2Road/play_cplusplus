#include "pch.h"
#include "r2_HobbyMenu.h"

#include "base/r2cm_Director.h"
#include "base/r2cm_eTestEndAction.h"
#include "menu/r2_RootMenu.h"

#include "test_hobby/item/infinite_number_test.h"
#include "test_hobby/item/vector3_test.h"

#include "r2_ArrayBasedListMenu.h"
#include "r2_MemoryPoolMenu.h"

namespace r2
{
	r2cm::MenuUp HobbyMenu::Create( r2cm::Director& director )
	{
		r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

		{
			ret->AddItem(
				'1'
				, []()->const char* { return r2::MemoryPoolMenu::GetTitle(); }
				, [&director]()->r2cm::eTestEndAction
				{
					director.Setup( r2::MemoryPoolMenu::Create( director ) );
					return r2cm::eTestEndAction::None;
				}
			);


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
				, []()->const char* { return r2::ArrayBasedListMenu::GetTitle(); }
				, [&director]()->r2cm::eTestEndAction
				{
					director.Setup( r2::ArrayBasedListMenu::Create( director ) );
					return r2cm::eTestEndAction::None;
				}
			);


			ret->AddSplit();


			ret->AddItem(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->r2cm::eTestEndAction
				{
					director.Setup( r2::RootMenu::Create( director ) );
					return r2cm::eTestEndAction::None;
				}
			);
		}

		return ret;
	}
}