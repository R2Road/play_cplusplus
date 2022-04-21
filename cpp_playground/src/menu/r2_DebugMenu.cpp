#include "pch.h"
#include "r2_DebugMenu.h"

#include "base/r2cm_Director.h"
#include "base/r2cm_eTestEndAction.h"
#include "r2_RootMenu.h"

#include "test_cpp/debug_test.h"

namespace r2
{
	r2cm::MenuUp DebugMenu::Create( r2cm::Director& director )
	{
		r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

		{
			ret->AddItem( '1', debug_test::PredefinedMacro::GetInstance() );
			ret->AddItem( '2', debug_test::OutPutDebugString::GetInstance() );
			ret->AddItem( '3', debug_test::Assertion::GetInstance() );
			ret->AddItem( '4', debug_test::DebugBreak::GetInstance() );
			ret->AddItem( '5', debug_test::MyAssertion::GetInstance() );
			ret->AddItem( '6', debug_test::SimpleLog::GetInstance() );


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