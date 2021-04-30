#include "pch.h"
#include "filesystem_test.h"

#include <filesystem>

#include "r2_eTestResult.h"

namespace
{
	void TestDirectoryIterator()
	{
		std::cout << "# Directory Iterator #" << r2::linefeed;

		std::cout << "\t" << "+ Directory : " << r2::linefeed;
		std::cout << "\t\t" << std::filesystem::current_path() << r2::linefeed;
		std::cout << r2::linefeed;

		std::cout << "\t" << "+ View" << r2::linefeed;
		std::filesystem::directory_iterator itr( std::filesystem::current_path() );
		for( auto i : itr )
		{
			std::cout << "\t\t" << i.path() << r2::linefeed;
			std::cout << "\t\t\t" << ( std::filesystem::is_regular_file( i.path() ) ? "file" : "directory" ) << r2::linefeed;
		}

		std::cout << r2::linefeed;
	}

	void TestRecursiveDirectoryIterator()
	{
		std::cout << "# Recursive Directory Iterator #" << r2::linefeed;

		std::filesystem::recursive_directory_iterator itr( std::filesystem::current_path() / "src" );
		for( auto i : itr )
		{
			std::cout << "\t" << i.path() << r2::linefeed;
		}

		std::cout << r2::linefeed;
	}

	void TestPathOperation()
	{
		std::cout << "# Path Operation #" << r2::linefeed;

		std::filesystem::path p = std::filesystem::current_path();
		std::cout << "\t" << "+ Directory : " << r2::linefeed;
		std::cout << "\t\t" << p << r2::linefeed;
		std::cout << r2::linefeed;



		std::cout << "\t" << "+ Append, Operator /" << r2::linefeed;

		p /= "test.txt";

		std::cout << "\t\t" << p << r2::linefeed;
		std::cout << r2::linefeed;



		std::cout << "\t" << "+ Remove File Name" << r2::linefeed;

		p.remove_filename();

		std::cout << "\t\t" << p << r2::linefeed;
		std::cout << r2::linefeed;
	}
}



namespace filesystem_test
{

	const r2::iTest::TitleFunc DirectoryPath::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "File System : Directory Path";
		};
	}
	const r2::iTest::DoFunc DirectoryPath::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# Current Directory #" << r2::linefeed;

			std::filesystem::path p = std::filesystem::current_path();

			std::cout << "\t" << p << r2::linefeed;
			std::cout << r2::linefeed;



			std::cout << "# Temp Directory #" << r2::linefeed;

			std::filesystem::path p2 = std::filesystem::temp_directory_path();

			std::cout << "\t" << p2 << r2::linefeed;
			std::cout << r2::linefeed;

			return r2::eTestResult::RunTest;
		};
	}
}



namespace filesystem_test
{

	const r2::iTest::TitleFunc CurrentDirectory::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "File System : Current Directory";
		};
	}
	const r2::iTest::DoFunc CurrentDirectory::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			TestDirectoryIterator();

			std::cout << r2::linefeed << r2::linefeed;

			TestRecursiveDirectoryIterator();

			std::cout << r2::linefeed << r2::linefeed;

			TestPathOperation();

			return r2::eTestResult::RunTest;
		};
	}
}