#include "std_random_test.h"

#include <fstream>
#include <iomanip>
#include <random>
#include <string>
#include <map>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"
#include "utility/r2utility_FileUtil.h"


namespace std_random_test
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "STD Random : Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( std::random_device rd );
				DECLARATION_MAIN( std::default_random_engine random_engine( rd() ) );
				DECLARATION_MAIN( std::uniform_int_distribution<int> dist( 0, 2 ) );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( dist( random_engine ) );

				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "Loop : 10" << r2cm::linefeed;
				for( int i = 0; 10 > i; ++i )
				{
					std::cout << r2cm::tab2 << "- " << dist( random_engine ) << r2cm::linefeed;
				}

				std::cout << r2cm::linefeed;

				OUTPUT_NOTE( "Contained Min and Max" );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( std::random_device rd );
				DECLARATION_MAIN( std::default_random_engine random_engine( rd() ) );
				DECLARATION_MAIN( std::uniform_real_distribution<float> dist( 0.f, 0.1f ) );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( dist( random_engine ) );

				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "Loop : 10" << r2cm::linefeed;
				for( int i = 0; 10 > i; ++i )
				{
					std::cout << r2cm::tab2 << "- " << dist( random_engine ) << r2cm::linefeed;
				}

				std::cout << r2cm::linefeed;

				OUTPUT_NOTE( "Contained Min" );;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}



namespace
{
	const char* GetFilePath()
	{
		static std::string temp_string = r2utility::MakeOutPutPath( "random_test_Status.dat" );
		return temp_string.c_str();
	}
}
namespace std_random_test
{
	r2cm::iItem::TitleFunctionT StatusSaveAndLoad::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "STD Random : Status Save And Load";
		};
	}
	r2cm::iItem::DoFunctionT StatusSaveAndLoad::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( std::random_device rd );
			DECLARATION_MAIN( std::mt19937 random_engine( rd() ) );
			DECLARATION_MAIN( std::uniform_int_distribution<int> dist( 0, 999 ) );

			std::cout << r2cm::linefeed;
			std::cout << r2cm::tab << "+ Save : Current Random Status" << r2cm::linefeed2;

			{
				std::cout << "File Path : " << GetFilePath() << r2cm::linefeed;
				DECLARATION_MAIN( std::ofstream fs( GetFilePath() ) );
				PROCESS_MAIN( fs << random_engine );
			}

			std::cout << r2cm::split;

			for( int i = 0; 3 > i; ++i )
			{
				OUTPUT_VALUE( dist( random_engine ) );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Load x 1" << r2cm::linefeed2;

				DECLARATION_MAIN( std::ifstream ifs( GetFilePath() ) );
				DECLARATION_MAIN( std::mt19937 loaded_random_engine );
				PROCESS_MAIN( ifs >> loaded_random_engine );
				DECLARATION_MAIN( std::uniform_int_distribution<int> dist_2( 0, 999 ) );

				std::cout << r2cm::linefeed;

				for( int i = 0; 3 > i; ++i )
				{
					OUTPUT_VALUE( dist_2( loaded_random_engine ) );
				}
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Load x 2" << r2cm::linefeed2;

				DECLARATION_MAIN( std::ifstream ifs( GetFilePath() ) );
				DECLARATION_MAIN( std::mt19937 loaded_random_engine );
				PROCESS_MAIN( ifs >> loaded_random_engine );
				DECLARATION_MAIN( std::uniform_int_distribution<int> dist_2( 0, 999 ) );

				std::cout << r2cm::linefeed;

				for( int i = 0; 3 > i; ++i )
				{
					OUTPUT_VALUE( dist_2( loaded_random_engine ) );
				}
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}



namespace std_random_test
{
	r2cm::iItem::TitleFunctionT DiscreateDistribution::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "STD Random : Discreate Distribution";
		};
	}
	r2cm::iItem::DoFunctionT DiscreateDistribution::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( std::random_device rd );
			DECLARATION_MAIN( std::mt19937 random_engine( rd() ) );
			DECLARATION_MAIN( std::discrete_distribution<> dist( { 5, 10, 30, 50, 5 } ) );

			std::cout << r2cm::split;

			std::map<int, int> test_map;

			for( int i = 0; 3 > i; ++i )
			{
				test_map.clear();

				for( int sample_count = 0; 100 > sample_count; ++sample_count )
				{
					++test_map[dist( random_engine )];
				}

				for( const auto& t : test_map )
				{
					std::cout << r2cm::tab << "key : " << t.first << std::setw( 20 ) << "count : " << t.second << r2cm::linefeed;
				}

				std::cout << r2cm::split;
			}

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}