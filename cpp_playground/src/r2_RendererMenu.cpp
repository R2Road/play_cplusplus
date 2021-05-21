#include "pch.h"
#include "r2_RendererMenu.h"

#include "r2_Director.h"
#include "r2_eTestResult.h"
#include "r2_RootMenu.h"

#include "rect_test.h"
#include "visibleresource_test.h"
#include "renderer_test.h"
#include "camera_test.h"

namespace r2
{
	MenuUp RendererMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddChild( '1', visibleresource_test::FillAll::GetInstance() );
			ret->AddChild( '2', visibleresource_test::Fill::GetInstance() );
			ret->AddChild( '3', visibleresource_test::DrawWithPosition::GetInstance() );
			ret->AddChild( '4', visibleresource_test::InitWithChars::GetInstance() );


			ret->AddLineFeed();


			ret->AddChild( 'q', renderer_test::TestRenderable::GetInstance() );
			ret->AddChild( 'w', renderer_test::TestRenderer::GetInstance() );


			ret->AddLineFeed();


			ret->AddChild( 'a', rect_test::Basic::GetInstance() );
			ret->AddChild( 's', renderer_test::CameraRect::GetInstance() );
			ret->AddChild( 'd', renderer_test::CameraMove::GetInstance() );


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


			ret->AddSplit();
		}

		return ret;
	}
}