#include "c_file_test.h"

#include <stdio.h>
#include <sys/stat.h>

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
			LS();

			{
				OUTPUT_SUBJECT( "Open" );

				LF();

				DECLARATION_MAIN( FILE* fp = nullptr );
				EXPECT_EQ( 0, fopen_s( &fp, "resources/c_file_test_openandclose_1.txt", "rb" ) );

				LF();

				OUTPUT_SUBJECT( "Close" );

				LF();

				PROCESS_MAIN( fclose( fp ) );

				SS();

				OUTPUT_SUBJECT( "fclose 를 한 번 더 불러도 문제 없다." );

				LF();

				PROCESS_MAIN( fclose( fp ) );
			}

			LS();

			{
				OUTPUT_NOTE( "이러면 터진다." );

				LF();

				OUTPUT_CODE( fclose( nullptr ) );
			}

			LS();

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
			LS();

			OUTPUT_SUBJECT( "한 문자씩 읽는다." );

			LS();

			DECLARATION_MAIN( FILE* fp = nullptr );
			EXPECT_EQ( 0, fopen_s( &fp, "resources/c_file_test_openandclose_1.txt", "rb" ) );

			LS();

			{
				PROCESS_MAIN( printf( "%c \n", fgetc( fp ) ) );

				LF();

				PROCESS_MAIN( printf( "%c \n", fgetc( fp ) ) );

				LF();

				PROCESS_MAIN( printf( "%c \n", fgetc( fp ) ) );

				SS();

				PROCESS_MAIN( while( !feof( fp ) ) printf( "%c", fgetc( fp ) ) );
				LF();
			}

			LS();

			PROCESS_MAIN( fclose( fp ) );

			LS();

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
			LS();

			OUTPUT_SUBJECT( "한 줄씩 읽는다." );

			LS();

			DECLARATION_MAIN( FILE* fp = nullptr );
			EXPECT_EQ( 0, fopen_s( &fp, "resources/c_file_test_openandclose_1.txt", "rb" ) );

			LF();

			DECLARATION_MAIN( char temp[256] );

			LS();

			{
				PROCESS_MAIN( fgets( temp, sizeof( temp ), fp ); printf( "%s \n", temp ); );

				LF();

				PROCESS_MAIN( fgets( temp, sizeof( temp ), fp ); printf( "%s \n", temp ); );

				LF();

				PROCESS_MAIN( fgets( temp, sizeof( temp ), fp ); printf( "%s \n", temp ); );
			
				SS();

				PROCESS_MAIN( while( !feof( fp ) ) { fgets( temp, sizeof( temp ), fp ); printf( "%s", temp ); } );
				LF();
			}

			LS();

			PROCESS_MAIN( fclose( fp ) );

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT FileGenerate::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "C File : File Generate";
		};
	}
	r2tm::DoFunctionT FileGenerate::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( const char* path = "resources/temp_4_c_file_test__file_generate.txt" );

			LS();

			{
				OUTPUT_SUBJECT( "파일 없음 확인" );

				LF();

				DECLARATION_MAIN( struct stat s = { 0 } );
				EXPECT_NE( 0, stat( path, &s ) );
			}

			LS();

			{
				OUTPUT_SUBJECT( "파일 생성" );

				LF();

				DECLARATION_MAIN( FILE* fp = nullptr );
				EXPECT_EQ( 0, fopen_s( &fp, path, "w" ) );

				LF();

				PROCESS_MAIN( fclose( fp ) );

				LF();

				OUTPUT_SUBJECT( "파일 있음 확인" );

				LF();

				DECLARATION_MAIN( struct stat s = { 0 } );
				EXPECT_EQ( 0, stat( path, &s ) );
			}

			LS();

			{
				OUTPUT_SUBJECT( "파일 삭제" );

				LF();

				EXPECT_EQ( 0, remove( path ) );

				LF();

				OUTPUT_SUBJECT( "파일 없음 확인" );

				LF();

				DECLARATION_MAIN( struct stat s = { 0 } );
				EXPECT_NE( 0, stat( path, &s ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}