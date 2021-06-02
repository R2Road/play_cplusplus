#include "pch.h"
#include "r2_RenderMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestResult.h"
#include "r2_RootMenu.h"

#include "test_render/rect_test.h"
#include "test_render/visibleresource_test.h"
#include "test_render/renderer_test.h"
#include "test_render/camera_test.h"
#include "test_render/animation_test.h"

namespace r2
{
	MenuUp RenderMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddChild( '1', visibleresource_test::FillAll::GetInstance() );
			ret->AddChild( '2', visibleresource_test::Fill::GetInstance() );
			ret->AddChild( '3', visibleresource_test::DrawWithPosition::GetInstance() );
			ret->AddChild( '4', visibleresource_test::InitWithChars::GetInstance() );
			ret->AddChild( '5', visibleresource_test::VisibleRect::GetInstance() );


			ret->AddLineFeed();


			ret->AddChild( 'q', renderer_test::TestRenderable::GetInstance() );
			ret->AddChild( 'w', renderer_test::TestRenderer::GetInstance() );


			ret->AddLineFeed();


			ret->AddChild( 'a', rect_test::Basic::GetInstance() );
			ret->AddChild( 's', camera_test::CameraRect::GetInstance() );
			ret->AddChild( 'd', camera_test::CameraMove1::GetInstance() );
			ret->AddChild( 'f', camera_test::CameraMove2::GetInstance() );


			ret->AddSplit();


			ret->AddChild( 'z', animation_test::Basic::GetInstance() );


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