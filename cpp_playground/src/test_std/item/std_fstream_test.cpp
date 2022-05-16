#include "std_fstream_test.h"

#include <filesystem>
#include <fstream>
#include <string>

#include "r2cm/r2cm_constant.h"
#include "r2cm/r2cm_Inspector.h"

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
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()()  << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			DECLARATION_MAIN( std::filesystem::path p = std::filesystem::current_path() );
			PROCESS_MAIN( p.append( "resources" ) );
			PROCESS_MAIN( p.append( "std_fstream_test_0.txt" ) );
			std::cout << "p : " << p << r2cm::linefeed2;

			EXPECT_TRUE( std::filesystem::exists( p ) );

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ while( ifs >> buffer )		std::cout << buffer << r2cm::linefeed;" << r2cm::linefeed2;

				std::string buffer;
				std::ifstream ifs( p, std::ios::in );

				while( ifs >> buffer )
				{
					std::cout << buffer << r2cm::linefeed;
				}

				ifs.close();
			}

			std::cout << r2cm::split;

			{

				std::cout << r2cm::tab << "+ while( ifs.good() )		std::getline( ifs, buffer );	std::cout << buffer << r2cm::linefeed;" << r2cm::linefeed2;

				std::string buffer;
				std::ifstream ifs( p, std::ios::in );

				while( ifs.good() )
				{
					std::getline( ifs, buffer );
					std::cout << buffer << r2cm::linefeed;
				}

				ifs.close();
			}

			std::cout << r2cm::split;

			{

				std::cout << r2cm::tab << "+ while( ifs )		ifs.getline( buffer, 100 );		std::cout << buffer << r2cm::linefeed;" << r2cm::linefeed2;

				char buffer[100];
				std::ifstream ifs( p, std::ios::in );

				while( ifs )
				{
					ifs.getline( buffer, 100 );
					std::cout << buffer << r2cm::linefeed;
				}

				ifs.close();
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}