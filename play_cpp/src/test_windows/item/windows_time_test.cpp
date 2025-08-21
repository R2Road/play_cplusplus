#include "windows_time_test.h"

#include <conio.h>

#define NOMINMAX
#include <windows.h>
#pragma comment(lib, "winmm.lib") // for timeGetTime()

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"
#include "r2tm/r2tm_windows_utility.hpp"

#include "r2/r2_fps_timer.hpp"

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
			LS();

			DECL_MAIN( SYSTEMTIME local_time );
			DECL_MAIN( SYSTEMTIME system_time );
			DECL_MAIN( DWORD current_tick = 0 );
			DECL_MAIN( DWORD last_tick = 0 );

			LS();

			std::cout << r2tm::tab << "[ANY KEY] Exit" << r2tm::linefeed;

			LS();

			{
				r2::FPSTimer fps_timer( 30 );
				const auto pivot_point = r2tm::WindowsUtility::GetCursorPoint();
				do
				{

					if( fps_timer.Update() )
					{
						r2tm::WindowsUtility::MoveCursorPointWithClearBuffer( pivot_point );

						{
							PROC_MAIN( GetLocalTime( &local_time ) );
							std::cout << r2tm::tab << local_time.wYear << local_time.wMonth << local_time.wDay << r2tm::linefeed;
							std::cout << r2tm::tab << local_time.wDayOfWeek << r2tm::linefeed;
							std::cout << r2tm::tab << local_time.wHour << local_time.wMinute << local_time.wSecond << r2tm::linefeed;
							std::cout << r2tm::tab << local_time.wMilliseconds << r2tm::linefeed;
						}

						LF();

						{
							PROC_MAIN( GetSystemTime( &system_time ) );
							std::cout << r2tm::tab << system_time.wYear << system_time.wMonth << system_time.wDay << r2tm::linefeed;
							std::cout << r2tm::tab << system_time.wDayOfWeek << r2tm::linefeed;
							std::cout << r2tm::tab << system_time.wHour << system_time.wMinute << system_time.wSecond << r2tm::linefeed;
							std::cout << r2tm::tab << system_time.wMilliseconds << r2tm::linefeed;
						}

						LF();

						{
							PROC_MAIN( current_tick = GetTickCount() );
							OUTPUT_VALUE( current_tick );

							last_tick = current_tick;
						}

						LF();

						{
							OUTPUT_VALUE( GetTickCount64() );
						}

						LF();

						{
							OUTPUT_VALUE( timeGetTime() );
						}

						LS();
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