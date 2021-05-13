#include "pch.h"
#include "r2_TemplatePracticeScene.h"

#include "r2_Director.h"
#include "r2_eTestResult.h"
#include "r2_TemplateScene.h"

#include "template_practice_part_01_test.h"

namespace r2
{
	SceneUp TemplatePracticeScene::Create( Director& director )
	{
		SceneUp ret( new ( std::nothrow ) Scene( director, GetTitle() ) );

		{
			ret->AddChild( '1', template_practice_part_01_test::Practice01::GetInstance() );
			ret->AddChild( '2', template_practice_part_01_test::VaridicMax::GetInstance() );


			ret->AddSplit();


			ret->AddChild(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->const eTestResult
				{
					director.Setup( r2::TemplateScene::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);
		}

		return ret;
	}
}