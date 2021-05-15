#include "pch.h"
#include "r2_RendererScene.h"

#include "r2_Director.h"
#include "r2_eTestResult.h"
#include "r2_RootScene.h"

#include "rect_test.h"
#include "renderer_test.h"
#include "camera_test.h"

namespace r2
{
	SceneUp RendererScene::Create( Director& director )
	{
		SceneUp ret( new ( std::nothrow ) Scene( director, GetTitle() ) );

		{
			ret->AddChild( '1', renderer_test::VisibleResource_FillAll::GetInstance() );
			ret->AddChild( '2', renderer_test::VisibleResource_Fill::GetInstance() );
			ret->AddChild( '3', renderer_test::VisibleResource_DrawWithPosition::GetInstance() );
			ret->AddChild( '4', renderer_test::VisibleResource_InitWithChars::GetInstance() );


			ret->AddSplit();


			ret->AddChild( 'q', renderer_test::TestRenderable::GetInstance() );
			ret->AddChild( 'w', renderer_test::TestRenderer::GetInstance() );


			ret->AddSplit();


			ret->AddChild( 'a', rect_test::Basic::GetInstance() );
			ret->AddChild( 's', renderer_test::CameraRect::GetInstance() );
			ret->AddChild( 'd', renderer_test::TestCamera::GetInstance() );


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