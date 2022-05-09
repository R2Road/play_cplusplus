#include "pch.h"
#include "console_window_test.h"

#include <bitset>
#include <conio.h>
#include <stdio.h>
#include <Windows.h>
#include <wincon.h> // BACKGROUND_RED

#include "r2cm/r2cm_constant.h"
#include "r2cm/r2cm_Inspector.h"

namespace console_window_test
{
	r2cm::iItem::TitleFuncT BufferInfo::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Buffer Info";
		};
	}
	r2cm::iItem::DoFuncT BufferInfo::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

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



	r2cm::iItem::TitleFuncT ChangeWindowSize::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Change Window Size";
		};
	}
	r2cm::iItem::DoFuncT ChangeWindowSize::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			{
				system( "mode con lines=30 cols=120" );
				ShowScrollBar( GetConsoleWindow(), SB_VERT, 1 );
			}

			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE );
			CONSOLE_SCREEN_BUFFER_INFO csbi;

			{
				std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE );" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "CONSOLE_SCREEN_BUFFER_INFO cs_buffer_info;" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Process" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "system( \"mode con lines = 30 cols = 120\" );" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				GetConsoleScreenBufferInfo( hStdout, &csbi );
				const auto width = static_cast<int>( csbi.srWindow.Right - csbi.srWindow.Left + 1 );
				const auto height = static_cast<int>( csbi.srWindow.Bottom - csbi.srWindow.Top + 1 );

				std::cout << r2cm::tab << "+ Current Window Size" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "GetConsoleScreenBufferInfo( hStdout, &cs_buffer_info )" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "Width : " << width << r2cm::linefeed;
				std::cout << r2cm::tab2 << "Height : " << height << r2cm::linefeed;
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



	r2cm::iItem::TitleFuncT FullScreen::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "FullScreen";
		};
	}
	r2cm::iItem::DoFuncT FullScreen::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			{
				SendMessage( ::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000 );
			}

			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			std::cout << r2cm::tab << "+ Process" << r2cm::linefeed2;
			std::cout << r2cm::tab2 << "SendMessage( ::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000 );" << r2cm::linefeed;

			std::cout << r2cm::split;

			std::cout << "Press Any Key : Roll Back Window Size" << r2cm::linefeed;
			_getch();

			{
				SendMessage( ::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000 );
			}

			return r2cm::eItemLeaveAction::None;
		};
	}



	r2cm::iItem::TitleFuncT WindowPosition::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Window Position";
		};
	}
	r2cm::iItem::DoFuncT WindowPosition::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2cm::linefeed;

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



	r2cm::iItem::TitleFuncT ChangeWindowName::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Change Window Name";
		};
	}
	r2cm::iItem::DoFuncT ChangeWindowName::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2cm::linefeed;

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



	r2cm::iItem::TitleFuncT HideTitleBar::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Hide Title Bar";
		};
	}
	r2cm::iItem::DoFuncT HideTitleBar::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			LONG last_window_style = 0;

			{
				last_window_style = GetWindowLong( GetConsoleWindow(), GWL_STYLE );

				std::cout << r2cm::tab << "+ Backup" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "last_window_style = GetWindowLong( GetConsoleWindow(), GWL_STYLE );" << r2cm::linefeed;
				std::cout << r2cm::tab3 << std::bitset<32>( last_window_style ) << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				LONG new_window_style = last_window_style;
				new_window_style &= ~( WS_BORDER | WS_CAPTION | WS_THICKFRAME );
				SetWindowLong( GetConsoleWindow(), GWL_STYLE, new_window_style );

				std::cout << r2cm::tab << "+ Lock" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "new_window_style &= ~( WS_BORDER | WS_CAPTION | WS_THICKFRAME );" << r2cm::linefeed;
				std::cout << r2cm::tab3 << std::bitset<32>( new_window_style ) << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "SetWindowLong( GetConsoleWindow(), GWL_STYLE, new_window_style );" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			std::cout << r2cm::tab << "Press Any Key : Rollback" << r2cm::linefeed;
			_getch();

			std::cout << r2cm::split;

			//
			// Rollback
			//
			{
				HWND hwnd = GetConsoleWindow();
				SetWindowLong( hwnd, GWL_STYLE, last_window_style );
			}

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT HideScrollBar::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Hide Scroll Bar";
		};
	}
	r2cm::iItem::DoFuncT HideScrollBar::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed2;
			std::cout << r2cm::tab << "WinUser.h" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				ShowScrollBar( GetConsoleWindow(), SB_VERT, 0 );

				std::cout << r2cm::tab << "+ Hide" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "ShowScrollBar( GetConsoleWindow(), SB_VERT, 0 );" << r2cm::linefeed;
			}

			std::cout << r2cm::split;
			
			std::cout << r2cm::tab << "Press Any Key : Rollback" << r2cm::linefeed;
			_getch();

			std::cout << r2cm::split;

			//
			// Rollback
			//
			{
				ShowScrollBar( GetConsoleWindow(), SB_VERT, 1 );

				std::cout << r2cm::tab << "+ Show" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "ShowScrollBar( GetConsoleWindow(), SB_VERT, 1 );" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT LockWindowResizingByDragging::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Lock Window Resizing By Dragging";
		};
	}
	r2cm::iItem::DoFuncT LockWindowResizingByDragging::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			LONG last_window_style = 0;

			{
				last_window_style = GetWindowLong( GetConsoleWindow(), GWL_STYLE );

				std::cout << r2cm::tab << "+ Backup" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "last_window_style = GetWindowLong( GetConsoleWindow(), GWL_STYLE );" << r2cm::linefeed;
				std::cout << r2cm::tab3 << std::bitset<32>( last_window_style ) << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				LONG new_window_style = last_window_style;
				new_window_style &= ~( WS_SIZEBOX );
				SetWindowLong( GetConsoleWindow(), GWL_STYLE, new_window_style );

				std::cout << r2cm::tab << "+ Lock" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "new_window_style &= ~( WS_SIZEBOX );" << r2cm::linefeed;
				std::cout << r2cm::tab3 << std::bitset<32>( new_window_style ) << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "SetWindowLong( GetConsoleWindow(), GWL_STYLE, new_window_style );" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			std::cout << r2cm::tab << "Press Any Key : Rollback" << r2cm::linefeed;
			_getch();

			std::cout << r2cm::split;

			//
			// Rollback
			//
			{
				SetWindowLong( GetConsoleWindow(), GWL_STYLE, last_window_style );
			}

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT MenuItem::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Menu Item";
		};
	}
	r2cm::iItem::DoFuncT MenuItem::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			HMENU hmenu = GetSystemMenu( GetConsoleWindow(), FALSE );

			std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
			std::cout << r2cm::tab2 << "HMENU hmenu = GetSystemMenu( GetConsoleWindow(), FALSE );" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Process : Close Button Grayed" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "EnableMenuItem( hmenu, SC_CLOSE, MF_GRAYED );" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "Press Any Key : Do" << r2cm::linefeed;
				_getch();

				EnableMenuItem( hmenu, SC_CLOSE, MF_GRAYED );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "Press Any Key : Rollback" << r2cm::linefeed;
				_getch();

				//
				// Rollback
				//
				{
					EnableMenuItem( hmenu, SC_CLOSE, MF_ENABLED );
				}
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT CursorMove::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Cursor Move";
		};
	}
	r2cm::iItem::DoFuncT CursorMove::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed2;

			std::cout << "[W, A, S, D] : Move" << r2cm::linefeed;
			std::cout << "[SPACE BAR] Foot Print" << r2cm::linefeed;
			std::cout << "[ESC] Exit" << r2cm::linefeed;

			{
				HANDLE stdHandle = GetStdHandle( STD_OUTPUT_HANDLE );
				COORD pos = { 0, 7 };

				bool process = true;
				while( process )
				{
					SetConsoleCursorPosition( stdHandle, pos );

					switch( _getch() )
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

					case 27: // ESC
						process = false;
						break;

					case 32: // space
						std::cout << "test string";
						break;
					}
				}
			}

			return r2cm::eItemLeaveAction::None;
		};
	}

	r2cm::iItem::TitleFuncT CursorVisibility::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Cursor Visibility";
		};
	}
	r2cm::iItem::DoFuncT CursorVisibility::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			HANDLE stdHandle = GetStdHandle( STD_OUTPUT_HANDLE );

			{
				CONSOLE_CURSOR_INFO     cursorInfo;

				GetConsoleCursorInfo( stdHandle, &cursorInfo );
				cursorInfo.bVisible = false;
				SetConsoleCursorInfo( stdHandle, &cursorInfo );
			}

			system( "pause" );

			{
				CONSOLE_CURSOR_INFO     cursorInfo;

				GetConsoleCursorInfo( stdHandle, &cursorInfo );
				cursorInfo.bVisible = true;
				SetConsoleCursorInfo( stdHandle, &cursorInfo );
			}

			system( "pause" );

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::None;
		};
	}
}