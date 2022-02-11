#include "pch.h"
#include "r2_CharMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestResult.h"
#include "r2_RootMenu.h"

#include "test_cpp/char_test.h"
#include "test_cpp/locale_test.h"

#include "test_cpp/korean_test.h"

namespace r2
{
	MenuUp CharMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddChild( '1', char_test::Basic::GetInstance() );
			ret->AddChild( '2', char_test::Encoding::GetInstance() );
			ret->AddChild( '3', locale_test::Basic::GetInstance() );


			ret->AddLineFeed();


			ret->AddChild( 'z', korean_test::Basic::GetInstance() );


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