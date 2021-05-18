#include "pch.h"
#include "r2_AlignScene.h"

#include "r2_Director.h"
#include "r2_eTestResult.h"
#include "r2_RootMenu.h"

#include "alignof_test.h"
#include "alignas_test.h"
#include "align_test.h"

namespace r2
{
	MenuUp AlignScene::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddChild( '1', alignof_test::Basic::GetInstance() );
			ret->AddChild( '2', alignof_test::MixedStruct::GetInstance() );


			ret->AddSplit();


			ret->AddChild( 'q', align_test::AlignAs::GetInstance() );


			ret->AddSplit();


			ret->AddChild( 'z', align_test::Align_0::GetInstance() );
			ret->AddChild( 'x', align_test::Align_1::GetInstance() );
			ret->AddChild( 'c', align_test::Align_2::GetInstance() );


			ret->AddSplit();


			ret->AddChild(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->const eTestResult
				{
					director.Setup( r2::RootMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);
		}

		return ret;
	}
}