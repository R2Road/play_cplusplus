#include "pch.h"
#include "console_window_test.h"

#include <bitset>
#include <conio.h>
#include <stdio.h>
#include <Windows.h>
#include <wincon.h> // BACKGROUND_RED

#include "base/r2_eTestResult.h"

namespace console_window_test
{
	r2::iTest::TitleFunc BufferInfo::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Buffer Info";
		};
	}
	r2::iTest::DoFunc BufferInfo::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE );
			CONSOLE_SCREEN_BUFFER_INFO cs_buffer_info;

			std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
			std::cout << r2::tab2 << "HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE );" << r2::linefeed;
			std::cout << r2::tab2 << "CONSOLE_SCREEN_BUFFER_INFO cs_buffer_info;" << r2::linefeed;

			std::cout << r2::split;

			const auto result = GetConsoleScreenBufferInfo( hStdout, &cs_buffer_info );

			std::cout << r2::tab << "+ Process" << r2::linefeed2;
			std::cout << r2::tab2 << "GetConsoleScreenBufferInfo( hStdout, &cs_buffer_info )" << r2::linefeed;

			std::cout << r2::split;

			if( result )
			{
				std::cout << r2::tab << "+ CONSOLE_SCREEN_BUFFER_INFO.dwCursorPosition" << r2::linefeed;
				std::cout << r2::tab2 << "X : " << cs_buffer_info.dwCursorPosition.X << r2::linefeed;
				std::cout << r2::tab2 << "Y : " << cs_buffer_info.dwCursorPosition.Y << r2::linefeed2;

				std::cout << r2::tab << "+ CONSOLE_SCREEN_BUFFER_INFO.dwMaximumWindowSize" << r2::linefeed;
				std::cout << r2::tab2 << "X : " << cs_buffer_info.dwMaximumWindowSize.X << r2::linefeed;
				std::cout << r2::tab2 << "Y : " << cs_buffer_info.dwMaximumWindowSize.Y << r2::linefeed2;

				std::cout << r2::tab << "+ CONSOLE_SCREEN_BUFFER_INFO.dwSize" << r2::linefeed;
				std::cout << r2::tab2 << "X : " << cs_buffer_info.dwSize.X << r2::linefeed;
				std::cout << r2::tab2 << "Y : " << cs_buffer_info.dwSize.Y << r2::linefeed2;

				std::cout << r2::tab << "+ CONSOLE_SCREEN_BUFFER_INFO.srWindow" << r2::linefeed;
				std::cout << r2::tab2 << "T : " << cs_buffer_info.srWindow.Top << r2::linefeed;
				std::cout << r2::tab2 << "B : " << cs_buffer_info.srWindow.Bottom << r2::linefeed;
				std::cout << r2::tab2 << "L : " << cs_buffer_info.srWindow.Left << r2::linefeed;
				std::cout << r2::tab2 << "R : " << cs_buffer_info.srWindow.Right << r2::linefeed2;

				std::cout << r2::tab << "+ CONSOLE_SCREEN_BUFFER_INFO.wAttributes" << r2::linefeed;
				std::cout << r2::tab2 << cs_buffer_info.wAttributes << r2::linefeed;
			}
			else
			{
				std::cout << r2::tab << "Failed : " "GetConsoleScreenBufferInfo( hStdout, &cs_buffer_info )" << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc ChangeWindowSize::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Change Window Size";
		};
	}
	r2::iTest::DoFunc ChangeWindowSize::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			{
				system( "mode con lines=30 cols=120" );
			}

			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				CONSOLE_SCREEN_BUFFER_INFO csbi;
				GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &csbi );
				const auto width = static_cast<int>( csbi.srWindow.Right - csbi.srWindow.Left + 1 );
				const auto height = static_cast<int>( csbi.srWindow.Bottom - csbi.srWindow.Top + 1 );

				std::cout << r2::tab << "Current Window Size" << r2::linefeed;
				std::cout << r2::tab << " - Width : " << width << r2::linefeed;
				std::cout << r2::tab << " - Height : " << height << r2::linefeed;
			}

			std::cout << r2::split;

			std::cout << "Press Any Key : Roll Back Window Size" << r2::linefeed;
			_getch();

			{
				system( "mode con lines=60 cols=120" );
			}

			return r2::eTestResult::RunTest_Without_Pause;
		};
	}



	r2::iTest::TitleFunc WindowPosition::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Window Position";
		};
	}
	r2::iTest::DoFunc WindowPosition::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			RECT last_window_rect;

			{
				HWND hWnd = GetConsoleWindow();
				GetWindowRect( hWnd, &last_window_rect );
				std::cout << r2::tab << "HWND hWnd = GetConsoleWindow();" << r2::linefeed;
				std::cout << r2::tab << "RECT last_window_rect;" << r2::linefeed;
				std::cout << r2::tab << "GetWindowRect( hWnd, &last_window_rect );" << r2::linefeed;

				std::cout << r2::linefeed;

				std::cout << r2::tab << "Current Window Position" << r2::linefeed;
				std::cout << r2::tab2 << " - X : " << last_window_rect.left << r2::linefeed;
				std::cout << r2::tab2 << " - Y : " << last_window_rect.top << r2::linefeed;
			}

			std::cout << r2::split;

			{
				RECT rectClient, rectWindow;
				HWND hWnd = GetConsoleWindow();
				GetClientRect( hWnd, &rectClient );
				GetWindowRect( hWnd, &rectWindow );
				
				int posx = GetSystemMetrics( SM_CXSCREEN ) / 2 - ( rectWindow.right - rectWindow.left ) / 2;
				int posy = GetSystemMetrics( SM_CYSCREEN ) / 2 - ( rectWindow.bottom - rectWindow.top ) / 2;

				MoveWindow( hWnd, posx, posy, rectClient.right - rectClient.left, rectClient.bottom - rectClient.top, TRUE );

				std::cout << r2::tab << "Move To Center" << r2::linefeed;
			}

			std::cout << r2::split;

			{
				RECT rectWindow;
				HWND hWnd = GetConsoleWindow();
				GetWindowRect( hWnd, &rectWindow );

				std::cout << r2::linefeed;

				std::cout << r2::tab << "Current Window Position" << r2::linefeed;
				std::cout << r2::tab2 << " - X : " << rectWindow.left << r2::linefeed;
				std::cout << r2::tab2 << " - Y : " << rectWindow.top << r2::linefeed;
			}

			std::cout << r2::split;
			system( "pause" );

			{
				//
				// Rollback
				//

				HWND hWnd = GetConsoleWindow();

				MoveWindow(
					hWnd
					, last_window_rect.left, last_window_rect.top
					, last_window_rect.right - last_window_rect.left, last_window_rect.bottom - last_window_rect.top
					, TRUE
				);
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest_Without_Pause;
		};
	}



	r2::iTest::TitleFunc ChangeWindowName::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Change Window Name";
		};
	}
	r2::iTest::DoFunc ChangeWindowName::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				TCHAR window_name_string[MAX_PATH];
				GetConsoleTitle( window_name_string, MAX_PATH );

				std::cout << r2::tab << " + " << "Current Window Name" << r2::linefeed;
				std::wcout << r2::tab2 << " - " << window_name_string << r2::linefeed;
			}

			std::cout << r2::split;

			{
				auto* window_name_string = TEXT( "console_test : ChangeWindowName" );

				SetConsoleTitle( window_name_string );

				std::cout << r2::tab << " + " << "New Window Name" << r2::linefeed;
				std::wcout << r2::tab2 << " - " << window_name_string << r2::linefeed;
			}

			std::cout << r2::split;

			std::cout << "Press Any Key : Roll Back Window Name" << r2::linefeed;
			_getch();

			{
				SetConsoleTitle( TEXT( "cpp_playground" ) );
			}
			_getch();

			return r2::eTestResult::RunTest_Without_Pause;
		};
	}



	r2::iTest::TitleFunc HideTitleBar::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Hide Title Bar";
		};
	}
	r2::iTest::DoFunc HideTitleBar::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			LONG last_window_style = 0;

			{
				last_window_style = GetWindowLong( GetConsoleWindow(), GWL_STYLE );

				std::cout << r2::tab << "+ Backup" << r2::linefeed2;
				std::cout << r2::tab2 << "last_window_style = GetWindowLong( GetConsoleWindow(), GWL_STYLE );" << r2::linefeed;
				std::cout << r2::tab3 << std::bitset<32>( last_window_style ) << r2::linefeed;
			}

			std::cout << r2::split;

			{
				LONG new_window_style = last_window_style;
				new_window_style &= ~( WS_BORDER | WS_CAPTION | WS_THICKFRAME );
				SetWindowLong( GetConsoleWindow(), GWL_STYLE, new_window_style );

				std::cout << r2::tab << "+ Lock" << r2::linefeed2;
				std::cout << r2::tab2 << "new_window_style &= ~( WS_BORDER | WS_CAPTION | WS_THICKFRAME );" << r2::linefeed;
				std::cout << r2::tab3 << std::bitset<32>( new_window_style ) << r2::linefeed2;
				std::cout << r2::tab2 << "SetWindowLong( GetConsoleWindow(), GWL_STYLE, new_window_style );" << r2::linefeed;
			}

			std::cout << r2::split;

			std::cout << r2::tab << "Press Any Key : Rollback" << r2::linefeed;
			_getch();

			std::cout << r2::split;

			//
			// Rollback
			//
			{
				HWND hwnd = GetConsoleWindow();
				SetWindowLong( hwnd, GWL_STYLE, last_window_style );
			}

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc HideScrollBar::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Hide Scroll Bar";
		};
	}
	r2::iTest::DoFunc HideScrollBar::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed2;
			std::cout << r2::tab << "WinUser.h" << r2::linefeed;

			std::cout << r2::split;

			{
				ShowScrollBar( GetConsoleWindow(), SB_VERT, 0 );

				std::cout << r2::tab << "+ Hide" << r2::linefeed2;
				std::cout << r2::tab2 << "ShowScrollBar( GetConsoleWindow(), SB_VERT, 0 );" << r2::linefeed;
			}

			std::cout << r2::split;
			
			std::cout << r2::tab << "Press Any Key : Rollback" << r2::linefeed;
			_getch();

			std::cout << r2::split;

			//
			// Rollback
			//
			{
				ShowScrollBar( GetConsoleWindow(), SB_VERT, 1 );

				std::cout << r2::tab << "+ Show" << r2::linefeed2;
				std::cout << r2::tab2 << "ShowScrollBar( GetConsoleWindow(), SB_VERT, 1 );" << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc LockWindowResizingByDragging::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Lock Window Resizing By Dragging";
		};
	}
	r2::iTest::DoFunc LockWindowResizingByDragging::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			LONG last_window_style = 0;

			{
				last_window_style = GetWindowLong( GetConsoleWindow(), GWL_STYLE );

				std::cout << r2::tab << "+ Backup" << r2::linefeed2;
				std::cout << r2::tab2 << "last_window_style = GetWindowLong( GetConsoleWindow(), GWL_STYLE );" << r2::linefeed;
				std::cout << r2::tab3 << std::bitset<32>( last_window_style ) << r2::linefeed;
			}

			std::cout << r2::split;

			{
				LONG new_window_style = last_window_style;
				new_window_style &= ~( WS_SIZEBOX );
				SetWindowLong( GetConsoleWindow(), GWL_STYLE, new_window_style );

				std::cout << r2::tab << "+ Lock" << r2::linefeed2;
				std::cout << r2::tab2 << "new_window_style &= ~( WS_SIZEBOX );" << r2::linefeed;
				std::cout << r2::tab3 << std::bitset<32>( new_window_style ) << r2::linefeed2;
				std::cout << r2::tab2 << "SetWindowLong( GetConsoleWindow(), GWL_STYLE, new_window_style );" << r2::linefeed;
			}

			std::cout << r2::split;

			std::cout << r2::tab << "Press Any Key : Rollback" << r2::linefeed;
			_getch();

			std::cout << r2::split;

			//
			// Rollback
			//
			{
				SetWindowLong( GetConsoleWindow(), GWL_STYLE, last_window_style );
			}

			return r2::eTestResult::RunTest;
		};
	}


	r2::iTest::TitleFunc CursorMove::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Cursor Move";
		};
	}
	r2::iTest::DoFunc CursorMove::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;
			std::cout << r2::tab << " + [W, A, S, D] : Move" << r2::linefeed;
			std::cout << r2::tab << " + [SPACE BAR] Foot Print" << r2::linefeed;
			std::cout << r2::tab << " + [ESC] Exit" << r2::linefeed;

			{
				HANDLE stdHandle = GetStdHandle( STD_OUTPUT_HANDLE );
				COORD pos = { 0, 3 };

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

			return r2::eTestResult::RunTest_Without_Pause;
		};
	}

	r2::iTest::TitleFunc CursorVisibility::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Cursor Visibility";
		};
	}
	r2::iTest::DoFunc CursorVisibility::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

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

			std::cout << r2::split;

			return r2::eTestResult::RunTest_Without_Pause;
		};
	}
}