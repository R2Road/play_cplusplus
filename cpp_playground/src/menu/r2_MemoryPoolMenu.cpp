#include "pch.h"
#include "r2_MemoryPoolMenu.h"

#include "base/r2cm_Director.h"
#include "base/r2cm_eTestEndAction.h"
#include "r2_HobbyMenu.h"

#include "test_hobby/memory_pool_test.h"

namespace r2
{
	r2cm::MenuUp MemoryPoolMenu::Create( r2cm::Director& director )
	{
		r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

		{
			ret->AddItem( '1', memory_pool_test::Step01::GetInstance() );


			ret->AddSplit();


			ret->AddItem(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->r2cm::eTestEndAction
				{
					director.Setup( r2::HobbyMenu::Create( director ) );
					return r2cm::eTestEndAction::None;
				}
			);
		}

		return ret;
	}
}