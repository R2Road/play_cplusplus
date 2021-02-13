#include "filesystem_test.h"

#include <filesystem>
#include <iostream>

namespace
{
	void TestCurrentDirectory()
	{
		std::cout << "== Current Directory ==" << std::endl;

		std::filesystem::path cwd = std::filesystem::current_path();

		std::cout << "\t" << cwd << std::endl;
		std::cout << std::endl;



		std::cout << "== Append, Operator / ==" << std::endl;

		cwd /= "test.txt";

		std::cout << "\t" << cwd << std::endl;
		std::cout << std::endl;



		std::cout << "== Remove File Name ==" << std::endl;

		cwd.remove_filename();

		std::cout << "\t" << cwd << std::endl;
		std::cout << std::endl;
	}

	void TestTempDirectory()
	{
		std::cout << "== Temp Directory ==" << std::endl;

		std::filesystem::path cwd = std::filesystem::temp_directory_path();

		std::cout << "\t" << cwd << std::endl;
		std::cout << std::endl;
	}

	void TestDirectoryIterator()
	{
		std::cout << "== Directory Iterator ==" << std::endl;

		std::cout << "\t" << "+ Directory : " << std::endl;
		std::cout << "\t\t" << std::filesystem::current_path() << std::endl;
		std::cout << std::endl;

		std::cout << "\t" << "+ View" << std::endl;
		std::filesystem::directory_iterator itr( std::filesystem::current_path() );
		for( auto i : itr )
		{
			std::cout << "\t\t" << i.path() << std::endl;
			std::cout << "\t\t\t" << ( std::filesystem::is_regular_file( i.path() ) ? "file" : "directory" ) << std::endl;
		}

		std::cout << std::endl;
	}

	void TestRecursiveDirectoryIterator()
	{
		std::cout << "== Recursive Directory Iterator ==" << std::endl;

		std::filesystem::recursive_directory_iterator itr( std::filesystem::current_path() / "src" );
		for( auto i : itr )
		{
			std::cout << "\t" << i.path() << std::endl;
		}

		std::cout << std::endl;
	}
}

namespace filesystem_test
{
	void CurrentDirectory::Do()
	{
		TestCurrentDirectory();

		std::cout << std::endl << std::endl;

		TestTempDirectory();

		std::cout << std::endl << std::endl;

		TestDirectoryIterator();

		std::cout << std::endl << std::endl;

		TestRecursiveDirectoryIterator();
	}
}