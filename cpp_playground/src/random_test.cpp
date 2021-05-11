#include "pch.h"
#include "random_test.h"

#include <filesystem>
#include <fstream>
#include <random>
#include <string>

#include "r2_eTestResult.h"


namespace random_test
{
	r2::iTest::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Basic";
		};
	}
	r2::iTest::DoFunc Basic::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << "\t+ Range Check" << r2::linefeed;
				std::cout << "\t\t" << "std::uniform_int_distribution<int> dist( 0, 2 );" << r2::linefeed << r2::linefeed;

				std::random_device rd;
				std::default_random_engine random_engine( rd() );
				std::uniform_int_distribution<int> dist( 0, 2 );

				std::cout << "\t\t" << "Loop : 10" << r2::linefeed;

				for( int i = 0; 10 > i; ++i )
				{
					std::cout << "\t\t\t - " << dist( random_engine ) << r2::linefeed;
				}

				std::cout << r2::linefeed;

				std::cout << "\t\t" << "Contained Min and Max;" << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << "\t+ Range Check" << r2::linefeed;
				std::cout << "\t\t" << "std::uniform_real_distribution<float> dist( 0, 2 );" << r2::linefeed << r2::linefeed;

				std::random_device rd;
				std::default_random_engine random_engine( rd() );
				std::uniform_real_distribution<float> dist( 0.f, 0.1f );

				std::cout << "\t\t" << "Loop : 10" << r2::linefeed;

				for( int i = 0; 10 > i; ++i )
				{
					std::cout << "\t\t\t - " << dist( random_engine ) << r2::linefeed;
				}

				std::cout << r2::linefeed;

				std::cout << "\t\t" << "Contained Min;" << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}



namespace
{
	const char* GetFilePath()
	{
		static std::string temp_string =
#if defined( _WIN64 )
			( std::filesystem::current_path() / "x64" / "Debug" / "random_test_Status.dat" ).string();
#else
			( std::filesystem::current_path() / "Debug" / "random_test_Status.dat" ).string();
#endif
		return temp_string.c_str();
	}

	void Status_Save()
	{
		std::cout << "# Status Save #" << r2::linefeed;
		
		std::cout << r2::split;

		std::random_device rd;
		std::mt19937 random_engine( rd() );
		std::uniform_int_distribution<int> dist( 0, 999 );

		std::cout << "\t+ Make Random Engine & Test Output" << r2::linefeed;
		std::cout << "\t\t" << dist( random_engine ) << r2::linefeed;
		std::cout << "\t\t" << dist( random_engine ) << r2::linefeed;
		std::cout << "\t\t" << dist( random_engine ) << r2::linefeed;
		std::cout << r2::linefeed;

		//
		// status save
		//
		std::cout << "\t+ Save : Current Random Status" << r2::linefeed;
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
			std::cout << "\t+ Test Step 1" << r2::linefeed;

			std::ifstream ifs( GetFilePath() );
			if( ifs.fail() )
			{
				std::cout << "\t\tFailed : Need - random_test::Status_Save" << r2::linefeed;
				return;
			}

			std::mt19937 random_engine;
			ifs >> random_engine;
			std::uniform_int_distribution<int> dist( 0, 999 );

			std::cout << "\t\t" << dist( random_engine ) << r2::linefeed;
			std::cout << "\t\t" << dist( random_engine ) << r2::linefeed;
			std::cout << "\t\t" << dist( random_engine ) << r2::linefeed;
		}

		std::cout << r2::split;

		{
			std::cout << "\t+ Test Step 2" << r2::linefeed;

			std::ifstream ifs( GetFilePath() );
			std::mt19937 random_engine;
			ifs >> random_engine;
			std::uniform_int_distribution<int> dist( 0, 999 );

			std::cout << "\t\t" << dist( random_engine ) << r2::linefeed;
			std::cout << "\t\t" << dist( random_engine ) << r2::linefeed;
			std::cout << "\t\t" << dist( random_engine ) << r2::linefeed;
		}

		std::cout << r2::split;
	}
}
namespace random_test
{
	r2::iTest::TitleFunc StatusSaveAndLoad::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Status Save And Load";
		};
	}
	r2::iTest::DoFunc StatusSaveAndLoad::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			Status_Save();

			std::cout << r2::linefeed << r2::linefeed;

			Status_Load();

			return r2::eTestResult::RunTest;
		};
	}
}