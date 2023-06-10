#include "windows_terminal_font_test.h"

#include <conio.h> // _kbhit(), _getch()
#include <cwchar>
#include <Windows.h> // HDC

#include "r2tm/r2tm_ostream.h"

void ShowFontInfo( const CONSOLE_FONT_INFOEX & cfie )
{
	std::cout << r2tm::tab2 << "dwFontSize.X : " << cfie.dwFontSize.X << r2tm::linefeed;
	std::cout << r2tm::tab2 << "dwFontSize.Y : " << cfie.dwFontSize.Y << r2tm::linefeed;
	std::cout << r2tm::tab2 << "FontFamily : " << cfie.FontFamily << r2tm::linefeed;
	std::cout << r2tm::tab2 << "FontWeight : " << cfie.FontWeight << r2tm::linefeed;
	std::cout << r2tm::tab2 << "nFont : " << cfie.nFont << r2tm::linefeed; // 시스템의 콘솔 글꼴 테이블에 있는 글꼴의 인덱스입니다.

	std::wcout.imbue( std::locale( "kor" ) );
	std::wcout << r2tm::tab2 << "FaceName : " << cfie.FaceName << r2tm::linefeed;
}

namespace windows_terminal_font_test
{
	r2tm::TitleFunctionT FontInfo::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Font Info";
		};
	}
	r2tm::DoFunctionT FontInfo::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			CONSOLE_FONT_INFOEX cfie;
			cfie.cbSize = sizeof( CONSOLE_FONT_INFOEX );
			GetCurrentConsoleFontEx( GetStdHandle( STD_OUTPUT_HANDLE ), 0, &cfie );

			std::cout << r2tm::tab << "+ Declartion" << r2tm::linefeed2;
			std::cout << r2tm::tab2 << "CONSOLE_FONT_INFOEX cfie;" << r2tm::linefeed;

			std::cout << r2tm::split;

			// https://docs.microsoft.com/ko-kr/windows/console/console-font-infoex
			std::cout << r2tm::tab << "+ Process" << r2tm::linefeed2;
			std::cout << r2tm::tab2 << "cfie.cbSize = sizeof( CONSOLE_FONT_INFOEX );" << r2tm::tab << "<===== Need This" << r2tm::linefeed;
			std::cout << r2tm::tab2 << "GetCurrentConsoleFontEx( GetStdHandle( STD_OUTPUT_HANDLE ), 0, &cfie );" << r2tm::linefeed;

			std::cout << r2tm::split;

			{
				std::cout << r2tm::tab << "+ Font Info" << r2tm::linefeed2;
				ShowFontInfo( cfie );
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT FontChange::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Font Change";
		};
	}
	r2tm::DoFunctionT FontChange::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			CONSOLE_FONT_INFOEX backup_cfie;
			backup_cfie.cbSize = sizeof( CONSOLE_FONT_INFOEX );
			GetCurrentConsoleFontEx( GetStdHandle( STD_OUTPUT_HANDLE ), 0, &backup_cfie );

			{
				std::cout << r2tm::tab << "+ Backup : Font Info" << r2tm::linefeed2;
				ShowFontInfo( backup_cfie );
			}

			std::cout << r2tm::split;

			{
				CONSOLE_FONT_INFOEX cfie;
				cfie.cbSize = sizeof( CONSOLE_FONT_INFOEX );
				cfie.nFont = 0;
				cfie.dwFontSize.X = backup_cfie.dwFontSize.X;
				cfie.dwFontSize.Y = backup_cfie.dwFontSize.Y;
				cfie.FontFamily = FF_DONTCARE;
				cfie.FontWeight = FW_NORMAL;
				wcscpy_s( cfie.FaceName, L"NSimSun" );

				std::cout << r2tm::tab << "+ Declartion" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "CONSOLE_FONT_INFOEX cfi;" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "cfi.cbSize = sizeof( CONSOLE_FONT_INFOEX );" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "cfi.dwFontSize.X = backup_cfie.dwFontSize.X;" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "cfi.dwFontSize.Y = backup_cfie.dwFontSize.Y;" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "cfi.FontFamily = FF_DONTCARE;" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "cfi.FontWeight = FW_NORMAL;" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "wcscpy_s( cfi.FaceName, L\"NSimSun\" );" << r2tm::linefeed;

				std::cout << r2tm::split;

				std::cout << r2tm::tab << "Press Key : Change Font" << r2tm::linefeed;
				_getch();

				std::cout << r2tm::split;
				
				SetCurrentConsoleFontEx( GetStdHandle( STD_OUTPUT_HANDLE ), FALSE, &cfie );

				{
					std::cout << r2tm::tab << "+ Current : Font Info" << r2tm::linefeed2;
					ShowFontInfo( cfie );
				}
			}

			std::cout << r2tm::split;

			std::cout << r2tm::tab << "Press Key : Rollback" << r2tm::linefeed;
			_getch();

			SetCurrentConsoleFontEx( GetStdHandle( STD_OUTPUT_HANDLE ), FALSE, &backup_cfie );

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}