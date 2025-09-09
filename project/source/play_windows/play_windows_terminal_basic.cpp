#include "play_windows_terminal_basic.hpp"

#include <bitset>
#include <conio.h>
#include <iomanip>
#include <stdio.h>
#include <Windows.h>
#include <wincon.h> // BACKGROUND_RED

// Windows.h 와 wincon.h 의 include 순서를 바꾸면 빌드에 문제가 생긴다.
// - c:\program files (x86)\windows kits\10\include\10.0.18362.0\um\winnt.h(173): fatal error C1189: #error:  "No Target Architecture"

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"
#include "r2tm/r2tm_windows_utility.hpp"

namespace play_windows_terminal_basic
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

			DECL_MAIN( HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE ) );
			DECL_MAIN( CONSOLE_SCREEN_BUFFER_INFO console_screen_buffer_info );

			LS();

			EXPECT_TRUE( GetConsoleScreenBufferInfo( hStdout, &console_screen_buffer_info ) );

			LS();

			{
				OUT_VALUE( console_screen_buffer_info.dwCursorPosition.X );
				OUT_VALUE( console_screen_buffer_info.dwCursorPosition.Y );

				LF();

				OUT_VALUE( console_screen_buffer_info.dwMaximumWindowSize.X );
				OUT_VALUE( console_screen_buffer_info.dwMaximumWindowSize.Y );

				LF();

				OUT_VALUE( console_screen_buffer_info.dwSize.X );
				OUT_VALUE( console_screen_buffer_info.dwSize.Y );

				LF();

				OUT_VALUE( console_screen_buffer_info.srWindow.Left );
				OUT_VALUE( console_screen_buffer_info.srWindow.Top );
				OUT_VALUE( console_screen_buffer_info.srWindow.Right );
				OUT_VALUE( console_screen_buffer_info.srWindow.Bottom );

				LF();

				OUT_VALUE( console_screen_buffer_info.wAttributes );
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
				DECL_MAIN( HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE ) );
				DECL_MAIN( CONSOLE_SCREEN_BUFFER_INFO csbi );

				LF();

				PROC_MAIN( GetConsoleScreenBufferInfo( hStdout, &csbi ) );
				DECL_MAIN( const auto width = static_cast<int>( csbi.srWindow.Right - csbi.srWindow.Left + 1 ) );
				DECL_MAIN( const auto height = static_cast<int>( csbi.srWindow.Bottom - csbi.srWindow.Top + 1 ) );
				OUT_VALUE( width );
				OUT_VALUE( height );

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
			return "Full Screen";
		};
	}
	r2tm::DoFunctionT FullScreen::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_SUBJECT( "Alt + Enter" );

			LS();

			{
				PROC_MAIN( SendMessage( ::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000 ) );
			}

			LS();

			{
				OUT_SUBJECT( "아무키 누르면 윈도우 크기 복구" );
				WAIT_ANY_KEY;

				LF();

				PROC_MAIN( SendMessage( ::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000 ) );
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
			const auto last_cursor_point = r2tm::WindowsUtility::GetCursorPoint();
			while( true )
			{
				r2tm::WindowsUtility::MoveCursorPoint( last_cursor_point );

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

			DECL_MAIN( HWND hWnd = GetConsoleWindow() );
			DECL_MAIN( RECT last_window_rect );

			LS();

			{
				std::cout << r2tm::tab << "+ Backup" << r2tm::linefeed2;

				PROC_MAIN( GetWindowRect( hWnd, &last_window_rect ) );

				std::cout << r2tm::tab
					<< "X : " << last_window_rect.left << "     "
					<< "Y : " << last_window_rect.top << "     "
					<< "W : " << ( last_window_rect.right - last_window_rect.left ) << "     "
					<< "H : " << ( last_window_rect.bottom - last_window_rect.top ) << r2tm::linefeed;
			}

			LS();

			{
				std::cout << r2tm::tab << "+ System Display Info" << r2tm::linefeed2;
				OUT_VALUE( GetSystemMetrics( SM_CXSCREEN ) );
				OUT_VALUE( GetSystemMetrics( SM_CYSCREEN ) );
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Move To Center" << r2tm::linefeed;

				DECL_MAIN( const int system_center_x = GetSystemMetrics( SM_CXSCREEN ) / 2 );
				DECL_MAIN( const int system_center_y = GetSystemMetrics( SM_CYSCREEN ) / 2 );
				OUT_VALUE( system_center_x );
				OUT_VALUE( system_center_y );

				DECL_MAIN( const int window_width = ( last_window_rect.right - last_window_rect.left ) );
				DECL_MAIN( const int window_height = ( last_window_rect.bottom - last_window_rect.top ) );
				OUT_VALUE( window_width );
				OUT_VALUE( window_height );

				DECL_MAIN( const int posx = system_center_x - ( window_width / 2 ) );
				DECL_MAIN( const int posy = system_center_y - ( window_height / 2 ) );
				OUT_VALUE( posx );
				OUT_VALUE( posy );

				PROC_MAIN( MoveWindow( hWnd, posx, posy, window_width, window_height, TRUE ) );

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

			DECL_MAIN( char last_window_name_string[MAX_PATH] );
			PROC_MAIN( GetConsoleTitleA( last_window_name_string, MAX_PATH ) );

			LF();

			OUT_VALUE( last_window_name_string );

			LS();

			{
				std::cout << r2tm::tab << " + Change Window Name" << r2tm::linefeed2;

				DECL_MAIN( const char* window_name_string = "console_test : ChangeWindowName" );
				PROC_MAIN( SetConsoleTitleA( window_name_string ) );
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

			DECL_MAIN( LONG last_window_style = 0 );

			LS();

			{
				std::cout << r2tm::tab << "+ Backup" << r2tm::linefeed2;

				PROC_MAIN( last_window_style = GetWindowLong( GetConsoleWindow(), GWL_STYLE ) );

				LF();

				OUT_BINARY( last_window_style );
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Lock" << r2tm::linefeed2;

				DECL_MAIN( LONG new_window_style = last_window_style );
				PROC_MAIN( new_window_style &= ~( WS_BORDER | WS_CAPTION | WS_THICKFRAME ) );
				PROC_MAIN( SetWindowLong( GetConsoleWindow(), GWL_STYLE, new_window_style ) );

				LF();

				OUT_BINARY( new_window_style );
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
				PROC_MAIN( SetWindowLong( GetConsoleWindow(), GWL_STYLE, last_window_style ) );
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

				PROC_MAIN( ShowScrollBar( GetConsoleWindow(), SB_VERT, 0 ) );
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

				PROC_MAIN( ShowScrollBar( GetConsoleWindow(), SB_VERT, 1 ) );
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

			DECL_MAIN( LONG last_window_style = 0 );

			LS();

			{
				std::cout << r2tm::tab << "+ Backup" << r2tm::linefeed2;

				PROC_MAIN( last_window_style = GetWindowLong( GetConsoleWindow(), GWL_STYLE ) );
				OUT_BINARY( last_window_style );
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Lock" << r2tm::linefeed2;

				DECL_MAIN( LONG new_window_style = last_window_style );
				PROC_MAIN( new_window_style &= ~( WS_MAXIMIZEBOX) );
				PROC_MAIN( SetWindowLong( GetConsoleWindow(), GWL_STYLE, new_window_style ) );
				OUT_BINARY( new_window_style );

				LF();

				std::cout << r2tm::tab << "+ 아래 코드를 쓴 경우들이 있어서 남겨둔다. 상황에 따라 갱신에 사용되는 것 같다." << r2tm::linefeed2;

				PROC_MAIN( SetWindowPos( GetConsoleWindow(), NULL, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE | SWP_FRAMECHANGED ) );
			}

			LS();

			std::cout << r2tm::tab << "Press Any Key : Rollback" << r2tm::linefeed;
			_getch();

			LS();

			//
			// Rollback
			//
			{
				PROC_MAIN( SetWindowLong( GetConsoleWindow(), GWL_STYLE, last_window_style ) );
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

			DECL_MAIN( LONG last_window_style = 0 );

			LS();

			{
				std::cout << r2tm::tab << "+ Backup" << r2tm::linefeed2;

				PROC_MAIN( last_window_style = GetWindowLong( GetConsoleWindow(), GWL_STYLE ) );
				OUT_BINARY( last_window_style );
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Lock" << r2tm::linefeed2;

				DECL_MAIN( LONG new_window_style = last_window_style );
				PROC_MAIN( new_window_style &= ~( WS_SIZEBOX ) );
				PROC_MAIN( SetWindowLong( GetConsoleWindow(), GWL_STYLE, new_window_style ) );
				OUT_BINARY( new_window_style );
			}

			LS();

			std::cout << r2tm::tab << "Press Any Key : Rollback" << r2tm::linefeed;
			_getch();

			LS();

			//
			// Rollback
			//
			{
				PROC_MAIN( SetWindowLong( GetConsoleWindow(), GWL_STYLE, last_window_style ) );
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
			DECL_MAIN( HMENU hmenu = GetSystemMenu( GetConsoleWindow(), FALSE ) );

			LS();

			{
				std::cout << r2tm::tab << "Press Any Key : Do" << r2tm::linefeed;
				_getch();
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Process : Close Button Grayed" << r2tm::linefeed2;
				PROC_MAIN( EnableMenuItem( hmenu, SC_CLOSE, MF_GRAYED ) );
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
				PROC_MAIN( EnableMenuItem( hmenu, SC_CLOSE, MF_ENABLED ) );
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

			DECL_MAIN( HANDLE stdHandle = GetStdHandle( STD_OUTPUT_HANDLE ) );
			DECL_MAIN( COORD pos );
			PROC_MAIN( pos.X = 20 );
			PROC_MAIN( pos.Y = 30 );

			LS();

			std::cout << "[W, A, S, D] : Move" << r2tm::linefeed;
			std::cout << "[SPACE BAR] Foot Print" << r2tm::linefeed;
			std::cout << "[ESC] Exit" << r2tm::linefeed;

			LS();

			PROC_MAIN( SetConsoleCursorPosition( stdHandle, pos ) );

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

			DECL_MAIN( HANDLE stdHandle = GetStdHandle( STD_OUTPUT_HANDLE ) );
			DECL_MAIN( CONSOLE_CURSOR_INFO cursorInfo );

			LS();

			{
				std::cout << r2tm::tab << "+ Hide" << r2tm::linefeed2;

				PROC_MAIN( GetConsoleCursorInfo( stdHandle, &cursorInfo ) );
				PROC_MAIN( cursorInfo.bVisible = false );
				PROC_MAIN( SetConsoleCursorInfo( stdHandle, &cursorInfo ) );
			}

			LS();

			system( "pause" );

			LS();

			{
				std::cout << r2tm::tab << "+ Show" << r2tm::linefeed2;

				PROC_MAIN( GetConsoleCursorInfo( stdHandle, &cursorInfo ) );
				PROC_MAIN( cursorInfo.bVisible = true );
				PROC_MAIN( SetConsoleCursorInfo( stdHandle, &cursorInfo ) );
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

			DECL_MAIN( DWORD last_console_mode = 0 );

			LS();

			{
				std::cout << r2tm::tab << "+ Backup" << r2tm::linefeed2;

				PROC_MAIN( GetConsoleMode( GetStdHandle( STD_INPUT_HANDLE ), &last_console_mode ) );
				OUT_BINARY( last_console_mode );
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Disable" << r2tm::linefeed2;

				DECL_MAIN( DWORD new_console_mode = last_console_mode );
				PROC_MAIN( new_console_mode |= ENABLE_EXTENDED_FLAGS );
				OUT_BINARY( new_console_mode );
				PROC_MAIN( new_console_mode &= ~( ENABLE_QUICK_EDIT_MODE ) );
				PROC_MAIN( SetConsoleMode( GetStdHandle( STD_INPUT_HANDLE ), new_console_mode ) );
				OUT_BINARY( new_console_mode );
			}

			LS();

			std::cout << r2tm::tab << "Press Any Key : Rollback" << r2tm::linefeed;
			_getch();

			LS();

			//
			// Rollback
			//
			{
				PROC_MAIN( SetConsoleMode( GetStdHandle( STD_INPUT_HANDLE ), last_console_mode ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}