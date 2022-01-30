#include "pch.h"
#include "r2_MemoryMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestResult.h"
#include "r2_STDMenu.h"

#include "test_cpp/std_memory_test.h"

namespace r2
{
	MenuUp MemoryMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddChild( '1', std_memory_test::SharedPointer::GetInstance() );
			ret->AddChild( '2', std_memory_test::UniquePointer::GetInstance() );


			ret->AddSplit();


			ret->AddChild(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->eTestResult
				{
					director.Setup( r2::STDMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);
		}

		return ret;
	}
}