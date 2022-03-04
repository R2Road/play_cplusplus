#include "pch.h"
#include "r2_DebugMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestEndAction.h"
#include "r2_RootMenu.h"

#include "test_cpp/debug_test.h"

namespace r2
{
	MenuUp DebugMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddItem( '1', debug_test::PredefinedMacro::GetInstance() );
			ret->AddItem( '2', debug_test::OutPutDebugString::GetInstance() );
			ret->AddItem( '3', debug_test::Assertion::GetInstance() );
			ret->AddItem( '4', debug_test::DebugBreak::GetInstance() );
			ret->AddItem( '5', debug_test::MyAssertion::GetInstance() );


			ret->AddSplit();


			ret->AddItem(
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