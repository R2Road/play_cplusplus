#include "windows_time_test.h"

#include <conio.h>
#include <windows.h>
#pragma comment(lib, "winmm.lib") // for timeGetTime()

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_WindowUtility.h"

namespace window_time_test
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Windows Time";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			DECLARATION_MAIN( SYSTEMTIME local_time );
			DECLARATION_MAIN( SYSTEMTIME system_time );
			DECLARATION_MAIN( DWORD current_tick = 0 );
			DECLARATION_MAIN( DWORD last_tick = 0 );

			std::cout << r2cm::split;

			std::cout << "[ANY KEY] Exit" << r2cm::linefeed2;

			const auto pivot_point = r2cm::WindowUtility::GetCursorPoint();
			while( true )
			{
				r2cm::WindowUtility::MoveCursorPointWithClearBuffer( pivot_point );

				{
					PROCESS_MAIN( GetLocalTime( &local_time ) );
					std::cout << r2cm::tab << local_time.wYear << local_time.wMonth << local_time.wDay << r2cm::linefeed;
					std::cout << r2cm::tab << local_time.wDayOfWeek << r2cm::linefeed;
					std::cout << r2cm::tab << local_time.wHour << local_time.wMinute << local_time.wSecond << r2cm::linefeed;
					std::cout << r2cm::tab << local_time.wMilliseconds << r2cm::linefeed;
				}

				std::cout << r2cm::linefeed;

				{
					PROCESS_MAIN( GetSystemTime( &system_time ) );
					std::cout << r2cm::tab << system_time.wYear << system_time.wMonth << system_time.wDay << r2cm::linefeed;
					std::cout << r2cm::tab << system_time.wDayOfWeek << r2cm::linefeed;
					std::cout << r2cm::tab << system_time.wHour << system_time.wMinute << system_time.wSecond << r2cm::linefeed;
					std::cout << r2cm::tab << system_time.wMilliseconds << r2cm::linefeed;
				}

				std::cout << r2cm::linefeed;

				{
					PROCESS_MAIN( current_tick = GetTickCount() );
					OUTPUT_VALUE( current_tick );

					last_tick = current_tick;
				}

				std::cout << r2cm::linefeed;

				{
					OUTPUT_VALUE( GetTickCount64() );
				}

				std::cout << r2cm::linefeed;

				{
					OUTPUT_VALUE( timeGetTime() );
				}

				std::cout << r2cm::split;

				if( _kbhit() )
				{
					_getch();
					break;
				}
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::None;
		};
	}
}