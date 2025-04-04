#include "windows_sound_test.h"

#include <conio.h>
#include <Windows.h>
#pragma comment( lib, "winmm.lib" )

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

#include "utility/play_cpp_utility_PathBuilder.h"

namespace windows_sound_test
{
	r2tm::TitleFunctionT PlaySoundTest::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "mmsystem : PlaySound";
		};
	}
	r2tm::DoFunctionT PlaySoundTest::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_STRING( "[ESC]"  " "  "Exit" );
			OUTPUT_STRING( "[ 1 ]"  " "  "Play SFX 1" );
			OUTPUT_STRING( "[ 2 ]"  " "  "Play SFX 2" );

			LS();

			int input = 0;
			do
			{

				input = _getch();
				switch( input )
				{
				case '1':
				{
					const std::string sfx_path = play_cpp_utility::BuildSFXPath( "rpg_sounds_kenney_bookopen.wav" );
					PlaySoundA( sfx_path.c_str(), NULL, SND_FILENAME | SND_ASYNC );
				}
				break;

				case '2':
				{
					const std::string sfx_path = play_cpp_utility::BuildSFXPath( "rpg_sounds_kenney_handlecoins2.wav" );
					PlaySoundA( sfx_path.c_str(), NULL, SND_FILENAME | SND_ASYNC );
				}
				break;
				}

			} while( 27 != input );

			return r2tm::eDoLeaveAction::None;
		};
	}



	r2tm::TitleFunctionT BeepTest::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "utilapiset : Beep";
		};
	}
	r2tm::DoFunctionT BeepTest::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_STRING( "[ESC]"  " "  "Exit" );
			OUTPUT_STRING( "[ 1 ]"  " "  "Play Beep" );
			OUTPUT_STRING( "[ 2 ]"  " "  "Play Beep" );

			LS();

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

			return r2tm::eDoLeaveAction::None;
		};
	}
}