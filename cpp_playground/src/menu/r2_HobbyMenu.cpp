#include "pch.h"
#include "r2_HobbyMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestResult.h"
#include "r2_RootMenu.h"

#include "test_hobby/infinite_number_test.h"
#include "test_hobby/vector3_test.h"

#include "menu/r2_ArrayBasedListMenu.h"
#include "menu/r2_MemoryPoolMenu.h"

namespace r2
{
	MenuUp HobbyMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddChild(
				'1'
				, []()->const char* { return r2::MemoryPoolMenu::GetTitle(); }
				, [&director]()->eTestEndAction
				{
					director.Setup( r2::MemoryPoolMenu::Create( director ) );
					return eTestEndAction::ChangeScene;
				}
			);


			ret->AddSplit();


			ret->AddChild( 'q', infinite_number_test::Basic::GetInstance() );


			ret->AddSplit();


			ret->AddChild( 'a', vector3_test::OperatorPlus::GetInstance() );
			ret->AddChild( 's', vector3_test::OperatorPlusEqual::GetInstance() );
			ret->AddChild( 'd', vector3_test::OperatorMinus::GetInstance() );
			ret->AddChild( 'f', vector3_test::OperatorMinusEqual::GetInstance() );
			ret->AddChild( 'g', vector3_test::OperatorMultiply_With_Scalar::GetInstance() );
			ret->AddChild( 'h', vector3_test::OperatorMultiplyEqual_With_Scalar::GetInstance() );


			ret->AddSplit();


			ret->AddChild(
				'z'
				, []()->const char* { return r2::ArrayBasedListMenu::GetTitle(); }
				, [&director]()->eTestEndAction
				{
					director.Setup( r2::ArrayBasedListMenu::Create( director ) );
					return eTestEndAction::ChangeScene;
				}
			);


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