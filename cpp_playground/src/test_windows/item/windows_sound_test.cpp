#include "pch.h"
#include "windows_sound_test.h"

#include <conio.h>
#include <Windows.h>
#pragma comment( lib, "winmm.lib" )

#include "r2cm/r2cm_constant.h"

#include "utility/r2utility_FileUtil.h"

namespace windows_sound_test
{
	r2cm::iItem::TitleFuncT PlaySoundTest::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "mmsystem : PlaySound";
		};
	}
	r2cm::iItem::DoFuncT PlaySoundTest::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()()  << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			std::cout << "[ESC]" " Exit" << r2cm::linefeed;
			std::cout << "[1]" " Play SFX 1" << r2cm::linefeed;
			std::cout << "[2]" " Play SFX 2" << r2cm::linefeed;

			std::cout << r2cm::split;

			bool bPlay = true;
			do
			{
				if( _kbhit() )
				{
					switch( _getch() )
					{
					case  49: // 1
					{
						const std::string sfx_path = r2utility::MakeSFXPath( "rpg_sounds_kenney_bookopen.wav" );
						PlaySoundA( sfx_path.c_str(), NULL, SND_FILENAME | SND_ASYNC );
					}
					break;

					case  50: // 2
					{
						const std::string sfx_path = r2utility::MakeSFXPath( "rpg_sounds_kenney_handlecoins2.wav" );
						PlaySoundA( sfx_path.c_str(), NULL, SND_FILENAME | SND_ASYNC );
					}
					break;

					case  27: // ESC
						bPlay = false;
						break;
					}
				}
			} while( bPlay );

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT BeepTest::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "utilapiset : Beep";
		};
	}
	r2cm::iItem::DoFuncT BeepTest::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			std::cout << "[ESC]" " Exit" << r2cm::linefeed;
			std::cout << "[1]" " Play Beep" << r2cm::linefeed;

			std::cout << r2cm::split;

			bool bPlay = true;
			do
			{
				if( _kbhit() )
				{
					switch( _getch() )
					{
					case  49: // 1
					{
						Beep( 440, 300 );
					}
					break;

					case  27: // ESC
						bPlay = false;
						break;
					}
				}
			} while( bPlay );

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}