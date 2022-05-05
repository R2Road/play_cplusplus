#include "pch.h"
#include "r2_CharMenu.h"

#include "base/r2cm_Director.h"
#include "base/r2cm_eTestEndAction.h"
#include "RootMenu.h"

#include "test_cpp/item/char_test.h"
#include "test_cpp/item/locale_test.h"

#include "test_cpp/item/korean_test.h"

namespace r2
{
	r2cm::MenuUp CharMenu::Create( r2cm::Director& director )
	{
		r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

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
				, [&director]()->r2cm::eTestEndAction
				{
					director.Setup( RootMenu::Create( director ) );
					return r2cm::eTestEndAction::None;
				}
			);
		}

		return ret;
	}
}