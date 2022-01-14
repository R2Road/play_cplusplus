#include "pch.h"
#include "r2_ConsoleMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestResult.h"
#include "r2_RootMenu.h"

#include "test_cpp/console_test.h"

namespace r2
{
	MenuUp ConsoleMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddChild( '1', console_test::GetWindowSize::GetInstance() );
			ret->AddChild( '2', console_test::ChangeWindowSize::GetInstance() );
			ret->AddChild( '3', console_test::WindowPosition::GetInstance() );
			ret->AddChild( '4', console_test::ChangeWindowName::GetInstance() );
			ret->AddChild( '5', console_test::HideTitleBar::GetInstance() );
			ret->AddChild( '6', console_test::CursorMove::GetInstance() );
			ret->AddChild( '7', console_test::CursorVisibility::GetInstance() );

			
			ret->AddLineFeed();


			ret->AddChild( 'q', console_test::ColorTable::GetInstance() );
			ret->AddChild( 'w', console_test::TextColor1::GetInstance() );
			ret->AddChild( 'e', console_test::TextColor2::GetInstance() );
			ret->AddChild( 'r', console_test::AdjustColorTable::GetInstance() );


			ret->AddLineFeed();


			ret->AddChild( 't', console_test::ColorTable2::GetInstance() );
			ret->AddChild( 'y', console_test::TextColor3::GetInstance() );


			ret->AddLineFeed();


			ret->AddChild( 'a', console_test::Pixel::GetInstance() );
			ret->AddChild( 's', console_test::DoubleBuffering::GetInstance() );


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