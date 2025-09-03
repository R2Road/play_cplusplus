#include "play_cpp_new.hpp"

#include <new>
#include <string_view>

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

namespace play_cpp_new
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
				DECL_MAIN( int* i = new int );

				LF();

				OUT_VALUE( *i );
				OUT_BINARY( *i );

				LF();

				PROC_MAIN( delete i );
			}

			LS();

			{
				DECL_MAIN( int* i = new int( 1 ) );
				EXPECT_EQ( 1, *i );

				LF();

				OUT_VALUE( *i );
				OUT_BINARY( *i );

				LF();

				PROC_MAIN( delete i );
			}

			LS();

			{
				DECL_MAIN( int* i = new ( std::nothrow ) int( 2 ) );
				EXPECT_EQ( 2, *i );

				LF();

				OUT_VALUE( *i );
				OUT_BINARY( *i );

				LF();

				PROC_MAIN( delete i );
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
				DECL_MAIN( int* i = new int[10] );
				OUT_VALUE( *i );
				OUT_VALUE( i[1] );

				LF();

				PROC_MAIN( delete[] i );
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

				OUT_VALUE( i[3] );
				OUT_VALUE( i[4] );

				LF();

				PROC_MAIN( delete[] i );
			}

			LS();

			{
				DECL_MAIN( char* str = new char[7] );
				OUT_VALUE( str );

				LF();

				PROC_MAIN( delete[] str );
			}

			LS();

			{
				DECL_MAIN( char* str = new char[7]{ "abc" } );
				EXPECT_EQ( std::string_view( "abc" ), str );
				EXPECT_EQ( 0, str[3] );
				EXPECT_EQ( '\0', str[3] );

				LF();

				EXPECT_EQ( str[4], str[3] );

				LF();

				PROC_MAIN( delete[] str );
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
				DECL_MAIN( int i = 123 );
				DECL_MAIN( float* fp = new (&i) float );

				OUT_VALUE( *fp );

				LF();

				PROC_MAIN( *fp = 3.14f );
				OUT_VALUE( *fp );
			}

			LS();

			{
				DECL_MAIN( int i = 65 );
				OUT_VALUE( i );
				OUT_BINARY( i );

				LF();

				DECL_MAIN( char* cp = new ( &i ) char );
				OUT_VALUE( *cp );
				OUT_BINARY( *cp );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}