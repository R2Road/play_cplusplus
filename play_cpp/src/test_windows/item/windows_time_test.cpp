#include "windows_time_test.h"

#include <conio.h>
#include <windows.h>
#pragma comment(lib, "winmm.lib") // for timeGetTime()

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_WindowUtility.h"

#include "r2/r2_FPSTimer.h"

namespace window_time_test
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Windows Time";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			DECLARATION_MAIN( SYSTEMTIME local_time );
			DECLARATION_MAIN( SYSTEMTIME system_time );
			DECLARATION_MAIN( DWORD current_tick = 0 );
			DECLARATION_MAIN( DWORD last_tick = 0 );

			std::cout << r2tm::split;

			std::cout << r2tm::tab << "[ANY KEY] Exit" << r2tm::linefeed;

			std::cout << r2tm::split;

			{
				r2::FPSTimer fps_timer( 30 );
				const auto pivot_point = r2tm::WindowUtility::GetCursorPoint();
				do
				{

					if( fps_timer.Update() )
					{
						r2tm::WindowUtility::MoveCursorPointWithClearBuffer( pivot_point );

						{
							PROCESS_MAIN( GetLocalTime( &local_time ) );
							std::cout << r2tm::tab << local_time.wYear << local_time.wMonth << local_time.wDay << r2tm::linefeed;
							std::cout << r2tm::tab << local_time.wDayOfWeek << r2tm::linefeed;
							std::cout << r2tm::tab << local_time.wHour << local_time.wMinute << local_time.wSecond << r2tm::linefeed;
							std::cout << r2tm::tab << local_time.wMilliseconds << r2tm::linefeed;
						}

						std::cout << r2tm::linefeed;

						{
							PROCESS_MAIN( GetSystemTime( &system_time ) );
							std::cout << r2tm::tab << system_time.wYear << system_time.wMonth << system_time.wDay << r2tm::linefeed;
							std::cout << r2tm::tab << system_time.wDayOfWeek << r2tm::linefeed;
							std::cout << r2tm::tab << system_time.wHour << system_time.wMinute << system_time.wSecond << r2tm::linefeed;
							std::cout << r2tm::tab << system_time.wMilliseconds << r2tm::linefeed;
						}

						std::cout << r2tm::linefeed;

						{
							PROCESS_MAIN( current_tick = GetTickCount() );
							OUTPUT_VALUE( current_tick );

							last_tick = current_tick;
						}

						std::cout << r2tm::linefeed;

						{
							OUTPUT_VALUE( GetTickCount64() );
						}

						std::cout << r2tm::linefeed;

						{
							OUTPUT_VALUE( timeGetTime() );
						}

						std::cout << r2tm::split;
					}

					if( _kbhit() )
					{
						_getch();
						break;
					}

				} while( true );
			}

			return r2tm::eDoLeaveAction::None;
		};
	}
}