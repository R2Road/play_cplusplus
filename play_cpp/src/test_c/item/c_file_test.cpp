#include "c_file_test.h"

#include <stdio.h>

#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_Inspector.h"

namespace c_file_test
{
	r2tm::TitleFunctionT OpenAndClose::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "C File : Open And Close";
		};
	}
	r2tm::DoFunctionT OpenAndClose::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			{
				DECLARATION_MAIN( FILE* fp = nullptr );
				EXPECT_EQ( 0, fopen_s( &fp, "resources/c_file_test_openandclose_1.txt", "rb" ) );

				std::cout << r2tm::linefeed;

				PROCESS_MAIN( fclose( fp ) );

				std::cout << r2tm::linefeed2;
				std::cout << r2tm::tab << "+ 한 번 더 불러도 문제가 없다." << r2tm::linefeed2;

				PROCESS_MAIN( fclose( fp ) );
			}

			std::cout << r2tm::split;

			{
				std::cout << r2tm::tab << "+ 터짐" << r2tm::linefeed2;

				OUTPUT_CODE( fclose( nullptr ) );
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT GetCharacter::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "C File : Get Character";
		};
	}
	r2tm::DoFunctionT GetCharacter::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			DECLARATION_MAIN( FILE* fp = nullptr );
			EXPECT_EQ( 0, fopen_s( &fp, "resources/c_file_test_openandclose_1.txt", "rb" ) );

			std::cout << r2tm::split;

			{
				PROCESS_MAIN( while( !feof( fp ) ) printf( "%c", fgetc( fp ) ) );
				std::cout << r2tm::linefeed;
			}

			std::cout << r2tm::split;

			PROCESS_MAIN( fclose( fp ) );

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT GetLine::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "C File : Get Line";
		};
	}
	r2tm::DoFunctionT GetLine::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			DECLARATION_MAIN( FILE* fp = nullptr );
			EXPECT_EQ( 0, fopen_s( &fp, "resources/c_file_test_openandclose_1.txt", "rb" ) );

			std::cout << r2tm::split;

			{
				DECLARATION_MAIN( char temp[256] );
				PROCESS_MAIN( while( !feof( fp ) ) { fgets( temp, sizeof( temp ), fp ); printf( "%s", temp ); } );

				std::cout << r2tm::linefeed;
			}

			std::cout << r2tm::split;

			PROCESS_MAIN( fclose( fp ) );

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}