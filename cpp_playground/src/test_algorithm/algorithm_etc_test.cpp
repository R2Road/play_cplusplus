#include "pch.h"
#include "algorithm_etc_test.h"

#include <conio.h> // _kbhit(), _getch()
#include <Windows.h>

#include "base/r2cm_eTestEndAction.h"

//
// # REF
// http://www.cse.yorku.ca/~oz/hash.html
//

namespace algorithm_etc_test
{
	unsigned long djb2_hash( const char* str )
	{
		unsigned long hash = 5381;
		int c;

		while( c = *str++ )
		{
			hash = ( ( hash << 5 ) + hash ) + c; /* hash * 33 + c */
		}

		return hash;
	}

	r2cm::iItem::TitleFuncT DJB2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "DJB2";
		};
	}
	r2cm::iItem::DoFuncT DJB2::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;
			
			std::cout << r2::split;

			{
				std::cout << "djb2_hash( \"a\" );" << r2::linefeed;
				std::cout << r2::tab << djb2_hash( "a" ) << r2::linefeed;
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}
}