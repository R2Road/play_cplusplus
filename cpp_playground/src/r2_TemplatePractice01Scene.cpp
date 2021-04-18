#include "pch.h"
#include "r2_TemplatePractice01Scene.h"

#include "r2_Director.h"
#include "r2_eTestResult.h"
#include "r2_TemplateScene.h"

#include "template_practice_part_01_test.h"
#include "template_practice_part_02_test.h"

namespace r2
{
	SceneUp TemplatePractice01Scene::Create( Director& director )
	{
		SceneUp ret( new ( std::nothrow ) Scene( director, GetTitle() ) );

		{
			ret->AddChild( '1', template_practice_part_01_test::Practice01::GetInstance() );

			ret->AddChild( 'q', template_practice_part_02_test::GreatestCommonDivisor::GetInstance() );

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