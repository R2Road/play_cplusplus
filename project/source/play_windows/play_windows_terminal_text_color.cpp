#include "play_windows_terminal_text_color.hpp"

#include <bitset>
#include <conio.h>
#include <iomanip>
#include <stdio.h>

#define NOMINMAX
#include <Windows.h>
#include <wincon.h> // BACKGROUND_RED

#include "r2tm/r2tm_ostream.hpp"
#include "r2tm/r2tm_inspector.hpp"

namespace play_windows_terminal_text_color
{
	void PrintColorTable_Item( const char* str_index, const char* str_name, const COLORREF c )
	{
		std::cout
			<< std::left

			<< "               "

			<< str_index

			<< "   |   "

			<< std::setw( 15 ) << str_name

			<< "   |   "

			<< "     "  "R : " << std::setw( 3 ) << ( int )GetRValue( c )
			<< "     "  "G : " << std::setw( 3 ) << ( int )GetGValue( c )
			<< "     "  "B : " << std::setw( 3 ) << ( int )GetBValue( c )
			<< r2tm::linefeed
		;
	}
	r2tm::TitleFunctionT ColorTable::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Color Table";
		};
	}
	r2tm::DoFunctionT ColorTable::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECL_MAIN( HANDLE stdHandle = GetStdHandle( STD_OUTPUT_HANDLE ) );
			DECL_MAIN( CONSOLE_SCREEN_BUFFER_INFOEX info );

			SS();

			{
				OUT_SUBJECT( "정보 획득" );

				LF();

				PROC_MAIN( info.cbSize = sizeof( CONSOLE_SCREEN_BUFFER_INFOEX ) );
				PROC_MAIN( GetConsoleScreenBufferInfoEx( stdHandle, &info ) );
			}

			SS();

			{
				OUT_SUBJECT( "Color Table" );

				LF();

				PrintColorTable_Item( "0"  , "Black"        , info.ColorTable[0] );
				PrintColorTable_Item( "1"  , "Blue"         , info.ColorTable[1] );
				PrintColorTable_Item( "2"  , "Green"        , info.ColorTable[2] );
				PrintColorTable_Item( "3"  , "Aqua"         , info.ColorTable[3] );
				PrintColorTable_Item( "4"  , "Red"          , info.ColorTable[4] );
				PrintColorTable_Item( "5"  , "Purple"       , info.ColorTable[5] );
				PrintColorTable_Item( "6"  , "Yellow"       , info.ColorTable[6] );
				PrintColorTable_Item( "7"  , "White"        , info.ColorTable[7] );
				PrintColorTable_Item( "8"  , "Gray"         , info.ColorTable[8] );
				PrintColorTable_Item( "9"  , "Light Blue"   , info.ColorTable[9] );
				PrintColorTable_Item( "A"  , "Light Green"  , info.ColorTable[10] );
				PrintColorTable_Item( "B"  , "Light Aqua"   , info.ColorTable[11] );
				PrintColorTable_Item( "C"  , "Light Led"    , info.ColorTable[12] );
				PrintColorTable_Item( "D"  , "Light Purple" , info.ColorTable[13] );
				PrintColorTable_Item( "E"  , "Light Yellow" , info.ColorTable[14] );
				PrintColorTable_Item( "F"  , "Bright White" , info.ColorTable[15] );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT TextColor1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Text Color 1";
		};
	}
	r2tm::DoFunctionT TextColor1::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				//
				// 0 for background Color(Black)
				// A for text color(Green)
				//
				system( "Color 0A" );
				std::cout << r2tm::tab << "system( \"Color 0A\" );" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "- 0 : background Color( Black )" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "- A : text color( Green )" << r2tm::linefeed;
			}

			LS();

			std::cout << "Press Any Key : Roll Back Text Color" << r2tm::linefeed;
			system( "pause" );

			{
				system( "Color 07" );
			}
			system( "pause" );
			

			return r2tm::eDoLeaveAction::None;
		};
	}



	r2tm::TitleFunctionT TextColor2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Text Color 2";
		};
	}
	r2tm::DoFunctionT TextColor2::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			HANDLE stdHandle = GetStdHandle( STD_OUTPUT_HANDLE );

			{
				char background_color = 8;
				char text_color = 6;

				WORD current_color = 0;
				current_color = background_color << 4;
				current_color |= text_color;

				std::cout << r2tm::tab << " SetConsoleTextAttribute( stdHandle, current_color );" << r2tm::linefeed;
				SetConsoleTextAttribute( stdHandle, current_color );

				std::cout << r2tm::tab2 << "- " << std::hex << "hex : " << (int)background_color << " : background Color" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "- " << std::hex << "hex : " << (int)text_color << " : text Color" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "- " << std::hex << "hex : " << (int)current_color << " : current Color" << r2tm::linefeed;
			}

			SetConsoleTextAttribute( stdHandle, 7 ); // bg - black( 0 ), text - white( 7 )

			LS();

			{
				const WORD current_color = BACKGROUND_BLUE | FOREGROUND_GREEN | COMMON_LVB_GRID_HORIZONTAL;

				std::cout << r2tm::tab << " SetConsoleTextAttribute( stdHandle, current_color );" << r2tm::linefeed;
				SetConsoleTextAttribute( stdHandle, current_color );

				std::cout << r2tm::tab2 << "- " << std::hex << "hex : " << (int)BACKGROUND_BLUE << " : BACKGROUND_BLUE" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "- " << std::hex << "hex : " << (int)FOREGROUND_GREEN << " : FOREGROUND_GREEN" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "- " << std::hex << "hex : " << (int)COMMON_LVB_GRID_HORIZONTAL << " : COMMON_LVB_GRID_HORIZONTAL" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "- " << std::hex << "hex : " << (int)current_color << " : curren Color" << r2tm::linefeed;
			}

			SetConsoleTextAttribute( stdHandle, 7 ); // bg - black( 0 ), text - white( 7 )

			LS();

			{
				std::cout << r2tm::tab;
				SetConsoleTextAttribute( stdHandle, FOREGROUND_GREEN );
				std::cout << "SetConsoleTextAttribute( ";
				SetConsoleTextAttribute( stdHandle, FOREGROUND_RED );
				std::cout << "stdHandle";
				std::cout << ", current_color";
				SetConsoleTextAttribute( stdHandle, FOREGROUND_GREEN );
				std::cout << " );" << r2tm::linefeed;
			}

			SetConsoleTextAttribute( stdHandle, 7 ); // bg - black( 0 ), text - white( 7 )

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT AdjustColorTable::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Adjust Color Table";
		};
	}
	r2tm::DoFunctionT AdjustColorTable::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECL_MAIN( HANDLE stdHandle = GetStdHandle( STD_OUTPUT_HANDLE ) );
			DECL_MAIN( CONSOLE_SCREEN_BUFFER_INFOEX info );
			DECL_MAIN( COLORREF color_backup );

			LF();

			PROC_MAIN( info.cbSize = sizeof( CONSOLE_SCREEN_BUFFER_INFOEX ) );
			PROC_MAIN( GetConsoleScreenBufferInfoEx( stdHandle, &info ) );

			SS();

			{
				OUT_SUBJECT( "복구를 위해 기존 색상 저장" );

				LF();

				PROC_MAIN( color_backup = info.ColorTable[1] );
			}

			LS();

			{
				OUT_SUBJECT( "컬러 테이블 조정" );
				OUT_COMMENT( "1번 Blue 를 임의의 색상으로 변경" );

				LF();

				PROC_MAIN( info.ColorTable[1] = RGB( 255, 100, 100 ) );
				PROC_MAIN( SetConsoleScreenBufferInfoEx( stdHandle, &info ) );
			}

			LS();

			{
				OUT_SUBJECT( "변경한 컬러로 문자열 출력" );

				LF();

				DECL_MAIN( const char background_color = 0 );
				DECL_MAIN( const char foreground_color = 1 );
				PROC_MAIN( SetConsoleTextAttribute( stdHandle, WORD( background_color << 4 | foreground_color ) ) );

				LF();

				std::cout << r2tm::tab2 << "색상 확인용 문자열" << r2tm::linefeed;

				LF();

				PROC_MAIN( SetConsoleTextAttribute( stdHandle, 7 ) ); // bg - black( 0 ), text - white( 7 )
			}

			LS();

			{
				OUT_SUBJECT( "아무키나 누르면 컬러 테이블 복구 처리 시작" );
				WAIT_ANY_KEY;

				LF();

				PROC_MAIN( info.ColorTable[1] = color_backup );
				PROC_MAIN( SetConsoleScreenBufferInfoEx( stdHandle, &info ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT ColorTable2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Color Table 2";
		};
	}
	r2tm::DoFunctionT ColorTable2::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			//
			// Link : https://en.wikipedia.org/wiki/ANSI_escape_code#Colors
			// > \033 : reset the console
			//

			{
				int n = 0;

				for( int i = 0; i < 11; i++ )
				{
					for( int j = 0; j < 10; j++ )
					{
						n = 10 * i + j;
						if( n > 108 )
						{
							break;
						}

						printf( " " "\033[%dm" "%3d" "\033[m", n, n );
					}

					printf( "\n" );
				}
			}

			LS();

			{
				for( int i = 30; 37 >= i; ++i )
				{
					std::cout << r2tm::tab2;
					printf( "\x1B[%dm" "Foreground Color" "\033[0m : %d", i, i );
					LF();
				}

				LF();

				for( int i = 90; 97 >= i; ++i )
				{
					std::cout << r2tm::tab2;
					printf( "\x1B[%dm" "Foreground Color" "\033[0m : %d", i, i );
					LF();
				}
			}

			LF();

			{
				for( int i = 40; 47 >= i; ++i )
				{
					std::cout << r2tm::tab2;
					printf( "\x1B[%dm" "Background Color" "\033[0m : %d", i, i );
					LF();
				}

				LF();

				for( int i = 100; 107 >= i; ++i )
				{
					std::cout << r2tm::tab2;
					printf( "\x1B[%dm" "Background Color" "\033[0m : %d", i, i );
					LF();
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT TextColor3::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Text Color 3";
		};
	}
	r2tm::DoFunctionT TextColor3::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			//
			// Link : https://en.wikipedia.org/wiki/ANSI_escape_code#Colors
			// > \033 : reset the console
			//

			{
				std::cout << r2tm::tab << "+ Sequence Not Required" << r2tm::linefeed << r2tm::linefeed;

				const int background_color = 31;
				const int foreground_color = 44;

				std::cout << r2tm::tab2;
				printf( "\x1B[%d;%dm" "Color" "\033[0m", foreground_color, background_color );
				printf( ": First - %d, Second - %d", foreground_color, background_color );
				LF();

				std::cout << r2tm::tab2;
				printf( "\x1B[%d;%dm" "Color" "\033[0m", background_color, foreground_color );
				printf( ": First - %d, Second - %d", background_color, foreground_color );
				LF();
			}

			LS();


			{
				std::cout << r2tm::tab << "+ 같은 속성의 값이 입력되면 뒤의 값이 적용된다." << r2tm::linefeed << r2tm::linefeed;

				const int background_color_1 = 41;
				const int background_color_2 = 44;

				std::cout << r2tm::tab2;
				printf( "\x1B[%d;%dm" "Color" "\033[0m", background_color_2, background_color_1 );
				printf( ": First - %d, Second - %d", background_color_2, background_color_1 );
				LF();

				std::cout << r2tm::tab2;
				printf( "\x1B[%d;%dm" "Color" "\033[0m", background_color_1, background_color_2 );
				printf( ": First - %d, Second - %d", background_color_1, background_color_2 );
				LF();
			}

			LS();

			{
				const int background_color = 47;
				const int foreground_color = 31;

				for( int i = 0; 9 >= i; ++i )
				{
					std::cout << r2tm::tab2;
					printf( "\033[%d;%d;%dm" "Text" "\033[0m", i, background_color, foreground_color );
					printf( ": 1st - %d, 2nd - %d, 3rd - %d ", i, background_color, foreground_color );
					std::cout << r2tm::linefeed << r2tm::linefeed;
				}
			}

			LS();

			{
				DECL_MAIN( const char* header = "\033[" );
				DECL_MAIN( const char* tail = "m" );
				DECL_MAIN( const short fg_color = 31 );
				DECL_MAIN( const short bg_color = 44 );

				LF();

				PROC_MAIN( std::cout << header << fg_color << ";" << bg_color << tail << "Change Color with std::cout" << header << "0" << tail << r2tm::linefeed );

				LF();

				PROC_MAIN( std::cout << header << fg_color << tail << header << bg_color << tail << "Change Color with std::cout" << header << "0" << tail << r2tm::linefeed );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}