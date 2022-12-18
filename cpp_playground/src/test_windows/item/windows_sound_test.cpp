#include "windows_sound_test.h"

#include <conio.h>
#include <Windows.h>
#pragma comment( lib, "winmm.lib" )

#include "r2cm/r2cm_ostream.h"

#include "utility/r2utility_FileUtil.h"

namespace windows_sound_test
{
	r2cm::iItem::TitleFunctionT PlaySoundTest::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "mmsystem : PlaySound";
		};
	}
	r2cm::iItem::DoFunctionT PlaySoundTest::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			std::cout << "[ESC]" " Exit" << r2cm::linefeed;
			std::cout << "[1]" " Play SFX 1" << r2cm::linefeed;
			std::cout << "[2]" " Play SFX 2" << r2cm::linefeed;

			std::cout << r2cm::split;

			int input = 0;
			do
			{

				input = _getch();
				switch( input )
				{
				case '1':
				{
					const std::string sfx_path = r2utility::MakeSFXPath( "rpg_sounds_kenney_bookopen.wav" );
					PlaySoundA( sfx_path.c_str(), NULL, SND_FILENAME | SND_ASYNC );
				}
				break;

				case '2':
				{
					const std::string sfx_path = r2utility::MakeSFXPath( "rpg_sounds_kenney_handlecoins2.wav" );
					PlaySoundA( sfx_path.c_str(), NULL, SND_FILENAME | SND_ASYNC );
				}
				break;
				}

			} while( 27 != input );

			return r2cm::eItemLeaveAction::None;
		};
	}



	r2cm::iItem::TitleFunctionT BeepTest::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "utilapiset : Beep";
		};
	}
	r2cm::iItem::DoFunctionT BeepTest::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			std::cout << "[ESC]" " Exit" << r2cm::linefeed;
			std::cout << "[1]" " Play Beep" << r2cm::linefeed;
			std::cout << "[2]" " Play Beep" << r2cm::linefeed;

			std::cout << r2cm::split;

			int input = 0;
			do
			{

				input = _getch();
				switch( input )
				{
				case '1':
				{
					Beep( 440, 300 );
				}
				break;
				case '2':
				{
					Beep( 110, 30 );
				}
				break;
				}

			} while( 27 != input );

			return r2cm::eItemLeaveAction::None;
		};
	}
}