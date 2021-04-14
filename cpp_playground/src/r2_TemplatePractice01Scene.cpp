#include "pch.h"
#include "r2_TemplatePractice01Scene.h"

#include "r2_Director.h"
#include "r2_eTestResult.h"
#include "r2_TemplateScene.h"

#include "template_meta_programming_test.h"

namespace r2
{
	SceneUp TemplatePractice01Scene::Create( Director& director )
	{
		SceneUp ret( new ( std::nothrow ) Scene( director, "Template Practice 01" ) );

		{
			ret->AddChild(
				27
				, []()->const char* { return "\nESC : Return To Root"; }
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