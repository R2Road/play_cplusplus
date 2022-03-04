#include "pch.h"
#include "r2_CharMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestEndAction.h"
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
			ret->AddItem( '1', char_test::Basic::GetInstance() );
			ret->AddItem( '2', char_test::Encoding::GetInstance() );
			ret->AddItem( '3', locale_test::Basic::GetInstance() );


			ret->AddLineFeed();


			ret->AddItem( 'z', korean_test::Basic::GetInstance() );


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