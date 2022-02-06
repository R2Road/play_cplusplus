#include "pch.h"
#include "console_window_message_test.h"

#include <conio.h>
#define  STRICT
#define  WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "base/r2_eTestResult.h"

namespace console_window_message_test
{
	BOOL WINAPI CtrlHandler( DWORD fdwCtrlType )
	{
		// return TRUE : Message Processed
		// return FALSE : Throw Next

		switch( fdwCtrlType )
		{
			// Handle the CTRL-C signal.
		case CTRL_C_EVENT:
			printf( "Ctrl-C event\n\n" );
			Beep( 750, 300 );
			return TRUE;

			// CTRL-CLOSE: confirm that the user wants to exit.
		case CTRL_CLOSE_EVENT:
			Beep( 600, 200 );
			printf( "Ctrl-Close event\n\n" );
			return TRUE;

			// Pass other signals to the next handler.
		case CTRL_BREAK_EVENT:
			Beep( 900, 200 );
			printf( "Ctrl-Break event\n\n" );
			return TRUE;

		case CTRL_LOGOFF_EVENT:
			Beep( 1000, 200 );
			printf( "Ctrl-Logoff event\n\n" );
			return FALSE;

		case CTRL_SHUTDOWN_EVENT:
			Beep( 750, 500 );
			printf( "Ctrl-Shutdown event\n\n" );
			return FALSE;

		default:
			return FALSE;
		}
	}
	r2::iTest::TitleFunc ConsoleControlHandler::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Window Message : Console Control Handler";
		};
	}
	r2::iTest::DoFunc ConsoleControlHandler::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed2;
			std::cout << "[ESC] End" << r2::linefeed2;
			std::cout << "[Ctrl + C] ..." << r2::linefeed;
			std::cout << "[Ctrl + Break] ..." << r2::linefeed;
			std::cout << "[Close Window] ..." << r2::linefeed;

			std::cout << r2::split;

			std::cout << r2::tab << "+ Ref" << r2::linefeed2;
			std::cout << r2::tab2 << "https://docs.microsoft.com/ko-kr/windows/console/registering-a-control-handler-function" << r2::linefeed;

			std::cout << r2::split;

			std::cout << r2::tab << "+ Message" << r2::linefeed2;
			std::cout << r2::tab2 << "Ctrl + C 를 누르면 디버거가 붙어있는 경우 PDB가 없다며 예외가 터진다." << r2::linefeed;
			std::cout << r2::tab2 << "F5 누르면 계속 실행 된다." << r2::linefeed;
			std::cout << r2::tab2 << "Ctrl + Break 는 메세지 받고 TRUE 를 반환하지 않으면 프로그램이 종료된다." << r2::linefeed;
			std::cout << r2::tab2 << "가급적 Ctrl + F5 로 실행할 것" << r2::linefeed;

			std::cout << r2::split;

			std::cout << "Press Key" << r2::linefeed2;

			if( SetConsoleCtrlHandler( CtrlHandler, TRUE ) )
			{
				do
				{
					if( _kbhit() )
					{
						//
						// ESC
						//
						if( 27 == _getch() )
						{
							break;
						}
					}
				}
				while( 1 );
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}