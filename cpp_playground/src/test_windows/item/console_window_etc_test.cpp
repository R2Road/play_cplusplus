#include "pch.h"
#include "console_window_etc_test.h"

#include <conio.h> // _kbhit(), _getch()
#include <cwchar>
#include <Windows.h> // HDC

#include "r2cm/r2cm_constant.h"

void ShowFontInfo( const CONSOLE_FONT_INFOEX & cfie )
{
	std::cout << r2cm::tab2 << "dwFontSize.X : " << cfie.dwFontSize.X << r2cm::linefeed;
	std::cout << r2cm::tab2 << "dwFontSize.Y : " << cfie.dwFontSize.Y << r2cm::linefeed;
	std::cout << r2cm::tab2 << "FontFamily : " << cfie.FontFamily << r2cm::linefeed;
	std::cout << r2cm::tab2 << "FontWeight : " << cfie.FontWeight << r2cm::linefeed;
	std::cout << r2cm::tab2 << "nFont : " << cfie.nFont << r2cm::linefeed; // �ý����� �ܼ� �۲� ���̺��� �ִ� �۲��� �ε����Դϴ�.

	std::wcout.imbue( std::locale( "kor" ) );
	std::wcout << r2cm::tab2 << "FaceName : " << cfie.FaceName << r2cm::linefeed;
}

namespace console_window_etc_test
{
	r2cm::iItem::TitleFuncT FontInfo::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Font Info";
		};
	}
	r2cm::iItem::DoFuncT FontInfo::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

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



	r2cm::iItem::TitleFuncT FontChange::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Font Change";
		};
	}
	r2cm::iItem::DoFuncT FontChange::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

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



	r2cm::iItem::TitleFuncT Pixel::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Set Pixel";
		};
	}
	r2cm::iItem::DoFuncT Pixel::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2cm::linefeed2;

			std::cout << "[ESC] Exit" << r2cm::linefeed;

			{
				HWND console_window = GetConsoleWindow();
				HDC dc = GetDC( console_window );

				COORD pivot_pos{ 0, 100 };
				COLORREF pixel_color = RGB( 255, 100, 100 );
				int current_x = 0;
				int current_y = 0;
				while( true )
				{
					current_x = pivot_pos.X;

					for( double i = 0; i < 3.141592 * 4; i += 0.05 )
					{
						current_y = static_cast<int>( pivot_pos.Y + ( 35 * sin( i ) ) );

						SetPixel( dc, current_x, current_y, pixel_color );
						current_x += 1;
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

			return r2cm::eItemLeaveAction::None;
		};
	}
}