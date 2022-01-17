#include "pch.h"
#include "console_test.h"

#include <conio.h> // _kbhit(), _getch()
#include <cwchar>
#include <Windows.h> // HDC

#include "base/r2_eTestResult.h"

namespace console_test
{
	r2::iTest::TitleFunc FontInfo::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Font Info";
		};
	}
	r2::iTest::DoFunc FontInfo::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			CONSOLE_FONT_INFOEX cfie;
			cfie.cbSize = sizeof( CONSOLE_FONT_INFOEX );
			GetCurrentConsoleFontEx( GetStdHandle( STD_OUTPUT_HANDLE ), 0, &cfie );

			std::cout << r2::tab << "+ Declartion" << r2::linefeed2;
			std::cout << r2::tab2 << "CONSOLE_FONT_INFOEX cfie;" << r2::linefeed;

			std::cout << r2::split;

			// https://docs.microsoft.com/ko-kr/windows/console/console-font-infoex
			std::cout << r2::tab << "+ Process" << r2::linefeed2;
			std::cout << r2::tab2 << "cfie.cbSize = sizeof( CONSOLE_FONT_INFOEX );" << r2::tab << "<===== Need This" << r2::linefeed;
			std::cout << r2::tab2 << "GetCurrentConsoleFontEx( GetStdHandle( STD_OUTPUT_HANDLE ), 0, &cfie );" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Font Info" << r2::linefeed2;
				std::cout << r2::tab2 << "cfie.dwFontSize.X : " << cfie.dwFontSize.X << r2::linefeed;
				std::cout << r2::tab2 << "cfie.dwFontSize.Y : " << cfie.dwFontSize.Y << r2::linefeed;
				std::cout << r2::tab2 << "cfie.FontFamily : " << cfie.FontFamily << r2::linefeed;
				std::cout << r2::tab2 << "cfie.FontWeight : " << cfie.FontWeight << r2::linefeed;
				std::cout << r2::tab2 << "cfie.nFont : " << cfie.nFont << r2::linefeed; // 시스템의 콘솔 글꼴 테이블에 있는 글꼴의 인덱스입니다.

				std::wcout.imbue( std::locale( "kor" ) );
				std::wcout << r2::tab2 << "cfie.FaceName : " << cfie.FaceName << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc FontChange::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Font Change";
		};
	}
	r2::iTest::DoFunc FontChange::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			CONSOLE_FONT_INFOEX backup_cfie;
			backup_cfie.cbSize = sizeof( CONSOLE_FONT_INFOEX );
			GetCurrentConsoleFontEx( GetStdHandle( STD_OUTPUT_HANDLE ), 0, &backup_cfie );

			{
				CONSOLE_FONT_INFOEX cfi;
				cfi.cbSize = sizeof( CONSOLE_FONT_INFOEX );
				cfi.nFont = 0;
				cfi.dwFontSize.X = backup_cfie.dwFontSize.X;
				cfi.dwFontSize.Y = backup_cfie.dwFontSize.Y;
				cfi.FontFamily = FF_DONTCARE;
				cfi.FontWeight = FW_NORMAL;
				wcscpy_s( cfi.FaceName, L"NSimSun" );

				std::cout << r2::tab << "+ Declartion" << r2::linefeed2;
				std::cout << r2::tab2 << "CONSOLE_FONT_INFOEX cfi;" << r2::linefeed;
				std::cout << r2::tab2 << "cfi.cbSize = sizeof( CONSOLE_FONT_INFOEX );" << r2::linefeed;
				std::cout << r2::tab2 << "cfi.dwFontSize.X = backup_cfie.dwFontSize.X;" << r2::linefeed;
				std::cout << r2::tab2 << "cfi.dwFontSize.Y = backup_cfie.dwFontSize.Y;" << r2::linefeed;
				std::cout << r2::tab2 << "cfi.FontFamily = FF_DONTCARE;" << r2::linefeed;
				std::cout << r2::tab2 << "cfi.FontWeight = FW_NORMAL;" << r2::linefeed;
				std::cout << r2::tab2 << "wcscpy_s( cfi.FaceName, L\"NSimSun\" );" << r2::linefeed;

				std::cout << r2::split;

				std::cout << r2::tab << "Press Key : Change Font" << r2::linefeed;
				_getch();
				
				SetCurrentConsoleFontEx( GetStdHandle( STD_OUTPUT_HANDLE ), FALSE, &cfi );
			}

			std::cout << r2::split;

			std::cout << r2::tab << "Press Key : Rollback" << r2::linefeed;
			_getch();

			SetCurrentConsoleFontEx( GetStdHandle( STD_OUTPUT_HANDLE ), FALSE, &backup_cfie );

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc Pixel::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Set Pixel";
		};
	}
	r2::iTest::DoFunc Pixel::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << "[ESC] Exit" << r2::linefeed;

			{
				HWND console_window = GetConsoleWindow();
				HDC dc = GetDC( console_window );

				COLORREF COLOR = RGB( 255, 100, 100 );
				while( true )
				{
					int pixel = 0;

					for( double i = 0; i < 3.141592 * 4; i += 0.05 )
					{
						SetPixel( dc, pixel, (int)( 70 + 25 * sin( i ) ), COLOR );
						pixel += 1;
					}

					if( _kbhit() )
					{
						if( 27 == _getch() )
						{
							break;
						}
					}
				}

				ReleaseDC( console_window, dc );
			}

			return r2::eTestResult::RunTest_Without_Pause;
		};
	}
}