#include "pch.h"
#include "r2_STDMemoryMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestEndAction.h"
#include "r2_STDMenu.h"

#include "test_cpp/std_memory_test.h"

namespace r2
{
	MenuUp STDMemoryMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddChild( '1', std_memory_test::SharedPointer::GetInstance() );
			ret->AddChild( '2', std_memory_test::UniquePointer::GetInstance() );


			ret->AddSplit();


			ret->AddChild(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->eTestEndAction
				{
					director.Setup( r2::STDMenu::Create( director ) );
					return eTestEndAction::ChangeScene;
				}
			);
		}

		return ret;
	}
}