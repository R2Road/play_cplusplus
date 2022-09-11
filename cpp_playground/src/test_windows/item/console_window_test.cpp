#include "console_window_test.h"

#include <bitset>
#include <conio.h>
#include <iomanip>
#include <stdio.h>
#include <Windows.h>
#include <wincon.h> // BACKGROUND_RED

// Windows.h 와 wincon.h 의 include 순서를 바꾸면 빌드에 문제가 생긴다.
// - c:\program files (x86)\windows kits\10\include\10.0.18362.0\um\winnt.h(173): fatal error C1189: #error:  "No Target Architecture"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_WindowUtility.h"

namespace console_window_test
{
	r2cm::iItem::TitleFunctionT BufferInfo::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Buffer Info";
		};
	}
	r2cm::iItem::DoFunctionT BufferInfo::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE ) );
			DECLARATION_MAIN( CONSOLE_SCREEN_BUFFER_INFO console_screen_buffer_info );

			std::cout << r2cm::split;

			EXPECT_TRUE( GetConsoleScreenBufferInfo( hStdout, &console_screen_buffer_info ) );

			std::cout << r2cm::split;

			{
				OUTPUT_VALUE( console_screen_buffer_info.dwCursorPosition.X );
				OUTPUT_VALUE( console_screen_buffer_info.dwCursorPosition.Y );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( console_screen_buffer_info.dwMaximumWindowSize.X );
				OUTPUT_VALUE( console_screen_buffer_info.dwMaximumWindowSize.Y );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( console_screen_buffer_info.dwSize.X );
				OUTPUT_VALUE( console_screen_buffer_info.dwSize.Y );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( console_screen_buffer_info.srWindow.Left );
				OUTPUT_VALUE( console_screen_buffer_info.srWindow.Top );
				OUTPUT_VALUE( console_screen_buffer_info.srWindow.Right );
				OUTPUT_VALUE( console_screen_buffer_info.srWindow.Bottom );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( console_screen_buffer_info.wAttributes );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT ChangeWindowSize::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Change Window Size";
		};
	}
	r2cm::iItem::DoFunctionT ChangeWindowSize::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			{
				system( "mode con lines=30 cols=120" );
				ShowScrollBar( GetConsoleWindow(), SB_VERT, 1 );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Process" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "system( \"mode con lines = 30 cols = 120\" );" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE ) );
				DECLARATION_MAIN( CONSOLE_SCREEN_BUFFER_INFO csbi );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( GetConsoleScreenBufferInfo( hStdout, &csbi ) );
				DECLARATION_MAIN( const auto width = static_cast<int>( csbi.srWindow.Right - csbi.srWindow.Left + 1 ) );
				DECLARATION_MAIN( const auto height = static_cast<int>( csbi.srWindow.Bottom - csbi.srWindow.Top + 1 ) );
				OUTPUT_VALUE( width );
				OUTPUT_VALUE( height );
			}

			std::cout << r2cm::split;

			std::cout << "Press Any Key : Roll Back Window Size" << r2cm::linefeed;
			_getch();

			{
				system( "mode con lines=60 cols=120" );
				ShowScrollBar( GetConsoleWindow(), SB_VERT, 1 );
			}

			return r2cm::eItemLeaveAction::None;
		};
	}



	r2cm::iItem::TitleFunctionT FullScreen::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "FullScreen";
		};
	}
	r2cm::iItem::DoFunctionT FullScreen::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "# Alt + Enter" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( SendMessage( ::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000 ) );
			}

			std::cout << r2cm::split;

			std::cout << "Press Any Key : Roll Back Window Size" << r2cm::linefeed;
			_getch();

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( SendMessage( ::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000 ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Focus::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Focus";
		};
	}
	r2cm::iItem::DoFunctionT Focus::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			std::cout << "[Any Key] End" << r2cm::linefeed2;

			const HWND hwnd = GetConsoleWindow();
			const auto last_cursor_point = r2cm::WindowUtility::GetCursorPoint();
			while( true )
			{
				r2cm::WindowUtility::MoveCursorPoint( last_cursor_point );

				if( hwnd == GetForegroundWindow() )
				{
					std::cout << "Focus : " << std::setw( 5 ) << "On";
				}
				else
				{
					std::cout << "Focus : " << std::setw( 5 ) << "Off";
				}

				if( _kbhit() )
				{
					if( 27 == _getch() )
					{
						break;
					}
				}
			}
			return r2cm::eItemLeaveAction::None;
		};
	}



	r2cm::iItem::TitleFunctionT WindowPosition::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Window Position";
		};
	}
	r2cm::iItem::DoFunctionT WindowPosition::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			HWND hWnd = GetConsoleWindow();
			RECT last_window_rect;

			std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
			std::cout << r2cm::tab2 << "HWND hWnd = GetConsoleWindow();" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "RECT last_window_rect;" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				GetWindowRect( hWnd, &last_window_rect );

				std::cout << r2cm::tab << "+ Backup" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "GetWindowRect( hWnd, &last_window_rect );" << r2cm::linefeed2;

				std::cout << r2cm::tab3
					<< "X : " << last_window_rect.left << "     "
					<< "Y : " << last_window_rect.top << r2cm::linefeed;
				std::cout << r2cm::tab3
					<< "W : " << ( last_window_rect.right - last_window_rect.left ) << "     "
					<< "H : " << ( last_window_rect.bottom - last_window_rect.top ) << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ System Display Info" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "GetSystemMetrics( SM_CXSCREEN );" " > " << GetSystemMetrics( SM_CXSCREEN ) << r2cm::linefeed;
				std::cout << r2cm::tab2 << "GetSystemMetrics( SM_CYSCREEN );" " > " << GetSystemMetrics( SM_CYSCREEN ) << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				const int system_center_x = GetSystemMetrics( SM_CXSCREEN ) / 2;
				const int system_center_y = GetSystemMetrics( SM_CYSCREEN ) / 2;

				const int window_width = ( last_window_rect.right - last_window_rect.left );
				const int window_height = ( last_window_rect.bottom - last_window_rect.top );

				const int posx = system_center_x - ( window_width / 2 );
				const int posy = system_center_y - ( window_height / 2 );

				MoveWindow( hWnd, posx, posy, window_width, window_height, TRUE );

				std::cout << r2cm::tab << "+ Move To Center" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "const int system_center_x = GetSystemMetrics( SM_CXSCREEN ) / 2;" " > " << system_center_x << r2cm::linefeed;
				std::cout << r2cm::tab2 << "const int system_center_y = GetSystemMetrics( SM_CYSCREEN ) / 2;" " > " << system_center_y << r2cm::linefeed2;

				std::cout << r2cm::tab2 << "const int window_width = ( last_window_rect.right - last_window_rect.left );" " > " << window_width << r2cm::linefeed;
				std::cout << r2cm::tab2 << "const int window_height = ( last_window_rect.bottom - last_window_rect.top );" " > " << window_height << r2cm::linefeed2;

				std::cout << r2cm::tab2 << "const int posx = system_center_x - ( window_width / 2 );" " > " << posx << r2cm::linefeed;
				std::cout << r2cm::tab2 << "const int posy = system_center_y - ( window_height / 2 );" " > " << posy << r2cm::linefeed2;

				std::cout << r2cm::tab2 << "MoveWindow( hWnd, posx, posy, window_width, window_height, TRUE );" << r2cm::linefeed2;


				RECT current_window_rect;
				GetWindowRect( hWnd, &current_window_rect );

				std::cout << r2cm::tab2 << "Current Window Position" << r2cm::linefeed;
				std::cout << r2cm::tab3 << " - X : " << current_window_rect.left << r2cm::linefeed;
				std::cout << r2cm::tab3 << " - Y : " << current_window_rect.top << r2cm::linefeed;
			}

			std::cout << r2cm::split;
			
			std::cout << "Press Any Key : Roll Back Window Position" << r2cm::linefeed;
			_getch();

			{
				//
				// Rollback
				//
				MoveWindow(
					hWnd
					, last_window_rect.left, last_window_rect.top
					, last_window_rect.right - last_window_rect.left, last_window_rect.bottom - last_window_rect.top
					, TRUE
				);
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT ChangeWindowName::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Change Window Name";
		};
	}
	r2cm::iItem::DoFunctionT ChangeWindowName::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				TCHAR window_name_string[MAX_PATH];
				GetConsoleTitle( window_name_string, MAX_PATH );

				std::cout << r2cm::tab << " + " << "Current Window Name" << r2cm::linefeed;
				std::wcout << r2cm::tab2 << " - " << window_name_string << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				auto* window_name_string = TEXT( "console_test : ChangeWindowName" );

				SetConsoleTitle( window_name_string );

				std::cout << r2cm::tab << " + " << "New Window Name" << r2cm::linefeed;
				std::wcout << r2cm::tab2 << " - " << window_name_string << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			std::cout << "Press Any Key : Roll Back Window Name" << r2cm::linefeed;
			_getch();

			{
				SetConsoleTitle( TEXT( "cpp_playground" ) );
			}
			_getch();

			return r2cm::eItemLeaveAction::None;
		};
	}



	r2cm::iItem::TitleFunctionT HideTitleBar::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Hide Title Bar";
		};
	}
	r2cm::iItem::DoFunctionT HideTitleBar::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( LONG last_window_style = 0 );

			{
				std::cout << r2cm::tab << "+ Backup" << r2cm::linefeed2;

				PROCESS_MAIN( last_window_style = GetWindowLong( GetConsoleWindow(), GWL_STYLE ) );
				OUTPUT_BINARY( last_window_style );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Lock" << r2cm::linefeed2;

				DECLARATION_MAIN( LONG new_window_style = last_window_style );
				PROCESS_MAIN( new_window_style &= ~( WS_BORDER | WS_CAPTION | WS_THICKFRAME ) );
				PROCESS_MAIN( SetWindowLong( GetConsoleWindow(), GWL_STYLE, new_window_style ) );
				OUTPUT_BINARY( new_window_style );
			}

			std::cout << r2cm::split;

			std::cout << r2cm::tab << "Press Any Key : Rollback" << r2cm::linefeed;
			_getch();

			std::cout << r2cm::split;

			//
			// Rollback
			//
			{
				PROCESS_MAIN( SetWindowLong( GetConsoleWindow(), GWL_STYLE, last_window_style ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT HideScrollBar::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Hide Scroll Bar";
		};
	}
	r2cm::iItem::DoFunctionT HideScrollBar::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			std::cout << r2cm::tab << " + Need : WinUser.h" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Hide" << r2cm::linefeed2;

				PROCESS_MAIN( ShowScrollBar( GetConsoleWindow(), SB_VERT, 0 ) );
			}

			std::cout << r2cm::split;
			
			std::cout << r2cm::tab << "Press Any Key : Rollback" << r2cm::linefeed;
			_getch();

			std::cout << r2cm::split;

			//
			// Rollback
			//
			{
				std::cout << r2cm::tab << "+ Show" << r2cm::linefeed2;

				PROCESS_MAIN( ShowScrollBar( GetConsoleWindow(), SB_VERT, 1 ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT DisableMaximize::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Disable Maximize";
		};
	}
	r2cm::iItem::DoFunctionT DisableMaximize::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( LONG last_window_style = 0 );

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Backup" << r2cm::linefeed2;

				PROCESS_MAIN( last_window_style = GetWindowLong( GetConsoleWindow(), GWL_STYLE ) );
				OUTPUT_BINARY( last_window_style );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Lock" << r2cm::linefeed2;

				DECLARATION_MAIN( LONG new_window_style = last_window_style );
				PROCESS_MAIN( new_window_style &= ~( WS_MAXIMIZEBOX) );
				PROCESS_MAIN( SetWindowLong( GetConsoleWindow(), GWL_STYLE, new_window_style ) );
				OUTPUT_BINARY( new_window_style );

				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "+ 아래 코드를 쓴 경우들이 있어서 남겨둔다. 상황에 따라 갱신에 사용되는 것 같다." << r2cm::linefeed2;

				PROCESS_MAIN( SetWindowPos( GetConsoleWindow(), NULL, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE | SWP_FRAMECHANGED ) );
			}

			std::cout << r2cm::split;

			std::cout << r2cm::tab << "Press Any Key : Rollback" << r2cm::linefeed;
			_getch();

			std::cout << r2cm::split;

			//
			// Rollback
			//
			{
				PROCESS_MAIN( SetWindowLong( GetConsoleWindow(), GWL_STYLE, last_window_style ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT LockWindowResizingByDragging::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Lock Window Resizing By Dragging";
		};
	}
	r2cm::iItem::DoFunctionT LockWindowResizingByDragging::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( LONG last_window_style = 0 );

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Backup" << r2cm::linefeed2;

				PROCESS_MAIN( last_window_style = GetWindowLong( GetConsoleWindow(), GWL_STYLE ) );
				OUTPUT_BINARY( last_window_style );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Lock" << r2cm::linefeed2;

				DECLARATION_MAIN( LONG new_window_style = last_window_style );
				PROCESS_MAIN( new_window_style &= ~( WS_SIZEBOX ) );
				PROCESS_MAIN( SetWindowLong( GetConsoleWindow(), GWL_STYLE, new_window_style ) );
				OUTPUT_BINARY( new_window_style );
			}

			std::cout << r2cm::split;

			std::cout << r2cm::tab << "Press Any Key : Rollback" << r2cm::linefeed;
			_getch();

			std::cout << r2cm::split;

			//
			// Rollback
			//
			{
				PROCESS_MAIN( SetWindowLong( GetConsoleWindow(), GWL_STYLE, last_window_style ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT MenuItem::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Menu Item";
		};
	}
	r2cm::iItem::DoFunctionT MenuItem::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
			DECLARATION_MAIN( HMENU hmenu = GetSystemMenu( GetConsoleWindow(), FALSE ) );

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "Press Any Key : Do" << r2cm::linefeed;
				_getch();
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Process : Close Button Grayed" << r2cm::linefeed2;
				PROCESS_MAIN( EnableMenuItem( hmenu, SC_CLOSE, MF_GRAYED ) );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "Press Any Key : Rollback" << r2cm::linefeed;
				_getch();
			}

			std::cout << r2cm::split;

			{
				//
				// Rollback
				//
				PROCESS_MAIN( EnableMenuItem( hmenu, SC_CLOSE, MF_ENABLED ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT CursorMove::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Cursor Move";
		};
	}
	r2cm::iItem::DoFunctionT CursorMove::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( HANDLE stdHandle = GetStdHandle( STD_OUTPUT_HANDLE ) );
			DECLARATION_MAIN( COORD pos );
			PROCESS_MAIN( pos.X = 20 );
			PROCESS_MAIN( pos.Y = 30 );

			std::cout << r2cm::split;

			std::cout << "[W, A, S, D] : Move" << r2cm::linefeed;
			std::cout << "[SPACE BAR] Foot Print" << r2cm::linefeed;
			std::cout << "[ESC] Exit" << r2cm::linefeed;

			std::cout << r2cm::split;

			PROCESS_MAIN( SetConsoleCursorPosition( stdHandle, pos ) );

			{
				int input = 0;
				do
				{

					SetConsoleCursorPosition( stdHandle, pos );

					input = _getch();
					switch( input )
					{
					case 'w': // up
						pos.Y -= 1;
						break;
					case 's': // down
						pos.Y += 1;
						break;
					case 'a': // left
						pos.X -= 1;
						break;
					case 'd': // right
						pos.X += 1;
						break;

					case 32: // space
						std::cout << "test string";
						break;
					}

				} while( 27 != input );
			}

			return r2cm::eItemLeaveAction::None;
		};
	}

	r2cm::iItem::TitleFunctionT CursorVisibility::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Cursor Visibility";
		};
	}
	r2cm::iItem::DoFunctionT CursorVisibility::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( HANDLE stdHandle = GetStdHandle( STD_OUTPUT_HANDLE ) );
			DECLARATION_MAIN( CONSOLE_CURSOR_INFO cursorInfo );

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Hide" << r2cm::linefeed2;

				PROCESS_MAIN( GetConsoleCursorInfo( stdHandle, &cursorInfo ) );
				PROCESS_MAIN( cursorInfo.bVisible = false );
				PROCESS_MAIN( SetConsoleCursorInfo( stdHandle, &cursorInfo ) );
			}

			std::cout << r2cm::split;

			system( "pause" );

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Show" << r2cm::linefeed2;

				PROCESS_MAIN( GetConsoleCursorInfo( stdHandle, &cursorInfo ) );
				PROCESS_MAIN( cursorInfo.bVisible = true );
				PROCESS_MAIN( SetConsoleCursorInfo( stdHandle, &cursorInfo ) );
			}

			std::cout << r2cm::split;

			system( "pause" );

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::None;
		};
	}




	r2cm::iItem::TitleFunctionT QuickEdit::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Quick Edit";
		};
	}
	r2cm::iItem::DoFunctionT QuickEdit::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			std::cout << r2cm::tab << "# Quick Edit 는 콘솔창에서 마우스를 사용한 커서 이동, 선택이 가능한 옵션이다." << r2cm::linefeed;

			std::cout << r2cm::split;

			DECLARATION_MAIN( DWORD last_console_mode = 0 );

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Backup" << r2cm::linefeed2;

				PROCESS_MAIN( GetConsoleMode( GetStdHandle( STD_INPUT_HANDLE ), &last_console_mode ) );
				OUTPUT_BINARY( last_console_mode );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Disable" << r2cm::linefeed2;

				DECLARATION_MAIN( DWORD new_console_mode = last_console_mode );
				PROCESS_MAIN( new_console_mode |= ENABLE_EXTENDED_FLAGS );
				OUTPUT_BINARY( new_console_mode );
				PROCESS_MAIN( new_console_mode &= ~( ENABLE_QUICK_EDIT_MODE ) );
				PROCESS_MAIN( SetConsoleMode( GetStdHandle( STD_INPUT_HANDLE ), new_console_mode ) );
				OUTPUT_BINARY( new_console_mode );
			}

			std::cout << r2cm::split;

			std::cout << r2cm::tab << "Press Any Key : Rollback" << r2cm::linefeed;
			_getch();

			std::cout << r2cm::split;

			//
			// Rollback
			//
			{
				PROCESS_MAIN( SetConsoleMode( GetStdHandle( STD_INPUT_HANDLE ), last_console_mode ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}