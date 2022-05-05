#include "pch.h"
#include "std_random_test.h"

#include <filesystem>
#include <fstream>
#include <random>
#include <string>
#include <map>

#include "r2cm/r2cm_eTestEndAction.h"
#include "utility/r2utility_FileUtil.h"


namespace std_random_test
{
	r2cm::iItem::TitleFuncT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "STD Random : Basic";
		};
	}
	r2cm::iItem::DoFuncT Basic::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "std::uniform_int_distribution<int> dist( 0, 2 );" << r2::linefeed2;

				std::random_device rd;
				std::default_random_engine random_engine( rd() );
				std::uniform_int_distribution<int> dist( 0, 2 );

				std::cout << r2::tab2 << "Loop : 10" << r2::linefeed;

				for( int i = 0; 10 > i; ++i )
				{
					std::cout << r2::tab3 << "- " << dist( random_engine ) << r2::linefeed;
				}

				std::cout << r2::linefeed;

				std::cout << r2::tab << "Message : Contained Min and Max" << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "std::uniform_real_distribution<float> dist( 0, 2 );" << r2::linefeed2;

				std::random_device rd;
				std::default_random_engine random_engine( rd() );
				std::uniform_real_distribution<float> dist( 0.f, 0.1f );

				std::cout << r2::tab2 << "Loop : 10" << r2::linefeed;

				for( int i = 0; 10 > i; ++i )
				{
					std::cout << r2::tab3 << "- " << dist( random_engine ) << r2::linefeed;
				}

				std::cout << r2::linefeed;

				std::cout << r2::tab << "Message : Contained Min" << r2::linefeed;
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
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

	void Status_Save()
	{
		std::cout << "# Status Save #" << r2::linefeed2;

		std::cout << "File Path : " << GetFilePath() << r2::linefeed;
		
		std::cout << r2::split;

		std::random_device rd;
		std::mt19937 random_engine( rd() );
		std::uniform_int_distribution<int> dist( 0, 999 );

		std::cout << r2::tab << "+ Make Random Engine & Test Output" << r2::linefeed;
		std::cout << r2::tab2 << dist( random_engine ) << r2::linefeed;
		std::cout << r2::tab2 << dist( random_engine ) << r2::linefeed;
		std::cout << r2::tab2 << dist( random_engine ) << r2::linefeed;
		std::cout << r2::linefeed;

		//
		// status save
		//
		std::cout << r2::tab << "+ Save : Current Random Status" << r2::linefeed;
		{
			std::ofstream fs( GetFilePath() );
			fs << random_engine;
		}

		std::cout << r2::split;
	}

	void Status_Load()
	{
		std::cout << "# Status Load #" << r2::linefeed;

		std::cout << r2::split;

		{
			std::cout << r2::tab << "+ Test Step 1" << r2::linefeed;

			std::ifstream ifs( GetFilePath() );
			if( ifs.fail() )
			{
				std::cout << r2::tab2 << "Failed : Need - random_test::Status_Save" << r2::linefeed;
				return;
			}

			std::mt19937 random_engine;
			ifs >> random_engine;
			std::uniform_int_distribution<int> dist( 0, 999 );

			std::cout << r2::tab2 << dist( random_engine ) << r2::linefeed;
			std::cout << r2::tab2 << dist( random_engine ) << r2::linefeed;
			std::cout << r2::tab2 << dist( random_engine ) << r2::linefeed;
		}

		std::cout << r2::split;

		{
			std::cout << r2::tab << "+ Test Step 2" << r2::linefeed;

			std::ifstream ifs( GetFilePath() );
			std::mt19937 random_engine;
			ifs >> random_engine;
			std::uniform_int_distribution<int> dist( 0, 999 );

			std::cout << r2::tab2 << dist( random_engine ) << r2::linefeed;
			std::cout << r2::tab2 << dist( random_engine ) << r2::linefeed;
			std::cout << r2::tab2 << dist( random_engine ) << r2::linefeed;
		}

		std::cout << r2::split;
	}
}
namespace std_random_test
{
	r2cm::iItem::TitleFuncT StatusSaveAndLoad::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "STD Random : Status Save And Load";
		};
	}
	r2cm::iItem::DoFuncT StatusSaveAndLoad::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			Status_Save();

			std::cout << r2::linefeed2;

			Status_Load();

			return r2cm::eTestEndAction::Pause;
		};
	}
}



namespace std_random_test
{
	r2cm::iItem::TitleFuncT DiscreateDistribution::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "STD Random : Discreate Distribution";
		};
	}
	r2cm::iItem::DoFuncT DiscreateDistribution::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			std::random_device rd;
			std::mt19937 gen( rd() );
			std::discrete_distribution<> d( { 5, 10, 30, 50, 5 } );

			std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
			std::cout << r2::tab2 << "std::discrete_distribution<> d( { 5, 10, 30, 50, 5 } );" << r2::linefeed;

			std::cout << r2::split;

			std::map<int, int> test_map;

			for( int i = 0; 3 > i; ++i )
			{
				test_map.clear();

				for( int sample_count = 0; 100 > sample_count; ++sample_count )
				{
					++test_map[d( gen )];
				}

				for( const auto& t : test_map )
				{
					std::cout << r2::tab << "key : " << t.first << std::setw( 20 ) << "count : " << t.second << r2::linefeed;
				}

				std::cout << r2::split;
			}

			return r2cm::eTestEndAction::Pause;
		};
	}
}