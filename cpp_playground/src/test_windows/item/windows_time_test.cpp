#include "windows_time_test.h"

#include <conio.h>
#include <windows.h>
#pragma comment(lib, "winmm.lib") // for timeGetTime()

#include "r2cm/r2cm_ostream.h"

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
			SYSTEMTIME local_time;
			SYSTEMTIME system_time;
			DWORD current_tick = 0;
			DWORD last_tick = 0;

			while( true )
			{
				GetLocalTime( &local_time );
				GetSystemTime( &system_time );
				current_tick = GetTickCount();

				if( last_tick + 16 < current_tick ) // 60fps
				{

					system( "cls" );

					std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed2;
					std::cout << "[ANY KEY] Exit" << r2cm::linefeed;

					std::cout << r2cm::split;

					{
						std::cout << r2cm::tab << "GetLocalTime( &local_time );" << r2cm::linefeed;
						std::cout << r2cm::tab2 << local_time.wYear << local_time.wMonth << local_time.wDay << r2cm::linefeed;
						std::cout << r2cm::tab2 << local_time.wDayOfWeek << r2cm::linefeed;
						std::cout << r2cm::tab2 << local_time.wHour << local_time.wMinute << local_time.wSecond << r2cm::linefeed;
						std::cout << r2cm::tab2 << local_time.wMilliseconds << r2cm::linefeed;
					}

					std::cout << r2cm::split;

					{
						std::cout << r2cm::tab << "GetSystemTime( &system_time );" << r2cm::linefeed;
						std::cout << r2cm::tab2 << system_time.wYear << system_time.wMonth << system_time.wDay << r2cm::linefeed;
						std::cout << r2cm::tab2 << system_time.wDayOfWeek << r2cm::linefeed;
						std::cout << r2cm::tab2 << system_time.wHour << system_time.wMinute << system_time.wSecond << r2cm::linefeed;
						std::cout << r2cm::tab2 << system_time.wMilliseconds << r2cm::linefeed;
					}

					std::cout << r2cm::split;

					{
						std::cout << r2cm::tab << "tick = GetTickCount();" << r2cm::linefeed;
						std::cout << r2cm::tab2 << current_tick << r2cm::linefeed;

						last_tick = current_tick;
					}

					std::cout << r2cm::split;

					{
						std::cout << r2cm::tab << "GetTickCount64();" << r2cm::linefeed;
						std::cout << r2cm::tab2 << GetTickCount64() << r2cm::linefeed;
					}

					std::cout << r2cm::split;

					{
						std::cout << r2cm::tab << "timeGetTime();" << r2cm::linefeed;
						std::cout << r2cm::tab2 << timeGetTime() << r2cm::linefeed;
					}

					std::cout << r2cm::split;
				}

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