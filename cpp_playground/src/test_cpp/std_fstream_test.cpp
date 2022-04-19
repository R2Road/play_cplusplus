#include "pch.h"
#include "std_fstream_test.h"

#include <filesystem>
#include <fstream>
#include <string>

#include "base/r2cm_eTestEndAction.h"
#include "r2/r2_Inspector.h"

namespace std_fstream_test
{
	r2cm::iItem::TitleFuncT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "fstream : Basic";
		};
	}
	r2cm::iItem::DoFuncT Basic::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()()  << " #" << r2::linefeed;

			std::cout << r2::split;

			DECLARATION_MAIN( std::filesystem::path p = std::filesystem::current_path() );
			PROCESS_MAIN( p.append( "resources" ) );
			PROCESS_MAIN( p.append( "std_fstream_test_0.txt" ) );
			std::cout << "p : " << p << r2::linefeed2;

			EXPECT_TRUE( std::filesystem::exists( p ) );

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ while( ifs >> buffer )		std::cout << buffer << r2::linefeed;" << r2::linefeed2;

				std::string buffer;
				std::ifstream ifs( p, std::ios::in );

				while( ifs >> buffer )
				{
					std::cout << buffer << r2::linefeed;
				}

				ifs.close();
			}

			std::cout << r2::split;

			{

				std::cout << r2::tab << "+ while( ifs.good() )		std::getline( ifs, buffer );	std::cout << buffer << r2::linefeed;" << r2::linefeed2;

				std::string buffer;
				std::ifstream ifs( p, std::ios::in );

				while( ifs.good() )
				{
					std::getline( ifs, buffer );
					std::cout << buffer << r2::linefeed;
				}

				ifs.close();
			}

			std::cout << r2::split;

			{

				std::cout << r2::tab << "+ while( ifs )		ifs.getline( buffer, 100 );		std::cout << buffer << r2::linefeed;" << r2::linefeed2;

				char buffer[100];
				std::ifstream ifs( p, std::ios::in );

				while( ifs )
				{
					ifs.getline( buffer, 100 );
					std::cout << buffer << r2::linefeed;
				}

				ifs.close();
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}
}