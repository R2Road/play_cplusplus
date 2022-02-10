#include "pch.h"
#include "r2_HobbyMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestResult.h"
#include "r2_RootMenu.h"

#include "test_hobby/infinite_number_test.h"
#include "test_hobby/memory_pool_test.h"
#include "test_hobby/vector3_test.h"

#include "menu/r2_ArrayBasedListMenu.h"

namespace r2
{
	MenuUp HobbyMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddChild( '1', memory_pool_test::Step01::GetInstance() );


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
				, [&director]()->eTestResult
				{
					director.Setup( r2::ArrayBasedListMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);


			ret->AddSplit();


			ret->AddChild(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->eTestResult
				{
					director.Setup( r2::RootMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);
		}

		return ret;
	}
}