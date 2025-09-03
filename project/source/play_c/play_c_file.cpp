#include "play_c_file.hpp"

#include <stdio.h>
#include <sys/stat.h>

#include "r2tm/r2tm_ostream.hpp"
#include "r2tm/r2tm_inspector.hpp"

namespace play_c_file
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
				OUT_SUBJECT( "Open" );

				LF();

				DECL_MAIN( FILE* fp = nullptr );
				EXPECT_EQ( 0, fopen_s( &fp, "resources/rsc___play_c_file___open_and_close_1.hpp", "rb" ) );

				SS();

				OUT_SUBJECT( "Close" );

				LF();

				PROC_MAIN( fclose( fp ) );

				SS();

				OUT_SUBJECT( "fclose 를 한 번 더 불러도 문제 없다." );

				LF();

				PROC_MAIN( fclose( fp ) );
			}

			LS();

			{
				OUT_NOTE( "이러면 터진다." );

				LF();

				OUT_CODE( fclose( nullptr ) );
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

			OUT_SUBJECT( "한 문자씩 읽는다." );

			LS();

			DECL_MAIN( FILE* fp = nullptr );
			EXPECT_EQ( 0, fopen_s( &fp, "resources/rsc___play_c_file___open_and_close_1.hpp", "rb" ) );

			LS();

			{
				PROC_MAIN( printf( "%c \n", fgetc( fp ) ) );

				LF();

				PROC_MAIN( printf( "%c \n", fgetc( fp ) ) );

				LF();

				PROC_MAIN( printf( "%c \n", fgetc( fp ) ) );

				SS();

				PROC_MAIN( while( !feof( fp ) ) printf( "%c", fgetc( fp ) ) );
				LF();
			}

			LS();

			PROC_MAIN( fclose( fp ) );

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

			OUT_SUBJECT( "한 줄씩 읽는다." );

			LS();

			DECL_MAIN( FILE* fp = nullptr );
			EXPECT_EQ( 0, fopen_s( &fp, "resources/rsc___play_c_file___open_and_close_1.hpp", "rb" ) );

			LF();

			DECL_MAIN( char temp[256] );

			LS();

			{
				PROC_MAIN( fgets( temp, sizeof( temp ), fp ); printf( "%s \n", temp ); );

				LF();

				PROC_MAIN( fgets( temp, sizeof( temp ), fp ); printf( "%s \n", temp ); );

				LF();

				PROC_MAIN( fgets( temp, sizeof( temp ), fp ); printf( "%s \n", temp ); );
			
				SS();

				PROC_MAIN( while( !feof( fp ) ) { fgets( temp, sizeof( temp ), fp ); printf( "%s", temp ); } );
				LF();
			}

			LS();

			PROC_MAIN( fclose( fp ) );

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT GetFormat::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "C File : Get Format";
		};
	}
	r2tm::DoFunctionT GetFormat::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_SUBJECT( "fscanf는 줄을 무시하고 읽는다." );

			LS();

			OUT_FILE( "resources/rsc___play_c_file___get_format_1.txt" );

			LS();

			DECL_MAIN( int a = 0 );
			DECL_MAIN( int b = 0 );
			DECL_MAIN( int last = 0 );

			DECL_MAIN( FILE * fp = nullptr );

			LS();

			EXPECT_EQ( 0, fopen_s( &fp, "resources/rsc___play_c_file___get_format_1.txt", "rb" ) );

			LS();

			{
				PROC_MAIN( fscanf_s( fp, "%d%d %d", &a, &b, &last ); printf( "%d %d    %d \n", a, b, last ); );

				LF();

				PROC_MAIN( a = 0; b = 0; last = 0 );
				PROC_MAIN( fscanf_s( fp, "%d%d %d", &a, &b, &last ); printf( "%d %d    %d \n", a, b, last ); );

				LF();

				PROC_MAIN( a = 0; b = 0; last = 0 );
				PROC_MAIN( fscanf_s( fp, "%d%d %d", &a, &b, &last ); printf( "%d %d    %d \n", a, b, last ); );

				LF();

				PROC_MAIN( while( !feof( fp ) ){ fscanf_s( fp, "%d%d %d", &a, &b, &last ); printf( "%d %d    %d \n", a, b, last ); } );
			}

			LS();

			PROC_MAIN( fclose( fp ) );

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

			DECL_MAIN( const char* path = "resources/temp_4_c_file_test__file_generate.txt" );

			LS();

			{
				OUT_SUBJECT( "파일 없음 확인" );

				LF();

				DECL_MAIN( struct stat s = { 0 } );
				EXPECT_NE( 0, stat( path, &s ) );
			}

			LS();

			{
				OUT_SUBJECT( "파일 생성" );

				LF();

				DECL_MAIN( FILE* fp = nullptr );
				EXPECT_EQ( 0, fopen_s( &fp, path, "w" ) );

				LF();

				PROC_MAIN( fclose( fp ) );

				LF();

				OUT_SUBJECT( "파일 있음 확인" );

				LF();

				DECL_MAIN( struct stat s = { 0 } );
				EXPECT_EQ( 0, stat( path, &s ) );
			}

			LS();

			{
				OUT_SUBJECT( "파일 삭제" );

				LF();

				EXPECT_EQ( 0, remove( path ) );

				LF();

				OUT_SUBJECT( "파일 없음 확인" );

				LF();

				DECL_MAIN( struct stat s = { 0 } );
				EXPECT_NE( 0, stat( path, &s ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}