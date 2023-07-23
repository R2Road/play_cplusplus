#include "std_fstream_test.h"

#include <filesystem>
#include <fstream>
#include <string>

#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_Inspector.h"

namespace std_fstream_test
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
				OUTPUT_SUBJECT( "없는 파일 열기" );

				LF();

				DECLARATION_MAIN( std::ifstream ifs( "", std::ios::in ) );

				LF();

				EXPECT_FALSE( ifs );
				EXPECT_TRUE( ifs.fail() );

				LF();

				PROCESS_MAIN( ifs.close() );
			}

			LS();

			DECLARATION_SUB( std::filesystem::path p = std::filesystem::current_path() );
			PROCESS_SUB( p.append( "resources" ).append( "std_fstream_test_0.txt" ) );
			OUTPUT_VALUE( p );

			LS();

			{
				EXPECT_TRUE( std::filesystem::exists( p ) );

				LF();

				OUTPUT_SUBJECT( "있는 파일 열기" );

				LF();

				DECLARATION_MAIN( std::ifstream ifs( p, std::ios::in ) );

				LF();

				EXPECT_TRUE( ifs );
				EXPECT_FALSE( ifs.fail() );

				LF();

				PROCESS_MAIN( ifs.close() );

				LF();

				OUTPUT_NOTE( "파일을 닫아도 유효성 검사를 통과 한다." );

				LF();

				EXPECT_TRUE( ifs );
				EXPECT_FALSE( ifs.fail() );
			}

			LS();

			{
				OUTPUT_SUBJECT( "open 함수로 열기" );

				LF();

				DECLARATION_MAIN( std::ifstream ifs );
				PROCESS_MAIN( ifs.open( p ) );

				LF();

				EXPECT_TRUE( ifs );
				EXPECT_FALSE( ifs.fail() );

				LF();

				PROCESS_MAIN( ifs.close() );
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

			DECLARATION_SUB( std::filesystem::path p = std::filesystem::current_path() );
			PROCESS_SUB( p.append( "resources" ).append( "std_fstream_test_0.txt" ) );
			OUTPUT_VALUE( p );
			EXPECT_TRUE( std::filesystem::exists( p ) );

			LS();

			DECLARATION_MAIN( std::ifstream ifs( p, std::ios::in ) );
			EXPECT_FALSE( ifs.fail() );

			LS();

			{
				OUTPUT_SUBJECT( "std::ifstream::get" );

				LF();

				OUTPUT_VALUE( static_cast<char>( ifs.get() ) );
				OUTPUT_VALUE( static_cast<char>( ifs.get() ) );
				OUTPUT_VALUE( static_cast<char>( ifs.get() ) );
			}

			LS();

			{
				OUTPUT_SUBJECT( "while" );

				LF();

				PROCESS_MAIN( while( !ifs.eof() ) { std::cout << static_cast<char>( ifs.get() ); } );

				LF();
			}

			LS();

			PROCESS_MAIN( ifs.close() );

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

			DECLARATION_SUB( std::filesystem::path p = std::filesystem::current_path() );
			PROCESS_SUB( p.append( "resources" ).append( "std_fstream_test_0.txt" ) );
			OUTPUT_VALUE( p );
			EXPECT_TRUE( std::filesystem::exists( p ) );

			LS();

			DECLARATION_MAIN( std::string buffer );
			DECLARATION_MAIN( std::ifstream ifs( p, std::ios::in ) );

			LS();

			{
				OUTPUT_SUBJECT( "std::getline" );

				LF();

				PROCESS_MAIN( std::getline( ifs, buffer ); std::cout << buffer << r2tm::linefeed );
				PROCESS_MAIN( std::getline( ifs, buffer ); std::cout << buffer << r2tm::linefeed );
				PROCESS_MAIN( std::getline( ifs, buffer ); std::cout << buffer << r2tm::linefeed );
			}

			LS();

			{
				OUTPUT_SUBJECT( "while" );

				LF();

				PROCESS_MAIN( while( ifs.good() ) { std::getline( ifs, buffer ); std::cout << buffer << r2tm::linefeed; } );
			}

			LS();

			{
				PROCESS_MAIN( ifs.close() );
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

			DECLARATION_SUB( std::filesystem::path p = std::filesystem::current_path() );
			PROCESS_SUB( p.append( "resources" ).append( "std_fstream_test_0.txt" ) );
			OUTPUT_VALUE( p );
			EXPECT_TRUE( std::filesystem::exists( p ) );

			LS();

			DECLARATION_MAIN( char buffer[100] );
			DECLARATION_MAIN( std::ifstream ifs( p, std::ios::in ) );

			LS();

			{
				OUTPUT_SUBJECT( "std::ifstream::getline" );

				LF();

				PROCESS_MAIN( ifs.getline( buffer, 100 ); std::cout << buffer << r2tm::linefeed );
				PROCESS_MAIN( ifs.getline( buffer, 100 ); std::cout << buffer << r2tm::linefeed );
				PROCESS_MAIN( ifs.getline( buffer, 100 ); std::cout << buffer << r2tm::linefeed );
			}

			LS();

			{
				OUTPUT_SUBJECT( "while" );

				LF();

				PROCESS_MAIN( while( ifs ) { ifs.getline( buffer, 100 ); std::cout << buffer << r2tm::linefeed; } );
			}

			LS();

			{
				PROCESS_MAIN( ifs.close() );
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

			DECLARATION_SUB( std::filesystem::path p = std::filesystem::current_path() );
			PROCESS_SUB( p.append( "resources" ).append( "std_fstream_test_0.txt" ) );
			OUTPUT_VALUE( p );
			EXPECT_TRUE( std::filesystem::exists( p ) );

			LS();

			DECLARATION_MAIN( std::string buffer );
			DECLARATION_MAIN( std::ifstream ifs( p, std::ios::in ) );

			LS();

			{
				OUTPUT_SUBJECT( "Operator >>" );

				LF();

				PROCESS_MAIN( ifs >> buffer; std::cout << buffer << r2tm::linefeed );
				PROCESS_MAIN( ifs >> buffer; std::cout << buffer << r2tm::linefeed );
				PROCESS_MAIN( ifs >> buffer; std::cout << buffer << r2tm::linefeed );
			}

			LS();

			{
				OUTPUT_SUBJECT( "while" );

				LF();

				PROCESS_MAIN( while( ifs >> buffer ) { std::cout << buffer << r2tm::linefeed; } );
			}

			LS();

			{
				PROCESS_MAIN( ifs.close() );
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

			DECLARATION_SUB( std::filesystem::path p = std::filesystem::current_path() );
			PROCESS_SUB( p.append( "resources" ).append( "temp.txt" ) );
			OUTPUT_VALUE( p );

			LS();

			{
				OUTPUT_SUBJECT( "파일 없음 확인" );

				LF();

				EXPECT_FALSE( std::filesystem::exists( p ) );
			}

			LS();

			DECLARATION_MAIN( std::ofstream fs );
			EXPECT_FALSE( fs.fail() );

			LS();

			{
				OUTPUT_SUBJECT( "파일 생성" );

				LF();

				PROCESS_MAIN( fs.open( p, std::ios::out ) );
				EXPECT_TRUE( fs.is_open() );


				LF();

				PROCESS_MAIN( fs.close() );
			}

			LS();

			{
				OUTPUT_SUBJECT( "파일 있음 확인" );

				LF();

				EXPECT_TRUE( std::filesystem::exists( p ) );
			}

			LS();

			{
				OUTPUT_SUBJECT( "파일 삭제" );

				LF();

				PROCESS_MAIN( std::filesystem::remove_all( p ) );
			}

			LS();

			{
				OUTPUT_SUBJECT( "파일 없음 확인" );

				LF();

				EXPECT_FALSE( std::filesystem::exists( p ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}