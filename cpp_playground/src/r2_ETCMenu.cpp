#include "pch.h"
#include "r2_ETCMenu.h"

#include "r2_Director.h"
#include "r2_eTestResult.h"
#include "r2_RootMenu.h"

#include "etc_0_test.h"

namespace r2
{
	MenuUp ETCMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddChild( '1', etc_test::XOR_Swap::GetInstance() );
			ret->AddChild( '2', etc_test::InitArray::GetInstance() );


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


			ret->AddSplit();
		}

		return ret;
	}
}