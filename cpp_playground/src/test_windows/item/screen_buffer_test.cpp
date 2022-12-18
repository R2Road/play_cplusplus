#include "screen_buffer_test.h"

#include <assert.h>
#include <conio.h> // _kbhit(), _getch()
#include <cstring>
#include <wchar.h>
#include <Windows.h>

#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_WindowUtility.h"

namespace screen_buffer_test
{
	r2cm::iItem::TitleFunctionT FillBuffer::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Screen Buffer : Fill Buffer";
		};
	}
	r2cm::iItem::DoFunctionT FillBuffer::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE );
			COORD topLeft = { 0, 0 };
			CONSOLE_SCREEN_BUFFER_INFO cs_buffer_info{};
			if( !GetConsoleScreenBufferInfo( hStdout, &cs_buffer_info ) )
			{
				assert( false && "Failed : GetConsoleScreenBufferInfo" );
			}
			const DWORD length = ( cs_buffer_info.srWindow.Right + 1 ) * ( cs_buffer_info.srWindow.Bottom + 1 );
			DWORD out_result;

			std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
			std::cout << r2cm::tab2 << "HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE );" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "COORD topLeft = { 0, 0 };" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "CONSOLE_SCREEN_BUFFER_INFO cs_buffer_info;" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "GetConsoleScreenBufferInfo( hStdout, &cs_buffer_info )" << r2cm::linefeed2;
			std::cout << r2cm::tab2 << "const DWORD length = ( cs_buffer_info.srWindow.Right + 1 ) * ( cs_buffer_info.srWindow.Bottom + 1 );";
			std::cout << r2cm::tab2 << "DWORD out_result;" << r2cm::linefeed;

			std::cout << r2cm::split;

			std::cout << r2cm::tab << "+ Upcoming Process : Fill All Buffer" << r2cm::linefeed2;
			std::cout << r2cm::tab2 << "FillConsoleOutputCharacter( hStdout, TEXT( '#' ), length, topLeft, &out_result );" << r2cm::linefeed2;
			std::cout << r2cm::tab2 << "FillConsoleOutputAttribute( hStdout, FOREGROUND_BLUE, length, topLeft, &out_result );" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "FillConsoleOutputAttribute( hStdout, FOREGROUND_GREEN, length / 2, topLeft, &out_result );" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "FillConsoleOutputAttribute( hStdout, FOREGROUND_RED, length / 3, topLeft, &out_result );" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "FillConsoleOutputAttribute( hStdout, FOREGROUND_INTENSITY, cs_buffer_info.srWindow.Right + 1, topLeft, &out_result );" << r2cm::linefeed;

			std::cout << r2cm::split;

			std::cout << r2cm::tab << "Press Key : Do" << r2cm::linefeed;
			_getch();
			{
				FillConsoleOutputCharacter( hStdout, TEXT( '#' ), length, topLeft, &out_result );

				FillConsoleOutputAttribute( hStdout, FOREGROUND_BLUE, length, topLeft, &out_result );
				FillConsoleOutputAttribute( hStdout, FOREGROUND_GREEN, length / 2, topLeft, &out_result );
				FillConsoleOutputAttribute( hStdout, FOREGROUND_BLUE | FOREGROUND_GREEN, length / 3, topLeft, &out_result );
				FillConsoleOutputAttribute( hStdout, FOREGROUND_INTENSITY, cs_buffer_info.srWindow.Right + 1, topLeft, &out_result );
			}

			std::cout << r2cm::tab << "Press Key : Rollback" << r2cm::linefeed;
			_getch();
			{
				FillConsoleOutputAttribute( hStdout, cs_buffer_info.wAttributes, length, topLeft, &out_result );
			}

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Write2Buffer_WriteConsole::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Screen Buffer : Write 2 Buffer : WriteConsole";
		};
	}
	r2cm::iItem::DoFunctionT Write2Buffer_WriteConsole::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
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



	r2cm::iItem::TitleFunctionT Write2Buffer_WriteConsoleOutput::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Screen Buffer : Write 2 Buffer : WriteConsoleOutput";
		};
	}
	r2cm::iItem::DoFunctionT Write2Buffer_WriteConsoleOutput::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
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



	r2cm::iItem::TitleFunctionT ReadConsoleOutputTest::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Screen Buffer : ReadConsoleOutputTest";
		};
	}
	r2cm::iItem::DoFunctionT ReadConsoleOutputTest::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE ) );
			DECLARATION_MAIN( DWORD ret = 0; );
			DECLARATION_MAIN( const char str[21] = "한글출력테스트팔구십" );
			DECLARATION_MAIN( const wchar_t wstr[21] = L"한글출력테스트일이십" );

			std::cout << r2cm::split;
			
			{
				const auto cursor_point = r2cm::WindowUtility::GetCursorPoint();
				WriteConsoleOutputCharacterA( hStdout, str, static_cast<DWORD>( strlen( str ) ), { cursor_point.x, cursor_point.y }, &ret );

				std::cout << r2cm::linefeed2;

				DECLARATION_MAIN( char buffer[100] = { 0 } );
				PROCESS_MAIN( ReadConsoleOutputCharacterA( hStdout, buffer, 10, { cursor_point.x, cursor_point.y }, &ret ) );

				std::cout << r2cm::linefeed2;

				PROCESS_MAIN( std::cout << buffer );
			}

			std::cout << r2cm::split;

			{
				const auto cursor_point = r2cm::WindowUtility::GetCursorPoint();
				WriteConsoleOutputCharacterW( hStdout, wstr, static_cast<DWORD>( wcslen( wstr ) ), { cursor_point.x, cursor_point.y }, &ret );

				std::cout << r2cm::linefeed2;

				DECLARATION_MAIN( wchar_t buffer[100] = { 0 } );
				PROCESS_MAIN( ReadConsoleOutputCharacterW( hStdout, buffer, 10, { cursor_point.x, cursor_point.y }, &ret ) );

				std::cout << r2cm::linefeed2;

				PROCESS_MAIN( std::wcout.imbue( std::locale( "kor" ) ) );
				PROCESS_MAIN( std::wcout << buffer );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "# ReadConsoleOutputCharacterW 를 활용해 가져온 문자열은 인코딩이 필요한 것 같다." << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT ETCTest::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Screen Buffer : ETC";
		};
	}
	r2cm::iItem::DoFunctionT ETCTest::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( char buffer[111] = { '0' } );
				memset( buffer, 'A', sizeof( buffer ) );
				buffer[110] = '\0';
				PROCESS_MAIN( std::cout << buffer );

				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( char buffer[111] = { '0' } );
				memset( buffer, 'a', sizeof( buffer ) );
				buffer[110] = '\0';
				PROCESS_MAIN( std::cout << buffer );

				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( char buffer[111] = "한글한글한글한글한글" "한글한글한글한글한글" "한글한글한글한글한글" "한글한글한글한글한글" "한글한글한글한글한글" "한글한글한" );
				PROCESS_MAIN( std::cout << buffer );

				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT DoubleBuffering::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Screen Buffer : Double Buffering";
		};
	}
	r2cm::iItem::DoFunctionT DoubleBuffering::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

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