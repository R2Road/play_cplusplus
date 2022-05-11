#include "pch.h"
#include "console_buffer_test.h"

#include <assert.h>
#include <conio.h> // _kbhit(), _getch()
#include <cstring>
#include <Windows.h>

#include "r2cm/r2cm_constant.h"
#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_WindowUtility.h"

namespace console_buffer_test
{
	r2cm::iItem::TitleFuncT FillBuffer::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Fill Buffer";
		};
	}
	r2cm::iItem::DoFuncT FillBuffer::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE );
			COORD topLeft = { 0, 0 };
			CONSOLE_SCREEN_BUFFER_INFO cs_buffer_info{};
			if( !GetConsoleScreenBufferInfo( hStdout, &cs_buffer_info ) )
			{
				assert( false && "Failed : GetConsoleScreenBufferInfo" );
			}
			const DWORD length = cs_buffer_info.dwSize.X * cs_buffer_info.dwSize.Y;
			DWORD out_result;

			std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
			std::cout << r2cm::tab2 << "HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE );" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "COORD topLeft = { 0, 0 };" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "CONSOLE_SCREEN_BUFFER_INFO cs_buffer_info;" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "GetConsoleScreenBufferInfo( hStdout, &cs_buffer_info )" << r2cm::linefeed2;
			std::cout << r2cm::tab2 << "const DWORD length = cs_buffer_info.dwSize.X * cs_buffer_info.dwSize.Y;" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "DWORD out_result;" << r2cm::linefeed;

			std::cout << r2cm::split;

			std::cout << r2cm::tab << "+ Upcoming Process : Fill All Buffer" << r2cm::linefeed2;
			std::cout << r2cm::tab2 << "FillConsoleOutputCharacter( hStdout, TEXT( '#' ), length, topLeft, &out_result );" << r2cm::linefeed2;
			std::cout << r2cm::tab2 << "FillConsoleOutputAttribute( hStdout, FOREGROUND_BLUE, length, topLeft, &out_result );" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "FillConsoleOutputAttribute( hStdout, FOREGROUND_GREEN, length / 2, topLeft, &out_result );" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "FillConsoleOutputAttribute( hStdout, FOREGROUND_RED, length / 3, topLeft, &out_result );" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "FillConsoleOutputAttribute( hStdout, FOREGROUND_INTENSITY, length / 4, topLeft, &out_result );" << r2cm::linefeed;

			std::cout << r2cm::split;

			std::cout << r2cm::tab << "Press Key : Do" << r2cm::linefeed;

			if( _getch() )
			{
				FillConsoleOutputCharacter( hStdout, TEXT( '#' ), length, topLeft, &out_result );

				FillConsoleOutputAttribute( hStdout, FOREGROUND_BLUE, length, topLeft, &out_result );
				FillConsoleOutputAttribute( hStdout, FOREGROUND_GREEN, length / 2, topLeft, &out_result );
				FillConsoleOutputAttribute( hStdout, FOREGROUND_BLUE | FOREGROUND_GREEN, length / 3, topLeft, &out_result );
				FillConsoleOutputAttribute( hStdout, FOREGROUND_INTENSITY, length / 4, topLeft, &out_result );
			}

			std::cout << r2cm::tab << "Press Key : Rollback" << r2cm::linefeed;
			_getch();

			FillConsoleOutputAttribute( hStdout, cs_buffer_info.wAttributes, length, topLeft, &out_result );

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT Write2Buffer_WriteConsole::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Write 2 Buffer : WriteConsole";
		};
	}
	r2cm::iItem::DoFuncT Write2Buffer_WriteConsole::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE );
				const char* str = "*************WriteConsole Test*************";

				std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE );" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "const char* str = \"*************WriteConsole Test*************\";" << r2cm::linefeed;

				std::cout << r2cm::split;

				std::cout << r2cm::tab << "+ Process" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "WriteConsoleA( hStdout, str, sizeof( str ), nullptr, nullptr );" << r2cm::linefeed;

				std::cout << r2cm::split;

				WriteConsoleA( hStdout, str, static_cast<DWORD>( strlen( str ) ), nullptr, nullptr ); // 64bit size_t == typedef unsigned __int64 size_t; 

				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT Write2Buffer_WriteConsoleOutput::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Write 2 Buffer : WriteConsoleOutput";
		};
	}
	r2cm::iItem::DoFuncT Write2Buffer_WriteConsoleOutput::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE );
			COORD topLeft = { 0, 0 };

			{
				std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE );" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "COORD topLeft = { 0, 0 };" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Process" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "DWORD ret;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "const char* str = \"*************WriteConsole Test*************\";" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "WriteConsoleOutputCharacterA( hStdout, str, static_cast<DWORD>( strlen( str ) ), topLeft, &ret );" << r2cm::linefeed;

				DWORD ret;
				const char* str = "*************WriteConsole Test*************";
				WriteConsoleOutputCharacterA( hStdout, str, static_cast<DWORD>( strlen( str ) ), topLeft, &ret );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Process" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "DWORD ret;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "WORD colors[10];" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "std::fill_n( colors, 10, FOREGROUND_GREEN | BACKGROUND_BLUE );" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "WriteConsoleOutputAttribute( hStdout, colors, static_cast<DWORD>( sizeof( colors ) / sizeof( DWORD ) ), topLeft, &ret );" << r2cm::linefeed;

				DWORD ret;
				WORD colors[10];
				std::fill_n( colors, 10, static_cast<WORD>( FOREGROUND_GREEN | BACKGROUND_BLUE ) );
				WriteConsoleOutputAttribute( hStdout, colors, static_cast<DWORD>( sizeof( colors ) / sizeof( DWORD ) ), topLeft, &ret );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT ClearBufferWithCusorMove::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Clear Buffer With Cusor Move";
		};
	}
	r2cm::iItem::DoFuncT ClearBufferWithCusorMove::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				std::cout << "ddddddddddddddddduuuuuuuuuuummmmmmmmmmmyyyyyyyyyyyyyyyyyy" << r2cm::linefeed;
				std::cout << "ddddddddddddddddduuuuuuuuuuummmmmmmmmmmyyyyyyyyyyyyyyyyyy" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			DECLARATION_MAIN( const auto last_cursor_point = r2utility::GetCursorPoint() );

			std::cout << r2cm::split;

			for( int i = 0; 20 > i; ++i )
			{
				std::cout << "ddddddddddddddddduuuuuuuuuuummmmmmmmmmmyyyyyyyyyyyyyyyyyy" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			std::cout << "[Any Key] Move Cursor with Clear Buffer";
			_getch();

			PROCESS_MAIN( r2utility::MoveCursorPointWithClearBuffer( last_cursor_point ) );

			std::cout << "[Any Key] End";
			_getch();

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT ReadConsoleOutputTest::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Console Buffer : ReadConsoleOutputTest";
		};
	}
	r2cm::iItem::DoFuncT ReadConsoleOutputTest::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE );
			COORD topLeft = { 0, 0 };

			//ReadConsoleOutputAttribute( hStdout, )

			{
				std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE );" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "COORD topLeft = { 0, 0 };" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Process" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "DWORD ret;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "const char* str = \"*************WriteConsole Test*************\";" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "WriteConsoleOutputCharacterA( hStdout, str, static_cast<DWORD>( strlen( str ) ), topLeft, &ret );" << r2cm::linefeed;

				DWORD ret;
				const char* str = "*************WriteConsole Test*************";
				WriteConsoleOutputCharacterA( hStdout, str, static_cast<DWORD>( strlen( str ) ), topLeft, &ret );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Process" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "DWORD ret;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "WORD colors[10];" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "std::fill_n( colors, 10, FOREGROUND_GREEN | BACKGROUND_BLUE );" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "WriteConsoleOutputAttribute( hStdout, colors, static_cast<DWORD>( sizeof( colors ) / sizeof( DWORD ) ), topLeft, &ret );" << r2cm::linefeed;

				DWORD ret;
				WORD colors[10];
				std::fill_n( colors, 10, static_cast<WORD>( FOREGROUND_GREEN | BACKGROUND_BLUE ) );
				WriteConsoleOutputAttribute( hStdout, colors, static_cast<DWORD>( sizeof( colors ) / sizeof( DWORD ) ), topLeft, &ret );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT DoubleBuffering::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Double Buffering";
		};
	}
	r2cm::iItem::DoFuncT DoubleBuffering::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << "[ESC] Exit" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				DWORD out_result;

				auto hFirstBuffer = GetStdHandle( STD_OUTPUT_HANDLE );
				CONSOLE_SCREEN_BUFFER_INFO first_csbi{};
				if( !GetConsoleScreenBufferInfo( hFirstBuffer, &first_csbi ) )
				{
					assert( false && "Failed : GetConsoleScreenBufferInfo" );
				}
				const DWORD length = first_csbi.dwSize.X * first_csbi.dwSize.Y;
				FillConsoleOutputCharacter( hFirstBuffer, TEXT( '1' ), length, { 0, 0 }, &out_result );

				auto hSecondBuffer = CreateConsoleScreenBuffer(
					GENERIC_READ | GENERIC_WRITE
					, FILE_SHARE_WRITE | FILE_SHARE_READ
					, nullptr
					, CONSOLE_TEXTMODE_BUFFER
					, nullptr
				);
				SetConsoleScreenBufferSize( hSecondBuffer, first_csbi.dwSize );
				CONSOLE_SCREEN_BUFFER_INFO second_csbi{};
				if( !GetConsoleScreenBufferInfo( hSecondBuffer, &second_csbi ) )
				{
					assert( false && "Failed : GetConsoleScreenBufferInfo" );
				}
				FillConsoleOutputCharacter( hSecondBuffer, TEXT( '2' ), length, { 0, 0 }, &out_result );

				bool bUseFirst = true;
				do
				{
					if( _kbhit() )
					{
						if( _getch() )
						{
							break;
						}
					}

					if( bUseFirst )
					{
						SetConsoleActiveScreenBuffer( hFirstBuffer );
					}
					else
					{
						SetConsoleActiveScreenBuffer( hSecondBuffer );
					}

					bUseFirst = !bUseFirst;
				} while( true );

				//
				// Rollback
				//
				{
					SetConsoleActiveScreenBuffer( hFirstBuffer );
				}
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::None;
		};
	}
}