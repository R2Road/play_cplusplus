#include "serialize_test.h"

#include <vector>

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
	r2cm::iItem::DoFunctionT Basic::GetDoFunction() const
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



	r2cm::iItem::TitleFunctionT Copy::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Serialize : Copy";
		};
	}
	r2cm::iItem::DoFunctionT Copy::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( struct Dummy { int64_t a = 0; int64_t b = 0; } );
			DECLARATION_MAIN( Dummy dummy_1; dummy_1.a = 13; dummy_1.b = -7; );
			DECLARATION_MAIN( Dummy dummy_2 );

			std::cout << r2cm::split;

			{
				OUTPUT_VALUE( dummy_2.a );
				OUTPUT_VALUE( dummy_2.b );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( const auto size = sizeof( dummy_1 ) );
				OUTPUT_VALUE( size );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( std::vector<uint8_t> bytes( size, 0 ) );

				std::cout << r2cm::linefeed2;

				{
					DECLARATION_MAIN( uint8_t* up = reinterpret_cast<uint8_t*>( &dummy_1 ) );
					std::cout << "Loop : bytes[i] = ( *up );" << r2cm::linefeed;
					for( int i = 0; size > i; ++i )
					{
						bytes[i] = ( *up );
						++up;
					}
				}

				std::cout << r2cm::linefeed2;

				{
					DECLARATION_MAIN( uint8_t* up = reinterpret_cast<uint8_t*>( &dummy_2 ) );
					std::cout << "Loop : ( *up ) = bytes[i];" << r2cm::linefeed;
					for( int i = 0; size > i; ++i )
					{
						( *up ) = bytes[i];
						++up;
					}
				}

				std::cout << r2cm::linefeed2;

				EXPECT_EQ( dummy_1.a, dummy_2.a );
				EXPECT_EQ( dummy_1.b, dummy_2.b );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_VALUE( dummy_2.a );
				OUTPUT_VALUE( dummy_2.b );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}