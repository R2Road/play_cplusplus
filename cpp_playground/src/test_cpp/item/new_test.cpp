#include "new_test.h"

#include <new>
#include <string_view>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace new_test
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( int* i = new int );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( *i );
				OUTPUT_BINARY( *i );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( delete i );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( int* i = new int( 1 ) );
				EXPECT_EQ( 1, *i );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( *i );
				OUTPUT_BINARY( *i );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( delete i );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( int* i = new ( std::nothrow ) int( 2 ) );
				EXPECT_EQ( 2, *i );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( *i );
				OUTPUT_BINARY( *i );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( delete i );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Array::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Array";
		};
	}
	r2cm::iItem::DoFunctionT Array::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( int* i = new int[10] );
				OUTPUT_VALUE( *i );
				OUTPUT_VALUE( i[1] );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( delete[] i );
			}

			std::cout << r2cm::split;

			{
				int* i = new int[10]{ 0, 1, 2 };

				std::cout << "int* i = new int[10]{ 0, 1, 2 };" << r2cm::linefeed;
				EXPECT_EQ( 0, *i );
				EXPECT_EQ( 1, i[1] );
				EXPECT_EQ( 2, i[2] );
				EXPECT_EQ( 0, i[3] );
				EXPECT_EQ( 0, i[4] );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( i[3] );
				OUTPUT_VALUE( i[4] );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( delete[] i );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( char* str = new char[7] );
				OUTPUT_VALUE( str );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( delete[] str );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( char* str = new char[7]{ "abc" } );
				EXPECT_EQ( std::string_view( "abc" ), str );
				EXPECT_EQ( 0, str[3] );
				EXPECT_EQ( '\0', str[3] );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( str[4], str[3] );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( delete[] str );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT PlacementNew::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Placement New";
		};
	}
	r2cm::iItem::DoFunctionT PlacementNew::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( int i = 123 );
				DECLARATION_MAIN( float* fp = new (&i) float );

				OUTPUT_VALUE( *fp );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( *fp = 3.14f );
				OUTPUT_VALUE( *fp );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( int i = 65 );
				OUTPUT_VALUE( i );
				OUTPUT_BINARY( i );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( char* cp = new ( &i ) char );
				OUTPUT_VALUE( *cp );
				OUTPUT_BINARY( *cp );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}