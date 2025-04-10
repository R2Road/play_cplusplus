#include "windows_terminal_basic_test.h"

#include <bitset>
#include <conio.h>
#include <iomanip>
#include <stdio.h>
#include <Windows.h>
#include <wincon.h> // BACKGROUND_RED

// Windows.h 와 wincon.h 의 include 순서를 바꾸면 빌드에 문제가 생긴다.
// - c:\program files (x86)\windows kits\10\include\10.0.18362.0\um\winnt.h(173): fatal error C1189: #error:  "No Target Architecture"

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_WindowUtility.h"

namespace windows_terminal_basic_test
{
	r2tm::TitleFunctionT BufferInfo::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Buffer Info";
		};
	}
	r2tm::DoFunctionT BufferInfo::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE ) );
			DECLARATION_MAIN( CONSOLE_SCREEN_BUFFER_INFO console_screen_buffer_info );

			LS();

			EXPECT_TRUE( GetConsoleScreenBufferInfo( hStdout, &console_screen_buffer_info ) );

			LS();

			{
				OUTPUT_VALUE( console_screen_buffer_info.dwCursorPosition.X );
				OUTPUT_VALUE( console_screen_buffer_info.dwCursorPosition.Y );

				LF();

				OUTPUT_VALUE( console_screen_buffer_info.dwMaximumWindowSize.X );
				OUTPUT_VALUE( console_screen_buffer_info.dwMaximumWindowSize.Y );

				LF();

				OUTPUT_VALUE( console_screen_buffer_info.dwSize.X );
				OUTPUT_VALUE( console_screen_buffer_info.dwSize.Y );

				LF();

				OUTPUT_VALUE( console_screen_buffer_info.srWindow.Left );
				OUTPUT_VALUE( console_screen_buffer_info.srWindow.Top );
				OUTPUT_VALUE( console_screen_buffer_info.srWindow.Right );
				OUTPUT_VALUE( console_screen_buffer_info.srWindow.Bottom );

				LF();

				OUTPUT_VALUE( console_screen_buffer_info.wAttributes );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT ChangeWindowSize::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Change Window Size";
		};
	}
	r2tm::DoFunctionT ChangeWindowSize::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			{
				system( "mode con lines=30 cols=120" );
				ShowScrollBar( GetConsoleWindow(), SB_VERT, 1 );
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Process" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "system( \"mode con lines = 30 cols = 120\" );" << r2tm::linefeed;
			}

			LS();

			{
				DECLARATION_MAIN( HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE ) );
				DECLARATION_MAIN( CONSOLE_SCREEN_BUFFER_INFO csbi );

				LF();

				PROCESS_MAIN( GetConsoleScreenBufferInfo( hStdout, &csbi ) );
				DECLARATION_MAIN( const auto width = static_cast<int>( csbi.srWindow.Right - csbi.srWindow.Left + 1 ) );
				DECLARATION_MAIN( const auto height = static_cast<int>( csbi.srWindow.Bottom - csbi.srWindow.Top + 1 ) );
				OUTPUT_VALUE( width );
				OUTPUT_VALUE( height );

				LF();

				printf_s(
					"         1         2         3         4         5         6         7         8         9         0         1         2\n"
					"0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890\n\n"
				);
			}

			LS();

			std::cout << "Press Any Key : Roll Back Window Size" << r2tm::linefeed;
			_getch();

			{
				system( "mode con lines=60 cols=120" );
				ShowScrollBar( GetConsoleWindow(), SB_VERT, 1 );
			}

			return r2tm::eDoLeaveAction::None;
		};
	}



	r2tm::TitleFunctionT FullScreen::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "FullScreen";
		};
	}
	r2tm::DoFunctionT FullScreen::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				std::cout << r2tm::tab << "# Alt + Enter" << r2tm::linefeed;
			}

			LS();

			{
				PROCESS_MAIN( SendMessage( ::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000 ) );
			}

			LS();

			std::cout << "Press Any Key : Roll Back Window Size" << r2tm::linefeed;
			_getch();

			LS();

			{
				PROCESS_MAIN( SendMessage( ::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000 ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Focus::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Focus";
		};
	}
	r2tm::DoFunctionT Focus::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			std::cout << "[Any Key] End" << r2tm::linefeed2;

			const HWND hwnd = GetConsoleWindow();
			const auto last_cursor_point = r2tm::WindowUtility::GetCursorPoint();
			while( true )
			{
				r2tm::WindowUtility::MoveCursorPoint( last_cursor_point );

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
			return r2tm::eDoLeaveAction::None;
		};
	}



	r2tm::TitleFunctionT WindowPosition::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Window Position";
		};
	}
	r2tm::DoFunctionT WindowPosition::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( HWND hWnd = GetConsoleWindow() );
			DECLARATION_MAIN( RECT last_window_rect );

			LS();

			{
				std::cout << r2tm::tab << "+ Backup" << r2tm::linefeed2;

				PROCESS_MAIN( GetWindowRect( hWnd, &last_window_rect ) );

				std::cout << r2tm::tab
					<< "X : " << last_window_rect.left << "     "
					<< "Y : " << last_window_rect.top << "     "
					<< "W : " << ( last_window_rect.right - last_window_rect.left ) << "     "
					<< "H : " << ( last_window_rect.bottom - last_window_rect.top ) << r2tm::linefeed;
			}

			LS();

			{
				std::cout << r2tm::tab << "+ System Display Info" << r2tm::linefeed2;
				OUTPUT_VALUE( GetSystemMetrics( SM_CXSCREEN ) );
				OUTPUT_VALUE( GetSystemMetrics( SM_CYSCREEN ) );
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Move To Center" << r2tm::linefeed;

				DECLARATION_MAIN( const int system_center_x = GetSystemMetrics( SM_CXSCREEN ) / 2 );
				DECLARATION_MAIN( const int system_center_y = GetSystemMetrics( SM_CYSCREEN ) / 2 );
				OUTPUT_VALUE( system_center_x );
				OUTPUT_VALUE( system_center_y );

				DECLARATION_MAIN( const int window_width = ( last_window_rect.right - last_window_rect.left ) );
				DECLARATION_MAIN( const int window_height = ( last_window_rect.bottom - last_window_rect.top ) );
				OUTPUT_VALUE( window_width );
				OUTPUT_VALUE( window_height );

				DECLARATION_MAIN( const int posx = system_center_x - ( window_width / 2 ) );
				DECLARATION_MAIN( const int posy = system_center_y - ( window_height / 2 ) );
				OUTPUT_VALUE( posx );
				OUTPUT_VALUE( posy );

				PROCESS_MAIN( MoveWindow( hWnd, posx, posy, window_width, window_height, TRUE ) );

				LF();

				RECT current_window_rect;
				GetWindowRect( hWnd, &current_window_rect );

				std::cout << r2tm::tab << "Current Window Position" << r2tm::linefeed;
				std::cout << r2tm::tab2
					<< "X : " << current_window_rect.left << "     "
					<< "Y : " << current_window_rect.top << r2tm::linefeed;
			}

			LS();
			
			std::cout << "Press Any Key : Roll Back Window Position" << r2tm::linefeed;
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

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT ChangeWindowName::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Change Window Name";
		};
	}
	r2tm::DoFunctionT ChangeWindowName::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			std::cout << r2tm::tab << " + Last Window Name" << r2tm::linefeed2;

			DECLARATION_MAIN( char last_window_name_string[MAX_PATH] );
			PROCESS_MAIN( GetConsoleTitleA( last_window_name_string, MAX_PATH ) );

			LF();

			OUTPUT_VALUE( last_window_name_string );

			LS();

			{
				std::cout << r2tm::tab << " + Change Window Name" << r2tm::linefeed2;

				DECLARATION_MAIN( const char* window_name_string = "console_test : ChangeWindowName" );
				PROCESS_MAIN( SetConsoleTitleA( window_name_string ) );
			}

			LS();

			{
				std::cout << r2tm::tab << "Press Any Key : Roll Back Window Name" << r2tm::linefeed;
				_getch();
			}

			LS();

			{
				SetConsoleTitleA( last_window_name_string );
			}

			return r2tm::eDoLeaveAction::None;
		};
	}



	r2tm::TitleFunctionT HideTitleBar::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Hide Title Bar";
		};
	}
	r2tm::DoFunctionT HideTitleBar::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( LONG last_window_style = 0 );

			LS();

			{
				std::cout << r2tm::tab << "+ Backup" << r2tm::linefeed2;

				PROCESS_MAIN( last_window_style = GetWindowLong( GetConsoleWindow(), GWL_STYLE ) );

				LF();

				OUTPUT_BINARY( last_window_style );
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Lock" << r2tm::linefeed2;

				DECLARATION_MAIN( LONG new_window_style = last_window_style );
				PROCESS_MAIN( new_window_style &= ~( WS_BORDER | WS_CAPTION | WS_THICKFRAME ) );
				PROCESS_MAIN( SetWindowLong( GetConsoleWindow(), GWL_STYLE, new_window_style ) );

				LF();

				OUTPUT_BINARY( new_window_style );
			}

			LS();

			{
				std::cout << r2tm::tab << "Press Any Key : Rollback" << r2tm::linefeed;
				_getch();
			}

			LS();

			//
			// Rollback
			//
			{
				PROCESS_MAIN( SetWindowLong( GetConsoleWindow(), GWL_STYLE, last_window_style ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT HideScrollBar::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Hide Scroll Bar";
		};
	}
	r2tm::DoFunctionT HideScrollBar::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			std::cout << r2tm::tab << " + Need : WinUser.h" << r2tm::linefeed;

			LS();

			{
				std::cout << r2tm::tab << "+ Hide" << r2tm::linefeed2;

				PROCESS_MAIN( ShowScrollBar( GetConsoleWindow(), SB_VERT, 0 ) );
			}

			LS();
			
			std::cout << r2tm::tab << "Press Any Key : Rollback" << r2tm::linefeed;
			_getch();

			LS();

			//
			// Rollback
			//
			{
				std::cout << r2tm::tab << "+ Show" << r2tm::linefeed2;

				PROCESS_MAIN( ShowScrollBar( GetConsoleWindow(), SB_VERT, 1 ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT DisableMaximize::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Disable Maximize";
		};
	}
	r2tm::DoFunctionT DisableMaximize::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( LONG last_window_style = 0 );

			LS();

			{
				std::cout << r2tm::tab << "+ Backup" << r2tm::linefeed2;

				PROCESS_MAIN( last_window_style = GetWindowLong( GetConsoleWindow(), GWL_STYLE ) );
				OUTPUT_BINARY( last_window_style );
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Lock" << r2tm::linefeed2;

				DECLARATION_MAIN( LONG new_window_style = last_window_style );
				PROCESS_MAIN( new_window_style &= ~( WS_MAXIMIZEBOX) );
				PROCESS_MAIN( SetWindowLong( GetConsoleWindow(), GWL_STYLE, new_window_style ) );
				OUTPUT_BINARY( new_window_style );

				LF();

				std::cout << r2tm::tab << "+ 아래 코드를 쓴 경우들이 있어서 남겨둔다. 상황에 따라 갱신에 사용되는 것 같다." << r2tm::linefeed2;

				PROCESS_MAIN( SetWindowPos( GetConsoleWindow(), NULL, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE | SWP_FRAMECHANGED ) );
			}

			LS();

			std::cout << r2tm::tab << "Press Any Key : Rollback" << r2tm::linefeed;
			_getch();

			LS();

			//
			// Rollback
			//
			{
				PROCESS_MAIN( SetWindowLong( GetConsoleWindow(), GWL_STYLE, last_window_style ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT LockWindowResizingByDragging::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Lock Window Resizing By Dragging";
		};
	}
	r2tm::DoFunctionT LockWindowResizingByDragging::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( LONG last_window_style = 0 );

			LS();

			{
				std::cout << r2tm::tab << "+ Backup" << r2tm::linefeed2;

				PROCESS_MAIN( last_window_style = GetWindowLong( GetConsoleWindow(), GWL_STYLE ) );
				OUTPUT_BINARY( last_window_style );
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Lock" << r2tm::linefeed2;

				DECLARATION_MAIN( LONG new_window_style = last_window_style );
				PROCESS_MAIN( new_window_style &= ~( WS_SIZEBOX ) );
				PROCESS_MAIN( SetWindowLong( GetConsoleWindow(), GWL_STYLE, new_window_style ) );
				OUTPUT_BINARY( new_window_style );
			}

			LS();

			std::cout << r2tm::tab << "Press Any Key : Rollback" << r2tm::linefeed;
			_getch();

			LS();

			//
			// Rollback
			//
			{
				PROCESS_MAIN( SetWindowLong( GetConsoleWindow(), GWL_STYLE, last_window_style ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT MenuItem::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Menu Item";
		};
	}
	r2tm::DoFunctionT MenuItem::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			std::cout << r2tm::tab << "+ Declaration" << r2tm::linefeed2;
			DECLARATION_MAIN( HMENU hmenu = GetSystemMenu( GetConsoleWindow(), FALSE ) );

			LS();

			{
				std::cout << r2tm::tab << "Press Any Key : Do" << r2tm::linefeed;
				_getch();
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Process : Close Button Grayed" << r2tm::linefeed2;
				PROCESS_MAIN( EnableMenuItem( hmenu, SC_CLOSE, MF_GRAYED ) );
			}

			LS();

			{
				std::cout << r2tm::tab << "Press Any Key : Rollback" << r2tm::linefeed;
				_getch();
			}

			LS();

			{
				//
				// Rollback
				//
				PROCESS_MAIN( EnableMenuItem( hmenu, SC_CLOSE, MF_ENABLED ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT CursorMove::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Cursor Move";
		};
	}
	r2tm::DoFunctionT CursorMove::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( HANDLE stdHandle = GetStdHandle( STD_OUTPUT_HANDLE ) );
			DECLARATION_MAIN( COORD pos );
			PROCESS_MAIN( pos.X = 20 );
			PROCESS_MAIN( pos.Y = 30 );

			LS();

			std::cout << "[W, A, S, D] : Move" << r2tm::linefeed;
			std::cout << "[SPACE BAR] Foot Print" << r2tm::linefeed;
			std::cout << "[ESC] Exit" << r2tm::linefeed;

			LS();

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

			return r2tm::eDoLeaveAction::None;
		};
	}

	r2tm::TitleFunctionT CursorVisibility::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Cursor Visibility";
		};
	}
	r2tm::DoFunctionT CursorVisibility::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( HANDLE stdHandle = GetStdHandle( STD_OUTPUT_HANDLE ) );
			DECLARATION_MAIN( CONSOLE_CURSOR_INFO cursorInfo );

			LS();

			{
				std::cout << r2tm::tab << "+ Hide" << r2tm::linefeed2;

				PROCESS_MAIN( GetConsoleCursorInfo( stdHandle, &cursorInfo ) );
				PROCESS_MAIN( cursorInfo.bVisible = false );
				PROCESS_MAIN( SetConsoleCursorInfo( stdHandle, &cursorInfo ) );
			}

			LS();

			system( "pause" );

			LS();

			{
				std::cout << r2tm::tab << "+ Show" << r2tm::linefeed2;

				PROCESS_MAIN( GetConsoleCursorInfo( stdHandle, &cursorInfo ) );
				PROCESS_MAIN( cursorInfo.bVisible = true );
				PROCESS_MAIN( SetConsoleCursorInfo( stdHandle, &cursorInfo ) );
			}

			LS();

			system( "pause" );

			LS();

			return r2tm::eDoLeaveAction::None;
		};
	}




	r2tm::TitleFunctionT QuickEdit::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Quick Edit";
		};
	}
	r2tm::DoFunctionT QuickEdit::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			std::cout << r2tm::tab << "# Quick Edit 는 콘솔창에서 마우스를 사용한 커서 이동, 선택이 가능한 옵션이다." << r2tm::linefeed;

			LS();

			DECLARATION_MAIN( DWORD last_console_mode = 0 );

			LS();

			{
				std::cout << r2tm::tab << "+ Backup" << r2tm::linefeed2;

				PROCESS_MAIN( GetConsoleMode( GetStdHandle( STD_INPUT_HANDLE ), &last_console_mode ) );
				OUTPUT_BINARY( last_console_mode );
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Disable" << r2tm::linefeed2;

				DECLARATION_MAIN( DWORD new_console_mode = last_console_mode );
				PROCESS_MAIN( new_console_mode |= ENABLE_EXTENDED_FLAGS );
				OUTPUT_BINARY( new_console_mode );
				PROCESS_MAIN( new_console_mode &= ~( ENABLE_QUICK_EDIT_MODE ) );
				PROCESS_MAIN( SetConsoleMode( GetStdHandle( STD_INPUT_HANDLE ), new_console_mode ) );
				OUTPUT_BINARY( new_console_mode );
			}

			LS();

			std::cout << r2tm::tab << "Press Any Key : Rollback" << r2tm::linefeed;
			_getch();

			LS();

			//
			// Rollback
			//
			{
				PROCESS_MAIN( SetConsoleMode( GetStdHandle( STD_INPUT_HANDLE ), last_console_mode ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}