#include "pch.h"
#include "r2_ConsoleMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestResult.h"
#include "r2_RootMenu.h"

#include "test_cpp/console_buffer_test.h"
#include "test_cpp/console_test.h"
#include "test_cpp/console_text_color_test.h"
#include "test_cpp/console_window_test.h"

namespace r2
{
	MenuUp ConsoleMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddChild( '1', console_window_test::BufferInfo::GetInstance() );
			ret->AddChild( '2', console_window_test::ChangeWindowSize::GetInstance() );
			ret->AddChild( '3', console_window_test::WindowPosition::GetInstance() );
			ret->AddChild( '4', console_window_test::ChangeWindowName::GetInstance() );
			ret->AddChild( '5', console_window_test::HideTitleBar::GetInstance() );
			ret->AddChild( '6', console_window_test::HideScrollBar::GetInstance() );
			ret->AddChild( '7', console_window_test::LockWindowResizingByDragging::GetInstance() );

			ret->AddLineFeed();

			ret->AddChild( '8', console_window_test::CursorMove::GetInstance() );
			ret->AddChild( '9', console_window_test::CursorVisibility::GetInstance() );

			
			ret->AddLineFeed();
			ret->AddLineFeed();


			ret->AddChild( 'q', console_text_color_test::ColorTable::GetInstance() );
			ret->AddChild( 'w', console_text_color_test::TextColor1::GetInstance() );
			ret->AddChild( 'e', console_text_color_test::TextColor2::GetInstance() );
			ret->AddChild( 'r', console_text_color_test::AdjustColorTable::GetInstance() );

			ret->AddLineFeed();

			ret->AddChild( 't', console_text_color_test::ColorTable2::GetInstance() );
			ret->AddChild( 'y', console_text_color_test::TextColor3::GetInstance() );

			ret->AddLineFeed();

			ret->AddChild( 'a', console_test::FontInfo::GetInstance() );
			ret->AddChild( 's', console_test::FontChange::GetInstance() );


			ret->AddLineFeed();
			ret->AddLineFeed();


			ret->AddChild( 'z', console_test::Pixel::GetInstance() );
			ret->AddChild( 'x', console_buffer_test::FillBuffer::GetInstance() );
			ret->AddChild( 'c', console_buffer_test::Write2Buffer::GetInstance() );
			ret->AddChild( 'v', console_buffer_test::DoubleBuffering::GetInstance() );


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