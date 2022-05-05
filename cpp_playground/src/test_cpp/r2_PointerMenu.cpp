#include "pch.h"
#include "r2_PointerMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_eTestEndAction.h"
#include "RootMenu.h"

#include "test_cpp/item/pointer_test.h"

namespace r2
{
	r2cm::MenuUp PointerMenu::Create( r2cm::Director& director )
	{
		r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, "Pointer" ) );

		{
			ret->AddItem( '1', pointer_test::Basic::GetInstance() );
			ret->AddItem( '2', pointer_test::ConstPointer::GetInstance() );


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