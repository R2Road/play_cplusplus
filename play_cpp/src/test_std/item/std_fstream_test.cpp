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
				std::cout << r2tm::tab << "+ 없는 파일." << r2tm::linefeed2;

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
			std::cout << "p : " << p << r2tm::linefeed;
			EXPECT_TRUE( std::filesystem::exists( p ) );

			LS();

			{
				std::cout << r2tm::tab << "+ 파일 열기 성공." << r2tm::linefeed2;

				DECLARATION_MAIN( std::ifstream ifs( p, std::ios::in ) );

				LF();

				EXPECT_TRUE( ifs );
				EXPECT_FALSE( ifs.fail() );

				LF();

				PROCESS_MAIN( ifs.close() );

				LF();

				std::cout << r2tm::tab << "+ 파일을 닫아도 유효성 검사를 통과 한다." << r2tm::linefeed2;
				EXPECT_TRUE( ifs );
				EXPECT_FALSE( ifs.fail() );
			}

			LS();

			{
				std::cout << r2tm::tab << "+ use std::ifstream::open" << r2tm::linefeed2;

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
			std::cout << "p : " << p << r2tm::linefeed;
			EXPECT_TRUE( std::filesystem::exists( p ) );

			LS();

			{
				std::cout << r2tm::tab << "+ std::ifstream::get" << r2tm::linefeed2;

				DECLARATION_MAIN( std::ifstream ifs( p, std::ios::in ) );
				EXPECT_FALSE( ifs.fail() );

				LF();

				PROCESS_MAIN( while( !ifs.eof() ) { std::cout << static_cast<char>( ifs.get() ); } );

				LF();

				PROCESS_MAIN( ifs.close() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT GetLine::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "fstream : GetLine";
		};
	}
	r2tm::DoFunctionT GetLine::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_SUB( std::filesystem::path p = std::filesystem::current_path() );
			PROCESS_SUB( p.append( "resources" ).append( "std_fstream_test_0.txt" ) );
			std::cout << "p : " << p << r2tm::linefeed;
			EXPECT_TRUE( std::filesystem::exists( p ) );

			LS();

			{
				DECLARATION_MAIN( std::string buffer );
				DECLARATION_MAIN( std::ifstream ifs( p, std::ios::in ) );

				LF();

				PROCESS_MAIN( while( ifs.good() ) { std::getline( ifs, buffer ); std::cout << buffer << r2tm::linefeed; } );

				LF();

				PROCESS_MAIN( ifs.close() );
			}

			LS();

			{
				DECLARATION_MAIN( char buffer[100] );
				DECLARATION_MAIN( std::ifstream ifs( p, std::ios::in ) );

				LF();

				PROCESS_MAIN( while( ifs ) { ifs.getline( buffer, 100 ); std::cout << buffer << r2tm::linefeed; } );

				LF();

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
			std::cout << "p : " << p << r2tm::linefeed;
			EXPECT_TRUE( std::filesystem::exists( p ) );

			LS();

			{
				DECLARATION_MAIN( std::string buffer );
				DECLARATION_MAIN( std::ifstream ifs( p, std::ios::in ) );

				LF();

				PROCESS_MAIN( while( ifs >> buffer ) { std::cout << buffer << r2tm::linefeed; } );

				LF();

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
			std::cout << "p : " << p << r2tm::linefeed;
			EXPECT_FALSE( std::filesystem::exists( p ) );

			LS();

			{
				DECLARATION_MAIN( std::ofstream ifs( p, std::ios::out ) );
				PROCESS_MAIN( ifs.close() );

				LF();

				EXPECT_TRUE( std::filesystem::exists( p ) );
			}

			LS();

			{
				PROCESS_MAIN( std::filesystem::remove_all( p ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}