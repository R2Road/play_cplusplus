#include "random_test.h"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <random>
#include <string>


namespace random_test
{
	void Basic::Do()
	{
		std::cout << "== Basic ==" << std::endl << std::endl;

		std::random_device rd;
		std::default_random_engine random_engine( rd() );
		std::uniform_int_distribution<int> dist( 0, 2 );

		std::cout << "\t+ Make Random Engine" << std::endl;
		std::cout << "\t\t" << "std::uniform_int_distribution<int> dist( 0, 2 );" << std::endl << std::endl;

		std::cout << "\t\t" << "Loop : 10" << std::endl;

		for( int i = 0; 10 > i; ++i )
		{
			std::cout << "\t\t\t - " << dist( random_engine ) << std::endl;
		}

		std::cout << std::endl;

		std::cout << "\t\t" << "Contained Min and Max;" << std::endl;
	}
}



namespace
{
	const char* GetFilePath()
	{
		static std::string temp_string = ( std::filesystem::current_path() / "Debug" / "random_test_Status.dat" ).string();
		return temp_string.c_str();
	}

	void Status_Save()
	{
		std::cout << "== Status Save ==" << std::endl;
		std::cout << std::endl;

		std::random_device rd;
		std::mt19937 random_engine( rd() );
		std::uniform_int_distribution<int> dist( 0, 999 );

		std::cout << "\t+ Make Random Engine & Test Output" << std::endl;
		std::cout << "\t\t" << dist( random_engine ) << std::endl;
		std::cout << "\t\t" << dist( random_engine ) << std::endl;
		std::cout << "\t\t" << dist( random_engine ) << std::endl;
		std::cout << std::endl;

		//
		// status save
		//
		std::cout << "\t+ Save : Current Random Status" << std::endl;
		{
			std::ofstream fs( GetFilePath() );
			fs << random_engine;
		}

		std::cout << std::endl;
	}

	void Status_Load()
	{
		std::cout << "== Status Load ==" << std::endl;
		std::cout << std::endl;

		{
			std::cout << "\t+ Test Step 1" << std::endl;

			std::ifstream ifs( GetFilePath() );
			if( ifs.fail() )
			{
				std::cout << "\t\tFailed : Need - random_test::Status_Save" << std::endl;
				return;
			}

			std::mt19937 random_engine;
			ifs >> random_engine;
			std::uniform_int_distribution<int> dist( 0, 999 );

			std::cout << "\t\t" << dist( random_engine ) << std::endl;
			std::cout << "\t\t" << dist( random_engine ) << std::endl;
			std::cout << "\t\t" << dist( random_engine ) << std::endl;
			std::cout << std::endl;
		}

		{
			std::cout << "\t+ Test Step 2" << std::endl;

			std::ifstream ifs( GetFilePath() );
			std::mt19937 random_engine;
			ifs >> random_engine;
			std::uniform_int_distribution<int> dist( 0, 999 );

			std::cout << "\t\t" << dist( random_engine ) << std::endl;
			std::cout << "\t\t" << dist( random_engine ) << std::endl;
			std::cout << "\t\t" << dist( random_engine ) << std::endl;
			std::cout << std::endl;
		}

		std::cout << std::endl;
	}
}
namespace random_test
{
	void StatusSaveAndLoad::Do()
	{
		Status_Save();

		std::cout << std::endl << std::endl;

		Status_Load();
	}
}