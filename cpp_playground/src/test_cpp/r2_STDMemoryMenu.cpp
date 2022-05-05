#include "pch.h"
#include "r2_STDMemoryMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_eTestEndAction.h"
#include "r2_STDMenu.h"

#include "test_cpp/item/std_memory_test.h"

namespace r2
{
	r2cm::MenuUp STDMemoryMenu::Create( r2cm::Director& director )
	{
		r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

		{
			ret->AddItem( '1', std_memory_test::SharedPointer::GetInstance() );
			ret->AddItem( '2', std_memory_test::UniquePointer::GetInstance() );


			ret->AddSplit();


			ret->AddItem(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->r2cm::eTestEndAction
				{
					director.Setup( r2::STDMenu::Create( director ) );
					return r2cm::eTestEndAction::None;
				}
			);
		}

		return ret;
	}
}