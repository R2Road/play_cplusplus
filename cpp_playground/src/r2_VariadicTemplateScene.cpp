#include "pch.h"
#include "r2_VariadicTemplateScene.h"

#include "r2_Director.h"
#include "r2_eTestResult.h"
#include "r2_RootScene.h"

#include "variadic_template_test.h"

namespace r2
{
	SceneUp VariadicTemplateScene::Create( Director& director )
	{
		SceneUp ret( new ( std::nothrow ) Scene( director, GetTitle() ) );

		{
			ret->AddChild( '1', variadic_template_test::PrintValues::GetInstance() );
			ret->AddChild( '2', variadic_template_test::SumValues::GetInstance() );
			ret->AddChild( '3', variadic_template_test::SubtractValues::GetInstance() );
			ret->AddChild( '4', variadic_template_test::SizeOfArgs::GetInstance() );


			ret->AddSplit();


			ret->AddChild(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->const eTestResult
				{
					director.Setup( r2::RootScene::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);
		}

		return ret;
	}
}