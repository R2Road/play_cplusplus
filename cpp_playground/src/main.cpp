#include <conio.h>
#include <iostream>
#include <sstream>
#include <Windows.h>

#include "filesystem_test.h"
#include "random_test.h"
#include "shared_pointer_test.h"


std::string MakeMenuString()
{
	std::stringstream ss;
	ss << "+ Menu" << std::endl;
	ss << "1 : " << filesystem_test::CurrentDirectory::GetTitle() << std::endl;
	ss << "2 : " << random_test::StatusSaveAndLoad::GetTitle() << std::endl;
	ss << "3 : " << shared_pointer_test::SharedPtr::GetTitle() << std::endl;

	ss << std::endl << "Press Number" << std::endl;

	return std::string( ss.str() );
}

void ShowMenu()
{
	static std::string menu_string( std::move( MakeMenuString() ) );
	std::cout << menu_string;
}

int main()
{
	system( "mode con lines=50 cols=120" );

	int input = 0;
	while( true )
	{
		ShowMenu();

		input = _getch();
		system( "cls" );

		switch( input )
		{
		case '1':
			filesystem_test::CurrentDirectory::Do();
			break;
		case '2':
			random_test::StatusSaveAndLoad::Do();
			break;
		case '3':
			shared_pointer_test::SharedPtr::Do();
			break;

		case 27: // ESC
			return 0;
		}

		std::cout << std::endl << "Press Any Key" << std::endl;
		_getch();
		system( "cls" );
	}

	return 0;
}
