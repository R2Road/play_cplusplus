#include "random_test_StatusSaveAndLoad.h"

#include <fstream>
#include <iostream>
#include <random>
#include <cassert>

namespace random_test
{
	void Status_Save()
	{
		std::cout << "== Status Save ==" << std::endl;
		std::cout << std::endl;

		std::random_device rd;
		std::mt19937 random_engine( rd() );
		std::uniform_int_distribution<int> dist( 0, 999 );

		std::cout << dist( random_engine ) << std::endl;
		std::cout << dist( random_engine ) << std::endl;
		std::cout << dist( random_engine ) << std::endl;

		//
		// status save
		//
		{
			std::ofstream fs( "random_test_Status.dat" );
			fs << random_engine;
		}

		std::cout << std::endl;
	}

	void Status_Load()
	{
		std::cout << "== Status Load ==" << std::endl;
		std::cout << std::endl;

		{
			std::cout << "+ Test Step 1" << std::endl;

			std::ifstream ifs( "random_test_Status.dat" );
			if( ifs.fail() )
			{
				std::cout << "    Failed : Need - random_test::Status_Save" << std::endl;
				return;
			}

			std::mt19937 random_engine;
			ifs >> random_engine;
			std::uniform_int_distribution<int> dist( 0, 999 );

			std::cout << dist( random_engine ) << std::endl;
			std::cout << dist( random_engine ) << std::endl;
			std::cout << dist( random_engine ) << std::endl;
			std::cout << std::endl;
		}

		{
			std::cout << "+ Test Step 2" << std::endl;

			std::ifstream ifs( "random_test_Status.dat" );
			std::mt19937 random_engine;
			ifs >> random_engine;
			std::uniform_int_distribution<int> dist( 0, 999 );

			std::cout << dist( random_engine ) << std::endl;
			std::cout << dist( random_engine ) << std::endl;
			std::cout << dist( random_engine ) << std::endl;
			std::cout << std::endl;
		}

		std::cout << std::endl;
	}

	void StatusSaveAndLoad::Do()
	{
		Status_Save();
		Status_Load();
	}
}