#include "windows_terminal_font_test.h"

#include <conio.h> // _kbhit(), _getch()
#include <cwchar>
#include <Windows.h> // HDC

#include "r2cm/r2cm_ostream.h"

void ShowFontInfo( const CONSOLE_FONT_INFOEX & cfie )
{
	std::cout << r2cm::tab2 << "dwFontSize.X : " << cfie.dwFontSize.X << r2cm::linefeed;
	std::cout << r2cm::tab2 << "dwFontSize.Y : " << cfie.dwFontSize.Y << r2cm::linefeed;
	std::cout << r2cm::tab2 << "FontFamily : " << cfie.FontFamily << r2cm::linefeed;
	std::cout << r2cm::tab2 << "FontWeight : " << cfie.FontWeight << r2cm::linefeed;
	std::cout << r2cm::tab2 << "nFont : " << cfie.nFont << r2cm::linefeed; // 시스템의 콘솔 글꼴 테이블에 있는 글꼴의 인덱스입니다.

	std::wcout.imbue( std::locale( "kor" ) );
	std::wcout << r2cm::tab2 << "FaceName : " << cfie.FaceName << r2cm::linefeed;
}

namespace windows_terminal_font_test
{
	r2cm::iItem::TitleFunctionT FontInfo::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Font Info";
		};
	}
	r2cm::iItem::DoFunctionT FontInfo::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			CONSOLE_FONT_INFOEX cfie;
			cfie.cbSize = sizeof( CONSOLE_FONT_INFOEX );
			GetCurrentConsoleFontEx( GetStdHandle( STD_OUTPUT_HANDLE ), 0, &cfie );

			std::cout << r2cm::tab << "+ Declartion" << r2cm::linefeed2;
			std::cout << r2cm::tab2 << "CONSOLE_FONT_INFOEX cfie;" << r2cm::linefeed;

			std::cout << r2cm::split;

			// https://docs.microsoft.com/ko-kr/windows/console/console-font-infoex
			std::cout << r2cm::tab << "+ Process" << r2cm::linefeed2;
			std::cout << r2cm::tab2 << "cfie.cbSize = sizeof( CONSOLE_FONT_INFOEX );" << r2cm::tab << "<===== Need This" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "GetCurrentConsoleFontEx( GetStdHandle( STD_OUTPUT_HANDLE ), 0, &cfie );" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Font Info" << r2cm::linefeed2;
				ShowFontInfo( cfie );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT FontChange::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Font Change";
		};
	}
	r2cm::iItem::DoFunctionT FontChange::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			CONSOLE_FONT_INFOEX backup_cfie;
			backup_cfie.cbSize = sizeof( CONSOLE_FONT_INFOEX );
			GetCurrentConsoleFontEx( GetStdHandle( STD_OUTPUT_HANDLE ), 0, &backup_cfie );

			{
				std::cout << r2cm::tab << "+ Backup : Font Info" << r2cm::linefeed2;
				ShowFontInfo( backup_cfie );
			}

			std::cout << r2cm::split;

			{
				CONSOLE_FONT_INFOEX cfie;
				cfie.cbSize = sizeof( CONSOLE_FONT_INFOEX );
				cfie.nFont = 0;
				cfie.dwFontSize.X = backup_cfie.dwFontSize.X;
				cfie.dwFontSize.Y = backup_cfie.dwFontSize.Y;
				cfie.FontFamily = FF_DONTCARE;
				cfie.FontWeight = FW_NORMAL;
				wcscpy_s( cfie.FaceName, L"NSimSun" );

				std::cout << r2cm::tab << "+ Declartion" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "CONSOLE_FONT_INFOEX cfi;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "cfi.cbSize = sizeof( CONSOLE_FONT_INFOEX );" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "cfi.dwFontSize.X = backup_cfie.dwFontSize.X;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "cfi.dwFontSize.Y = backup_cfie.dwFontSize.Y;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "cfi.FontFamily = FF_DONTCARE;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "cfi.FontWeight = FW_NORMAL;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "wcscpy_s( cfi.FaceName, L\"NSimSun\" );" << r2cm::linefeed;

				std::cout << r2cm::split;

				std::cout << r2cm::tab << "Press Key : Change Font" << r2cm::linefeed;
				_getch();

				std::cout << r2cm::split;
				
				SetCurrentConsoleFontEx( GetStdHandle( STD_OUTPUT_HANDLE ), FALSE, &cfie );

				{
					std::cout << r2cm::tab << "+ Current : Font Info" << r2cm::linefeed2;
					ShowFontInfo( cfie );
				}
			}

			std::cout << r2cm::split;

			std::cout << r2cm::tab << "Press Key : Rollback" << r2cm::linefeed;
			_getch();

			SetCurrentConsoleFontEx( GetStdHandle( STD_OUTPUT_HANDLE ), FALSE, &backup_cfie );

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}