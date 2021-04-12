#include "pch.h"
#include "random_test.h"

#include <filesystem>
#include <fstream>
#include <random>
#include <string>

#include "r2_eTestResult.h"


namespace random_test
{
	const r2::iNode::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Random : Basic";
		};
	}
	const r2::iNode::DoFunc Basic::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "== Basic ==" << std::endl << std::endl;

			{
				std::cout << "\t+ Range Check" << std::endl;
				std::cout << "\t\t" << "std::uniform_int_distribution<int> dist( 0, 2 );" << std::endl << std::endl;

				std::random_device rd;
				std::default_random_engine random_engine( rd() );
				std::uniform_int_distribution<int> dist( 0, 2 );

				std::cout << "\t\t" << "Loop : 10" << std::endl;

				for( int i = 0; 10 > i; ++i )
				{
					std::cout << "\t\t\t - " << dist( random_engine ) << std::endl;
				}

				std::cout << std::endl;

				std::cout << "\t\t" << "Contained Min and Max;" << std::endl;
			}

			std::cout << std::endl << std::endl;

			{
				std::cout << "\t+ Range Check" << std::endl;
				std::cout << "\t\t" << "std::uniform_real_distribution<float> dist( 0, 2 );" << std::endl << std::endl;

				std::random_device rd;
				std::default_random_engine random_engine( rd() );
				std::uniform_real_distribution<float> dist( 0.f, 0.1f );

				std::cout << "\t\t" << "Loop : 10" << std::endl;

				for( int i = 0; 10 > i; ++i )
				{
					std::cout << "\t\t\t - " << dist( random_engine ) << std::endl;
				}

				std::cout << std::endl;

				std::cout << "\t\t" << "Contained Min;" << std::endl;
			}

			return r2::eTestResult::RunTest;
		};
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
	const r2::iNode::TitleFunc StatusSaveAndLoad::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Random : Status Save And Load";
		};
	}
	const r2::iNode::DoFunc StatusSaveAndLoad::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			Status_Save();

			std::cout << std::endl << std::endl;

			Status_Load();

			return r2::eTestResult::RunTest;
		};
	}
}