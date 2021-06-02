#include "pch.h"
#include "r2_MemoryMenu.h"

#include "r2_Director.h"
#include "r2_eTestResult.h"
#include "r2_RootMenu.h"

#include "shared_pointer_test.h"
#include "memory_pool_test.h"

namespace r2
{
	MenuUp MemoryMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddChild( '1', shared_pointer_test::SharedPtr::GetInstance() );


			ret->AddLineFeed();


			ret->AddChild( 'q', memory_pool_test::Step01::GetInstance() );


			ret->AddSplit();


			ret->AddChild(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->eTestResult
				{
					director.Setup( r2::RootMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);
		}

		return ret;
	}
}