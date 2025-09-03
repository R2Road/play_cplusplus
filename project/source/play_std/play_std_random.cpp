#include "play_std_random.hpp"

#include <fstream>
#include <iomanip>
#include <random>
#include <string>
#include <map>

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"
#include "utility/play_cpp_utility_path_builder.hpp"


namespace play_std_random
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
				DECL_MAIN( std::random_device rd );
				DECL_MAIN( std::default_random_engine random_engine( rd() ) );
				DECL_MAIN( std::uniform_int_distribution<int> dist( 0, 2 ) );

				LF();

				OUT_VALUE( dist( random_engine ) );

				LF();

				std::cout << r2tm::tab << "Loop : 10" << r2tm::linefeed;
				for( int i = 0; 10 > i; ++i )
				{
					std::cout << r2tm::tab2 << "- " << dist( random_engine ) << r2tm::linefeed;
				}

				LF();

				OUT_NOTE( "Contained Min and Max" );
			}

			LS();

			{
				DECL_MAIN( std::random_device rd );
				DECL_MAIN( std::default_random_engine random_engine( rd() ) );
				DECL_MAIN( std::uniform_real_distribution<float> dist( 0.f, 0.1f ) );

				LF();

				OUT_VALUE( dist( random_engine ) );

				LF();

				std::cout << r2tm::tab << "Loop : 10" << r2tm::linefeed;
				for( int i = 0; 10 > i; ++i )
				{
					std::cout << r2tm::tab2 << "- " << dist( random_engine ) << r2tm::linefeed;
				}

				LF();

				OUT_NOTE( "Contained Min" );;
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
		static std::string temp_string = play_cpp_utility::BuildOutPutPath( "random_test_Status.dat" );
		return temp_string.c_str();
	}
}
namespace play_std_random
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

			DECL_MAIN( std::random_device rd );
			DECL_MAIN( std::mt19937 random_engine( rd() ) );
			DECL_MAIN( std::uniform_int_distribution<int> dist( 0, 999 ) );

			LF();
			std::cout << r2tm::tab << "+ Save : Current Random Status" << r2tm::linefeed2;

			{
				std::cout << "File Path : " << GetFilePath() << r2tm::linefeed;
				DECL_MAIN( std::ofstream fs( GetFilePath() ) );
				PROC_MAIN( fs << random_engine );
			}

			LS();

			for( int i = 0; 3 > i; ++i )
			{
				OUT_VALUE( dist( random_engine ) );
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Load x 1" << r2tm::linefeed2;

				DECL_MAIN( std::ifstream ifs( GetFilePath() ) );
				DECL_MAIN( std::mt19937 loaded_random_engine );
				PROC_MAIN( ifs >> loaded_random_engine );
				DECL_MAIN( std::uniform_int_distribution<int> dist_2( 0, 999 ) );

				LF();

				for( int i = 0; 3 > i; ++i )
				{
					OUT_VALUE( dist_2( loaded_random_engine ) );
				}
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Load x 2" << r2tm::linefeed2;

				DECL_MAIN( std::ifstream ifs( GetFilePath() ) );
				DECL_MAIN( std::mt19937 loaded_random_engine );
				PROC_MAIN( ifs >> loaded_random_engine );
				DECL_MAIN( std::uniform_int_distribution<int> dist_2( 0, 999 ) );

				LF();

				for( int i = 0; 3 > i; ++i )
				{
					OUT_VALUE( dist_2( loaded_random_engine ) );
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}



namespace play_std_random
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

			DECL_MAIN( std::random_device rd );
			DECL_MAIN( std::mt19937 random_engine( rd() ) );
			DECL_MAIN( std::discrete_distribution<> dist( { 5, 10, 30, 50, 5 } ) );

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