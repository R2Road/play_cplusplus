#include "windows_terminal_text_color_test.h"

#include <bitset>
#include <conio.h>
#include <stdio.h>
#include <Windows.h>
#include <wincon.h> // BACKGROUND_RED

#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_Inspector.h"

namespace windows_terminal_text_color_test
{
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

			{
				std::cout << r2tm::tab << "+ Color Table" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "Black" << r2tm::tab3 << "0" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "Blue" << r2tm::tab3 << "1" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "Green" << r2tm::tab3 << "2" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "Aqua" << r2tm::tab3 << "3" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "Red" << r2tm::tab3 << "4" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "Purple" << r2tm::tab3 << "5" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "Yellow" << r2tm::tab3 << "6" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "White" << r2tm::tab3 << "7" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "Gray" << r2tm::tab3 << "8" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "Light Blue" << r2tm::tab2 << "9" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "Light Green" << r2tm::tab2 << "A" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "Light Aqua" << r2tm::tab2 << "B" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "Light Led" << r2tm::tab2 << "C" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "Light Purple" << r2tm::tab2 << "D" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "Light Yellow" << r2tm::tab2 << "E" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "Bright White" << r2tm::tab2 << "F" << r2tm::linefeed;
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
				const char background_color = BACKGROUND_RED;
				const char text_color = FOREGROUND_GREEN;

				const WORD current_color = background_color | text_color | COMMON_LVB_GRID_HORIZONTAL;

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

			HANDLE stdHandle = GetStdHandle( STD_OUTPUT_HANDLE );

			{
				CONSOLE_SCREEN_BUFFER_INFOEX info;
				info.cbSize = sizeof( CONSOLE_SCREEN_BUFFER_INFOEX );
				std::cout << r2tm::tab << "CONSOLE_SCREEN_BUFFER_INFOEX info;" << r2tm::linefeed;
				std::cout << r2tm::tab << "info.cbSize = sizeof( CONSOLE_SCREEN_BUFFER_INFOEX );" << r2tm::linefeed;
				LF();

				GetConsoleScreenBufferInfoEx( stdHandle, &info );
				std::cout << r2tm::tab << "GetConsoleScreenBufferInfoEx( stdHandle, &info );" << r2tm::linefeed;
				LF();

				info.ColorTable[1] = RGB( 255, 100, 100 );
				std::cout << r2tm::tab << "info.ColorTable[1] = RGB( 255, 100, 100 );" << r2tm::linefeed;
				LF();

				SetConsoleScreenBufferInfoEx( stdHandle, &info );
				std::cout << r2tm::tab << "SetConsoleScreenBufferInfoEx( stdHandle, &info );" << r2tm::linefeed;
				LF();
			}

			LS();

			{
				char background_color = 8;
				char text_color = 1;

				WORD current_color = 0;
				current_color = background_color << 4;
				current_color |= text_color;

				std::cout << r2tm::tab << "SetConsoleTextAttribute( stdHandle, current_color );" << r2tm::linefeed;
				SetConsoleTextAttribute( stdHandle, current_color );

				std::cout << r2tm::tab2 << "- " << std::hex << (int)background_color << " : background Color" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "- " << std::hex << (int)text_color << " : text Color" << r2tm::linefeed;
			}

			SetConsoleTextAttribute( stdHandle, 7 ); // bg - black( 0 ), text - white( 7 )

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
				DECLARATION_MAIN( const char* header = "\033[" );
				DECLARATION_MAIN( const char* tail = "m" );
				DECLARATION_MAIN( const short fg_color = 31 );
				DECLARATION_MAIN( const short bg_color = 44 );

				LF();

				PROCESS_MAIN( std::cout << header << fg_color << ";" << bg_color << tail << "Change Color with std::cout" << header << "0" << tail << r2tm::linefeed );

				LF();

				PROCESS_MAIN( std::cout << header << fg_color << tail << header << bg_color << tail << "Change Color with std::cout" << header << "0" << tail << r2tm::linefeed );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}