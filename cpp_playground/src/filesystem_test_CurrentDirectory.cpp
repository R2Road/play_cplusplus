#include "filesystem_test_CurrentDirectory.h"

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
}

namespace filesystem_test
{
	void CurrentDirectory::Do()
	{
		TestCurrentDirectory();

		std::cout << std::endl << std::endl;

		TestTempDirectory();
	}
}