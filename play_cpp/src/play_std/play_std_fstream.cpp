#include "play_std_fstream.hpp"

#include <filesystem>
#include <fstream>
#include <string>

#include "r2tm/r2tm_ostream.hpp"
#include "r2tm/r2tm_inspector.hpp"

namespace play_std_fstream
{
	r2tm::TitleFunctionT OpenAndClose::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "fstream : Open And Close";
		};
	}
	r2tm::DoFunctionT OpenAndClose::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUT_SUBJECT( "없는 파일 열기" );

				LF();

				DECL_MAIN( std::ifstream ifs( "", std::ios::in ) );

				LF();

				EXPECT_FALSE( ifs );
				EXPECT_TRUE( ifs.fail() );

				LF();

				PROC_MAIN( ifs.close() );
			}

			LS();

			DECL_SUB( std::filesystem::path p = std::filesystem::current_path() );
			PROC_SUB( p.append( "resources" ).append( "play_std_fstream_0.txt" ) );
			OUT_VALUE( p );

			LS();

			{
				EXPECT_TRUE( std::filesystem::exists( p ) );

				LF();

				OUT_SUBJECT( "있는 파일 열기" );

				LF();

				DECL_MAIN( std::ifstream ifs( p, std::ios::in ) );

				LF();

				EXPECT_TRUE( ifs );
				EXPECT_FALSE( ifs.fail() );

				LF();

				PROC_MAIN( ifs.close() );

				LF();

				OUT_NOTE( "파일을 닫아도 유효성 검사를 통과 한다." );

				LF();

				EXPECT_TRUE( ifs );
				EXPECT_FALSE( ifs.fail() );
			}

			LS();

			{
				OUT_SUBJECT( "open 함수로 열기" );

				LF();

				DECL_MAIN( std::ifstream ifs );
				PROC_MAIN( ifs.open( p ) );

				LF();

				EXPECT_TRUE( ifs );
				EXPECT_FALSE( ifs.fail() );

				LF();

				PROC_MAIN( ifs.close() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT GetCharacter::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "fstream : GetCharacter";
		};
	}
	r2tm::DoFunctionT GetCharacter::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECL_SUB( std::filesystem::path p = std::filesystem::current_path() );
			PROC_SUB( p.append( "resources" ).append( "play_std_fstream_0.txt" ) );
			OUT_VALUE( p );
			EXPECT_TRUE( std::filesystem::exists( p ) );

			LS();

			DECL_MAIN( std::ifstream ifs( p, std::ios::in ) );
			EXPECT_FALSE( ifs.fail() );

			LS();

			{
				OUT_SUBJECT( "std::ifstream::get" );

				LF();

				OUT_VALUE( static_cast<char>( ifs.get() ) );
				OUT_VALUE( static_cast<char>( ifs.get() ) );
				OUT_VALUE( static_cast<char>( ifs.get() ) );
			}

			LS();

			{
				OUT_SUBJECT( "while" );

				LF();

				PROC_MAIN( while( !ifs.eof() ) { std::cout << static_cast<char>( ifs.get() ); } );

				LF();
			}

			LS();

			PROC_MAIN( ifs.close() );

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT GetLine1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "fstream : GetLine 1";
		};
	}
	r2tm::DoFunctionT GetLine1::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECL_SUB( std::filesystem::path p = std::filesystem::current_path() );
			PROC_SUB( p.append( "resources" ).append( "play_std_fstream_0.txt" ) );
			OUT_VALUE( p );
			EXPECT_TRUE( std::filesystem::exists( p ) );

			LS();

			DECL_MAIN( std::string buffer );
			DECL_MAIN( std::ifstream ifs( p, std::ios::in ) );

			LS();

			{
				OUT_SUBJECT( "std::getline" );

				LF();

				PROC_MAIN( std::getline( ifs, buffer ); std::cout << buffer << r2tm::linefeed );
				PROC_MAIN( std::getline( ifs, buffer ); std::cout << buffer << r2tm::linefeed );
				PROC_MAIN( std::getline( ifs, buffer ); std::cout << buffer << r2tm::linefeed );
			}

			LS();

			{
				OUT_SUBJECT( "while" );

				LF();

				PROC_MAIN( while( ifs.good() ) { std::getline( ifs, buffer ); std::cout << buffer << r2tm::linefeed; } );
			}

			LS();

			{
				PROC_MAIN( ifs.close() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT GetLine2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "fstream : GetLine 2";
		};
	}
	r2tm::DoFunctionT GetLine2::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECL_SUB( std::filesystem::path p = std::filesystem::current_path() );
			PROC_SUB( p.append( "resources" ).append( "play_std_fstream_0.txt" ) );
			OUT_VALUE( p );
			EXPECT_TRUE( std::filesystem::exists( p ) );

			LS();

			DECL_MAIN( char buffer[100] );
			DECL_MAIN( std::ifstream ifs( p, std::ios::in ) );

			LS();

			{
				OUT_SUBJECT( "std::ifstream::getline" );

				LF();

				PROC_MAIN( ifs.getline( buffer, 100 ); std::cout << buffer << r2tm::linefeed );
				PROC_MAIN( ifs.getline( buffer, 100 ); std::cout << buffer << r2tm::linefeed );
				PROC_MAIN( ifs.getline( buffer, 100 ); std::cout << buffer << r2tm::linefeed );
			}

			LS();

			{
				OUT_SUBJECT( "while" );

				LF();

				PROC_MAIN( while( ifs ) { ifs.getline( buffer, 100 ); std::cout << buffer << r2tm::linefeed; } );
			}

			LS();

			{
				PROC_MAIN( ifs.close() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT GetBlank2Blank::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "fstream : Get Blank 2 Blank";
		};
	}
	r2tm::DoFunctionT GetBlank2Blank::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECL_SUB( std::filesystem::path p = std::filesystem::current_path() );
			PROC_SUB( p.append( "resources" ).append( "play_std_fstream_0.txt" ) );
			OUT_VALUE( p );
			EXPECT_TRUE( std::filesystem::exists( p ) );

			LS();

			DECL_MAIN( std::string buffer );
			DECL_MAIN( std::ifstream ifs( p, std::ios::in ) );

			LS();

			{
				OUT_SUBJECT( "Operator >>" );

				LF();

				PROC_MAIN( ifs >> buffer; std::cout << buffer << r2tm::linefeed );
				PROC_MAIN( ifs >> buffer; std::cout << buffer << r2tm::linefeed );
				PROC_MAIN( ifs >> buffer; std::cout << buffer << r2tm::linefeed );
			}

			LS();

			{
				OUT_SUBJECT( "while" );

				LF();

				PROC_MAIN( while( ifs >> buffer ) { std::cout << buffer << r2tm::linefeed; } );
			}

			LS();

			{
				PROC_MAIN( ifs.close() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT FileGenerate::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "fstream : File Generate";
		};
	}
	r2tm::DoFunctionT FileGenerate::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECL_SUB( std::filesystem::path p = std::filesystem::current_path() );
			PROC_SUB( p.append( "resources" ).append( "temp.txt" ) );
			OUT_VALUE( p );

			LS();

			{
				OUT_SUBJECT( "파일 없음 확인" );

				LF();

				EXPECT_FALSE( std::filesystem::exists( p ) );
			}

			LS();

			DECL_MAIN( std::ofstream fs );
			EXPECT_FALSE( fs.fail() );

			LS();

			{
				OUT_SUBJECT( "파일 생성" );

				LF();

				PROC_MAIN( fs.open( p, std::ios::out ) );
				EXPECT_TRUE( fs.is_open() );


				LF();

				PROC_MAIN( fs.close() );
			}

			LS();

			{
				OUT_SUBJECT( "파일 있음 확인" );

				LF();

				EXPECT_TRUE( std::filesystem::exists( p ) );
			}

			LS();

			{
				OUT_SUBJECT( "파일 삭제" );

				LF();

				PROC_MAIN( std::filesystem::remove_all( p ) );
			}

			LS();

			{
				OUT_SUBJECT( "파일 없음 확인" );

				LF();

				EXPECT_FALSE( std::filesystem::exists( p ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}