#include "std_fstream_test.h"

#include <filesystem>
#include <fstream>
#include <string>

#include "r2cm/r2cm_constant.h"
#include "r2cm/r2cm_Inspector.h"

namespace std_fstream_test
{
	r2cm::iItem::TitleFuncT OpenAndClose::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "fstream : Open And Close";
		};
	}
	r2cm::iItem::DoFuncT OpenAndClose::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ 없는 파일." << r2cm::linefeed2;

				DECLARATION_MAIN( std::ifstream ifs( "", std::ios::in ) );

				std::cout << r2cm::linefeed;

				EXPECT_FALSE( ifs );
				EXPECT_TRUE( ifs.fail() );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( ifs.close() );
			}

			std::cout << r2cm::split;

			DECLARATION_SUB( std::filesystem::path p = std::filesystem::current_path() );
			PROCESS_SUB( p.append( "resources" ).append( "std_fstream_test_0.txt" ) );
			std::cout << "p : " << p << r2cm::linefeed;
			EXPECT_TRUE( std::filesystem::exists( p ) );

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ 파일 열기 성공." << r2cm::linefeed2;

				DECLARATION_MAIN( std::ifstream ifs( p, std::ios::in ) );

				std::cout << r2cm::linefeed;

				EXPECT_TRUE( ifs );
				EXPECT_FALSE( ifs.fail() );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( ifs.close() );

				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "+ 파일을 닫아도 유효성 검사를 통과 한다." << r2cm::linefeed2;
				EXPECT_TRUE( ifs );
				EXPECT_FALSE( ifs.fail() );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ use std::ifstream::open" << r2cm::linefeed2;

				DECLARATION_MAIN( std::ifstream ifs );
				PROCESS_MAIN( ifs.open( p ) );

				std::cout << r2cm::linefeed;

				EXPECT_TRUE( ifs );
				EXPECT_FALSE( ifs.fail() );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( ifs.close() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT GetCharacter::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "fstream : GetCharacter";
		};
	}
	r2cm::iItem::DoFuncT GetCharacter::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			DECLARATION_SUB( std::filesystem::path p = std::filesystem::current_path() );
			PROCESS_SUB( p.append( "resources" ).append( "std_fstream_test_0.txt" ) );
			std::cout << "p : " << p << r2cm::linefeed;
			EXPECT_TRUE( std::filesystem::exists( p ) );

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ std::ifstream::get" << r2cm::linefeed2;

				DECLARATION_MAIN( std::ifstream ifs( p, std::ios::in ) );
				EXPECT_FALSE( ifs.fail() );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( while( !ifs.eof() ) { std::cout << static_cast<char>( ifs.get() ); } );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( ifs.close() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT GetLine::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "fstream : GetLine";
		};
	}
	r2cm::iItem::DoFuncT GetLine::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			DECLARATION_SUB( std::filesystem::path p = std::filesystem::current_path() );
			PROCESS_SUB( p.append( "resources" ).append( "std_fstream_test_0.txt" ) );
			std::cout << "p : " << p << r2cm::linefeed;
			EXPECT_TRUE( std::filesystem::exists( p ) );

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( std::string buffer );
				DECLARATION_MAIN( std::ifstream ifs( p, std::ios::in ) );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( while( ifs.good() ) { std::getline( ifs, buffer ); std::cout << buffer << r2cm::linefeed; } );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( ifs.close() );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( char buffer[100] );
				DECLARATION_MAIN( std::ifstream ifs( p, std::ios::in ) );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( while( ifs ) { ifs.getline( buffer, 100 ); std::cout << buffer << r2cm::linefeed; } );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( ifs.close() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT GetBlank2Blank::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "fstream : Get Blank 2 Blank";
		};
	}
	r2cm::iItem::DoFuncT GetBlank2Blank::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()()  << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			DECLARATION_SUB( std::filesystem::path p = std::filesystem::current_path() );
			PROCESS_SUB( p.append( "resources" ).append( "std_fstream_test_0.txt" ) );
			std::cout << "p : " << p << r2cm::linefeed;
			EXPECT_TRUE( std::filesystem::exists( p ) );

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( std::string buffer );
				DECLARATION_MAIN( std::ifstream ifs( p, std::ios::in ) );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( while( ifs >> buffer ) { std::cout << buffer << r2cm::linefeed; } );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( ifs.close() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}