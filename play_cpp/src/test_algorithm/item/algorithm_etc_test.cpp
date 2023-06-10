#include "algorithm_etc_test.h"

#include "r2tm/r2tm_ostream.h"

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

	r2tm::TitleFunctionT DJB2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "DJB2";
		};
	}
	r2tm::DoFunctionT DJB2::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				std::cout << "djb2_hash( \"a\" );" << r2tm::linefeed;
				std::cout << r2tm::tab << djb2_hash( "a" ) << r2tm::linefeed;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}