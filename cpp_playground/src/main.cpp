#include <conio.h>
#include <iostream>
#include <sstream>
#include <Windows.h>

#include "filesystem_test.h"
#include "random_test.h"
#include "shared_pointer_test.h"
#include "variadic_template_test.h"
#include "template_meta_programming_test.h"


std::string MakeMenuString()
{
	std::stringstream ss;
	ss << "+ Menu" << std::endl;
	ss << "1 : " << filesystem_test::CurrentDirectory::GetTitle() << std::endl;
	ss << "2 : " << random_test::StatusSaveAndLoad::GetTitle() << std::endl;
	ss << "3 : " << shared_pointer_test::SharedPtr::GetTitle() << std::endl;
	ss << "4 : " << variadic_template_test::PrintValues::GetTitle() << std::endl;
	ss << "5 : " << variadic_template_test::SumValues::GetTitle() << std::endl;
	ss << "6 : " << variadic_template_test::SubtractValues::GetTitle() << std::endl;
	ss << "7 : " << template_meta_programming_test::CalculateFactorial::GetTitle() << std::endl;
	ss << "8 : " << template_meta_programming_test::Integer2String::GetTitle() << std::endl;

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
	SetConsoleTitle( TEXT( "cpp_playground" ) );
	system( "mode con lines=60 cols=120" );

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
		case '4':
			variadic_template_test::PrintValues::Do();
			break;
		case '5':
			variadic_template_test::SumValues::Do();
			break;
		case '6':
			variadic_template_test::SubtractValues::Do();
			break;
		case '7':
			template_meta_programming_test::CalculateFactorial::Do();
			break;
		case '8':
			template_meta_programming_test::Integer2String::Do();
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
