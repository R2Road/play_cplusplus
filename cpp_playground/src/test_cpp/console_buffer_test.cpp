#include "pch.h"
#include "console_buffer_test.h"

#include <assert.h>
#include <conio.h> // _kbhit(), _getch()
#include <cstring>
#include <Windows.h>

#include "base/r2_eTestResult.h"

namespace console_buffer_test
{
	r2::iTest::TitleFunc FillBuffer::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Fill Buffer";
		};
	}
	r2::iTest::DoFunc FillBuffer::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE );
			COORD topLeft = { 0, 0 };
			CONSOLE_SCREEN_BUFFER_INFO cs_buffer_info{};
			assert( GetConsoleScreenBufferInfo( hStdout, &cs_buffer_info ) && "Failed : GetConsoleScreenBufferInfo" );
			const DWORD length = cs_buffer_info.dwSize.X * cs_buffer_info.dwSize.Y;
			DWORD out_result;

			std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
			std::cout << r2::tab2 << "HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE );" << r2::linefeed;
			std::cout << r2::tab2 << "COORD topLeft = { 0, 0 };" << r2::linefeed;
			std::cout << r2::tab2 << "CONSOLE_SCREEN_BUFFER_INFO cs_buffer_info;" << r2::linefeed;
			std::cout << r2::tab2 << "GetConsoleScreenBufferInfo( hStdout, &cs_buffer_info )" << r2::linefeed2;
			std::cout << r2::tab2 << "const DWORD length = cs_buffer_info.dwSize.X * cs_buffer_info.dwSize.Y;" << r2::linefeed;
			std::cout << r2::tab2 << "DWORD out_result;" << r2::linefeed;

			std::cout << r2::split;

			std::cout << r2::tab << "+ Upcoming Process : Fill All Buffer" << r2::linefeed2;
			std::cout << r2::tab2 << "FillConsoleOutputCharacter( hStdout, TEXT( '#' ), length, topLeft, &out_result );" << r2::linefeed2;
			std::cout << r2::tab2 << "FillConsoleOutputAttribute( hStdout, FOREGROUND_BLUE, length, topLeft, &out_result );" << r2::linefeed;
			std::cout << r2::tab2 << "FillConsoleOutputAttribute( hStdout, FOREGROUND_GREEN, length / 2, topLeft, &out_result );" << r2::linefeed;
			std::cout << r2::tab2 << "FillConsoleOutputAttribute( hStdout, FOREGROUND_RED, length / 3, topLeft, &out_result );" << r2::linefeed;
			std::cout << r2::tab2 << "FillConsoleOutputAttribute( hStdout, FOREGROUND_INTENSITY, length / 4, topLeft, &out_result );" << r2::linefeed;

			std::cout << r2::split;

			std::cout << r2::tab << "Press Key : Do" << r2::linefeed;

			if( _getch() )
			{
				FillConsoleOutputCharacter( hStdout, TEXT( '#' ), length, topLeft, &out_result );

				FillConsoleOutputAttribute( hStdout, FOREGROUND_BLUE, length, topLeft, &out_result );
				FillConsoleOutputAttribute( hStdout, FOREGROUND_GREEN, length / 2, topLeft, &out_result );
				FillConsoleOutputAttribute( hStdout, FOREGROUND_RED, length / 3, topLeft, &out_result );
				FillConsoleOutputAttribute( hStdout, FOREGROUND_INTENSITY, length / 4, topLeft, &out_result );
			}

			std::cout << r2::tab << "Press Key : Rollback" << r2::linefeed;
			_getch();

			FillConsoleOutputAttribute( hStdout, cs_buffer_info.wAttributes, length, topLeft, &out_result );

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc Write2Buffer::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Write 2 Buffer";
		};
	}
	r2::iTest::DoFunc Write2Buffer::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE );
				const char* str = "*************WriteConsole Test*************";

				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE );" << r2::linefeed;
				std::cout << r2::tab2 << "const char* str = \"*************WriteConsole Test*************\";" << r2::linefeed;

				std::cout << r2::split;

				std::cout << r2::tab << "+ Process" << r2::linefeed2;
				std::cout << r2::tab2 << "WriteConsoleA( hStdout, str, sizeof( str ), nullptr, nullptr );" << r2::linefeed;

				std::cout << r2::split;

				WriteConsoleA( hStdout, str, static_cast<DWORD>( strlen( str ) ), nullptr, nullptr ); // 64bit size_t == typedef unsigned __int64 size_t; 

				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc DoubleBuffering::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Double Buffering";
		};
	}
	r2::iTest::DoFunc DoubleBuffering::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << "[ESC] Exit" << r2::linefeed;

			std::cout << r2::split;

			{
				DWORD out_result;

				auto hFirstBuffer = GetStdHandle( STD_OUTPUT_HANDLE );
				CONSOLE_SCREEN_BUFFER_INFO first_csbi{};
				assert( GetConsoleScreenBufferInfo( hFirstBuffer, &first_csbi ) && "Failed : GetConsoleScreenBufferInfo" );
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
				assert( GetConsoleScreenBufferInfo( hSecondBuffer, &second_csbi ) && "Failed : GetConsoleScreenBufferInfo" );
				FillConsoleOutputCharacter( hSecondBuffer, TEXT( '2' ), length, { 0, 0 }, &out_result );

				bool bUseFirst = true;
				bool process = true;
				do
				{
					if( _kbhit() )
					{
						switch( _getch() )
						{
						case 27: // ESC
							process = false;
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
				} while( process );

				//
				// Rollback
				//
				{
					SetConsoleActiveScreenBuffer( hFirstBuffer );
				}
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest_Without_Pause;
		};
	}
}