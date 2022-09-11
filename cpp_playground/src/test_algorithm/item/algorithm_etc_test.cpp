#include "algorithm_etc_test.h"

#include "r2cm/r2cm_ostream.h"

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

	r2cm::iItem::TitleFunctionT DJB2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "DJB2";
		};
	}
	r2cm::iItem::DoFunctionT DJB2::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				std::cout << "djb2_hash( \"a\" );" << r2cm::linefeed;
				std::cout << r2cm::tab << djb2_hash( "a" ) << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}