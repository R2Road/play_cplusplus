#include "serialize_test.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace serialize_test
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Serialize : Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( struct { int64_t a = 13; int64_t b = -7; } dummy );

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( const auto size = sizeof( dummy ) );
				OUTPUT_VALUE( size );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( uint8_t* up = reinterpret_cast<uint8_t*>( &dummy ) );
				for( int i = 0; size > i; ++i )
				{
					OUTPUT_BINARY( *up );
					++up;
				}
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}