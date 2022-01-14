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
	r2::iTest::TitleFunc GetWindowSize::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Get Window Size";
		};
	}
	r2::iTest::DoFunc GetWindowSize::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE );
				CONSOLE_SCREEN_BUFFER_INFO csbi;
				GetConsoleScreenBufferInfo( hStdout, &csbi );
				std::cout << r2::tab << "HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE );" << r2::linefeed;
				std::cout << r2::tab << "CONSOLE_SCREEN_BUFFER_INFO csbi;" << r2::linefeed;
				std::cout << r2::tab << "GetConsoleScreenBufferInfo( hStdout, &csbi );" << r2::linefeed;

				std::cout << r2::linefeed;

				const auto width = static_cast<int>( csbi.srWindow.Right - csbi.srWindow.Left + 1 );
				const auto height = static_cast<int>( csbi.srWindow.Bottom - csbi.srWindow.Top + 1 );
				std::cout << r2::tab2 << " - Width : " << width << r2::linefeed;
				std::cout << r2::tab2 << " - Height : " << height << r2::linefeed;

				std::cout << r2::linefeed;
				std::cout << r2::tab2 << " - Left : " << csbi.srWindow.Left << r2::linefeed;
				std::cout << r2::tab2 << " - Top : " << csbi.srWindow.Top << r2::linefeed;
				std::cout << r2::tab2 << " - Right : " << csbi.srWindow.Right << r2::linefeed;
				std::cout << r2::tab2 << " - Bottom : " << csbi.srWindow.Bottom << r2::linefeed;
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
				HWND hwnd = GetConsoleWindow();
				last_window_style = GetWindowLong( hwnd, GWL_STYLE );

				std::cout << r2::tab << "Last Window Style : " << r2::tab << std::bitset<32>( last_window_style ) << r2::linefeed;
			}

			std::cout << r2::split;

			{
				HWND hwnd = GetConsoleWindow();
				LONG style = last_window_style;
				style &= ~( WS_BORDER | WS_CAPTION | WS_THICKFRAME );
				SetWindowLong( hwnd, GWL_STYLE, style );

				std::cout << r2::tab << "New Window Style : " << r2::tab << std::bitset<32>( style ) << r2::linefeed;
			}

			std::cout << r2::split;

			system( "pause" );
			{
				HWND hwnd = GetConsoleWindow();
				SetWindowLong( hwnd, GWL_STYLE, last_window_style );
			}

			return r2::eTestResult::RunTest_Without_Pause;
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
				std::cout << r2::tab3 << std::bitset<32>( new_window_style ) << r2::linefeed;
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
}