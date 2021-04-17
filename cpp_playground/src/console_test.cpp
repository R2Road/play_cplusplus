#include "pch.h"
#include "console_test.h"

#include <conio.h>
#include <Windows.h>

#include "r2_eTestResult.h"

namespace console_test
{
	const r2::iNode::TitleFunc GetWindowSize::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Console : Get Window Size";
		};
	}
	const r2::iNode::DoFunc GetWindowSize::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed << r2::linefeed;

			std::cout << r2::split;

			{
				CONSOLE_SCREEN_BUFFER_INFO csbi;
				GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &csbi );
				std::cout << "\t" << "CONSOLE_SCREEN_BUFFER_INFO csbi;" << r2::linefeed;
				std::cout << "\t" << "GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &csbi );" << r2::linefeed;

				std::cout << r2::linefeed;

				const auto width = static_cast<int>( csbi.srWindow.Right - csbi.srWindow.Left + 1 );
				const auto height = static_cast<int>( csbi.srWindow.Bottom - csbi.srWindow.Top + 1 );
				std::cout << "\t\t - Width : " << width << r2::linefeed;
				std::cout << "\t\t - Height : " << width << r2::linefeed;

				std::cout << r2::linefeed;
				std::cout << "\t\t - Left : " << csbi.srWindow.Left << r2::linefeed;
				std::cout << "\t\t - Top : " << csbi.srWindow.Top << r2::linefeed;
				std::cout << "\t\t - Right : " << csbi.srWindow.Right << r2::linefeed;
				std::cout << "\t\t - Bottom : " << csbi.srWindow.Bottom << r2::linefeed;
			}

			std::cout << r2::split;

			{
				HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE );
				CONSOLE_SCREEN_BUFFER_INFO csbi;
				GetConsoleScreenBufferInfo( hStdout, &csbi );
				std::cout << "\t" << "HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE );" << r2::linefeed;
				std::cout << "\t" << "CONSOLE_SCREEN_BUFFER_INFO csbi;" << r2::linefeed;
				std::cout << "\t" << "GetConsoleScreenBufferInfo( hStdout, &csbi );" << r2::linefeed;

				std::cout << r2::linefeed;

				const auto width = static_cast<int>( csbi.srWindow.Right - csbi.srWindow.Left + 1 );
				const auto height = static_cast<int>( csbi.srWindow.Bottom - csbi.srWindow.Top + 1 );
				std::cout << "\t\t - Width : " << width << r2::linefeed;
				std::cout << "\t\t - Height : " << width << r2::linefeed;

				std::cout << r2::linefeed;
				std::cout << "\t\t - Left : " << csbi.srWindow.Left << r2::linefeed;
				std::cout << "\t\t - Top : " << csbi.srWindow.Top << r2::linefeed;
				std::cout << "\t\t - Right : " << csbi.srWindow.Right << r2::linefeed;
				std::cout << "\t\t - Bottom : " << csbi.srWindow.Bottom << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	const r2::iNode::TitleFunc ChangeWindowSize::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Console : Change Window Size";
		};
	}
	const r2::iNode::DoFunc ChangeWindowSize::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			{
				system( "mode con lines=30 cols=120" );
			}

			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed << r2::linefeed;

			std::cout << r2::split;

			{
				CONSOLE_SCREEN_BUFFER_INFO csbi;
				GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &csbi );
				const auto width = static_cast<int>( csbi.srWindow.Right - csbi.srWindow.Left + 1 );
				const auto height = static_cast<int>( csbi.srWindow.Bottom - csbi.srWindow.Top + 1 );

				std::cout << "\t" << "Current Window Size" << r2::linefeed;
				std::cout << "\t\t - Width : " << width << r2::linefeed;
				std::cout << "\t\t - Height : " << width << r2::linefeed;
			}

			std::cout << r2::split;

			std::cout << "Press Any Key : Roll Back Window Size" << r2::linefeed;
			_getch();

			{
				system( "mode con lines=60 cols=120" );
			}

			return r2::eTestResult::RunTest;
		};
	}



	const r2::iNode::TitleFunc ChangeWindowPosition::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Console : Change Window Position";
		};
	}
	const r2::iNode::DoFunc ChangeWindowPosition::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed << r2::linefeed;

			std::cout << r2::split;

			{
				RECT rectClient, rectWindow;
				HWND hWnd = GetConsoleWindow();
				GetClientRect( hWnd, &rectClient );
				GetWindowRect( hWnd, &rectWindow );
				
				int posx = GetSystemMetrics( SM_CXSCREEN ) / 2 - ( rectWindow.right - rectWindow.left ) / 2;
				int posy = GetSystemMetrics( SM_CYSCREEN ) / 2 - ( rectWindow.bottom - rectWindow.top ) / 2;

				MoveWindow( hWnd, posx, posy, rectClient.right - rectClient.left, rectClient.bottom - rectClient.top, TRUE );

				std::cout << "\t" << "Move To Center" << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	const r2::iNode::TitleFunc ChangeWindowName::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Console : Change Window Name";
		};
	}
	const r2::iNode::DoFunc ChangeWindowName::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed << r2::linefeed;

			std::cout << r2::split;

			{
				TCHAR window_name_string[MAX_PATH];
				GetConsoleTitle( window_name_string, MAX_PATH );

				std::cout << "\t + " << "Current Window Name" << r2::linefeed;
				std::wcout << "\t\t - " << window_name_string << r2::linefeed;
			}

			std::cout << r2::split;

			{
				auto* window_name_string = TEXT( "console_test : ChangeWindowName" );

				SetConsoleTitle( window_name_string );

				std::cout << "\t + " << "New Window Name" << r2::linefeed;
				std::wcout << "\t\t - " << window_name_string << r2::linefeed;
			}

			std::cout << r2::split;

			std::cout << "Press Any Key : Roll Back Window Name" << r2::linefeed;
			_getch();

			{
				SetConsoleTitle( TEXT( "cpp_playground" ) );
			}

			return r2::eTestResult::RunTest;
		};
	}
}