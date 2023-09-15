#include "std_random_test.h"

#include <fstream>
#include <iomanip>
#include <random>
#include <string>
#include <map>

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"
#include "utility/r2utility_FileUtil.h"


namespace std_random_test
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "STD Random : Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				DECLARATION_MAIN( std::random_device rd );
				DECLARATION_MAIN( std::default_random_engine random_engine( rd() ) );
				DECLARATION_MAIN( std::uniform_int_distribution<int> dist( 0, 2 ) );

				LF();

				OUTPUT_VALUE( dist( random_engine ) );

				LF();

				std::cout << r2tm::tab << "Loop : 10" << r2tm::linefeed;
				for( int i = 0; 10 > i; ++i )
				{
					std::cout << r2tm::tab2 << "- " << dist( random_engine ) << r2tm::linefeed;
				}

				LF();

				OUTPUT_NOTE( "Contained Min and Max" );
			}

			LS();

			{
				DECLARATION_MAIN( std::random_device rd );
				DECLARATION_MAIN( std::default_random_engine random_engine( rd() ) );
				DECLARATION_MAIN( std::uniform_real_distribution<float> dist( 0.f, 0.1f ) );

				LF();

				OUTPUT_VALUE( dist( random_engine ) );

				LF();

				std::cout << r2tm::tab << "Loop : 10" << r2tm::linefeed;
				for( int i = 0; 10 > i; ++i )
				{
					std::cout << r2tm::tab2 << "- " << dist( random_engine ) << r2tm::linefeed;
				}

				LF();

				OUTPUT_NOTE( "Contained Min" );;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}



namespace
{
	const char* GetFilePath()
	{
		static std::string temp_string = play_cpp_utility::MakeOutPutPath( "random_test_Status.dat" );
		return temp_string.c_str();
	}
}
namespace std_random_test
{
	r2tm::TitleFunctionT StatusSaveAndLoad::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "STD Random : Status Save And Load";
		};
	}
	r2tm::DoFunctionT StatusSaveAndLoad::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( std::random_device rd );
			DECLARATION_MAIN( std::mt19937 random_engine( rd() ) );
			DECLARATION_MAIN( std::uniform_int_distribution<int> dist( 0, 999 ) );

			LF();
			std::cout << r2tm::tab << "+ Save : Current Random Status" << r2tm::linefeed2;

			{
				std::cout << "File Path : " << GetFilePath() << r2tm::linefeed;
				DECLARATION_MAIN( std::ofstream fs( GetFilePath() ) );
				PROCESS_MAIN( fs << random_engine );
			}

			LS();

			for( int i = 0; 3 > i; ++i )
			{
				OUTPUT_VALUE( dist( random_engine ) );
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Load x 1" << r2tm::linefeed2;

				DECLARATION_MAIN( std::ifstream ifs( GetFilePath() ) );
				DECLARATION_MAIN( std::mt19937 loaded_random_engine );
				PROCESS_MAIN( ifs >> loaded_random_engine );
				DECLARATION_MAIN( std::uniform_int_distribution<int> dist_2( 0, 999 ) );

				LF();

				for( int i = 0; 3 > i; ++i )
				{
					OUTPUT_VALUE( dist_2( loaded_random_engine ) );
				}
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Load x 2" << r2tm::linefeed2;

				DECLARATION_MAIN( std::ifstream ifs( GetFilePath() ) );
				DECLARATION_MAIN( std::mt19937 loaded_random_engine );
				PROCESS_MAIN( ifs >> loaded_random_engine );
				DECLARATION_MAIN( std::uniform_int_distribution<int> dist_2( 0, 999 ) );

				LF();

				for( int i = 0; 3 > i; ++i )
				{
					OUTPUT_VALUE( dist_2( loaded_random_engine ) );
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}



namespace std_random_test
{
	r2tm::TitleFunctionT DiscreateDistribution::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "STD Random : Discreate Distribution";
		};
	}
	r2tm::DoFunctionT DiscreateDistribution::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( std::random_device rd );
			DECLARATION_MAIN( std::mt19937 random_engine( rd() ) );
			DECLARATION_MAIN( std::discrete_distribution<> dist( { 5, 10, 30, 50, 5 } ) );

			LS();

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
					std::cout << r2tm::tab << "key : " << t.first << std::setw( 20 ) << "count : " << t.second << r2tm::linefeed;
				}

				LS();
			}

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}