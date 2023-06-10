#include "cpp_new_test.h"

#include <new>
#include <string_view>

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace cpp_new_test
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				DECLARATION_MAIN( int* i = new int );

				LF();

				OUTPUT_VALUE( *i );
				OUTPUT_BINARY( *i );

				LF();

				PROCESS_MAIN( delete i );
			}

			LS();

			{
				DECLARATION_MAIN( int* i = new int( 1 ) );
				EXPECT_EQ( 1, *i );

				LF();

				OUTPUT_VALUE( *i );
				OUTPUT_BINARY( *i );

				LF();

				PROCESS_MAIN( delete i );
			}

			LS();

			{
				DECLARATION_MAIN( int* i = new ( std::nothrow ) int( 2 ) );
				EXPECT_EQ( 2, *i );

				LF();

				OUTPUT_VALUE( *i );
				OUTPUT_BINARY( *i );

				LF();

				PROCESS_MAIN( delete i );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Array::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Array";
		};
	}
	r2tm::DoFunctionT Array::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				DECLARATION_MAIN( int* i = new int[10] );
				OUTPUT_VALUE( *i );
				OUTPUT_VALUE( i[1] );

				LF();

				PROCESS_MAIN( delete[] i );
			}

			LS();

			{
				int* i = new int[10]{ 0, 1, 2 };

				std::cout << "int* i = new int[10]{ 0, 1, 2 };" << r2tm::linefeed;
				EXPECT_EQ( 0, *i );
				EXPECT_EQ( 1, i[1] );
				EXPECT_EQ( 2, i[2] );
				EXPECT_EQ( 0, i[3] );
				EXPECT_EQ( 0, i[4] );

				LF();

				OUTPUT_VALUE( i[3] );
				OUTPUT_VALUE( i[4] );

				LF();

				PROCESS_MAIN( delete[] i );
			}

			LS();

			{
				DECLARATION_MAIN( char* str = new char[7] );
				OUTPUT_VALUE( str );

				LF();

				PROCESS_MAIN( delete[] str );
			}

			LS();

			{
				DECLARATION_MAIN( char* str = new char[7]{ "abc" } );
				EXPECT_EQ( std::string_view( "abc" ), str );
				EXPECT_EQ( 0, str[3] );
				EXPECT_EQ( '\0', str[3] );

				LF();

				EXPECT_EQ( str[4], str[3] );

				LF();

				PROCESS_MAIN( delete[] str );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT PlacementNew::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Placement New";
		};
	}
	r2tm::DoFunctionT PlacementNew::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				DECLARATION_MAIN( int i = 123 );
				DECLARATION_MAIN( float* fp = new (&i) float );

				OUTPUT_VALUE( *fp );

				LF();

				PROCESS_MAIN( *fp = 3.14f );
				OUTPUT_VALUE( *fp );
			}

			LS();

			{
				DECLARATION_MAIN( int i = 65 );
				OUTPUT_VALUE( i );
				OUTPUT_BINARY( i );

				LF();

				DECLARATION_MAIN( char* cp = new ( &i ) char );
				OUTPUT_VALUE( *cp );
				OUTPUT_BINARY( *cp );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}