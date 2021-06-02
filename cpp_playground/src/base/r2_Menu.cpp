#include "pch.h"
#include "r2_Menu.h"

#include <cctype> // std::toupper

#include "r2_eTestResult.h"
#include "r2_iTest.h"

namespace r2
{
	Menu::Menu( Director& director, const char* title_string, const char* description_string ) :
		mDirector( director )
		, mTitleString( title_string )
		, mDescriptionString( description_string )
		, mTests()
	{}

	void Menu::ShowTitle() const
	{
		std::cout << "# " << mTitleString << " #" << r2::linefeed;
		std::cout << r2::split;
	}
	void Menu::ShowDescription() const
	{
		if( !mDescriptionString.empty() )
		{
			std::cout << "+ Message" << r2::linefeed << r2::linefeed;
			
			std::cout << mDescriptionString << r2::linefeed;

			std::cout << r2::split;
		}
	}

	void Menu::ShowMenu() const
	{
		std::cout << "+ Menu" << r2::linefeed << r2::linefeed;

		for( const auto t : mTests )
		{
			//
			// Key
			//
			if( 42 == t.KeyCode ) // *
			{
				std::cout << r2::split;
				continue;
			}
			if( 64 == t.KeyCode ) // @
			{
				std::cout << r2::linefeed;
				continue;
			}

			std::cout << "[";

			if( 27 == t.KeyCode ) // ESC
			{
				std::cout << "ESC";
			}
			else if( 32 == t.KeyCode ) // SPACE_BAR
			{
				std::cout << "SPACE";
			}
			else
			{
				std::cout << static_cast<char>( std::toupper( t.KeyCode ) );
			}

			std::cout << "] : ";
			
			//
			// Name
			//
			std::cout << t.NameFunction() << r2::linefeed;
		}

		std::cout << r2::split << "Select Menu";
	}

	eTestResult Menu::Do( const int key_code )
	{
		for( const auto t : mTests )
		{
			if( key_code == t.KeyCode )
			{
				return t.TestFunction();
			}
		}

		return eTestResult::RunTest;
	}

	void Menu::AddChild( const char key_code, iTest& test_obj )
	{
		mTests.emplace_back( key_code, test_obj.GetTitleFunction(), test_obj.GetDoFunction() );
	}
	void Menu::AddChild( const char key_code, const std::function<const char*( )> func_title, const std::function<const r2::eTestResult()> func_test )
	{
		mTests.emplace_back( key_code, func_title, func_test );
	}
	void Menu::AddLineFeed()
	{
		static const std::function<const char*()> func_title = []()->const char* { return ""; };
		static const std::function<const r2::eTestResult()> func_test = []()->const r2::eTestResult { return r2::eTestResult::RunTest; };

		mTests.push_back( { 64, func_title, func_test } );
	}
	void Menu::AddSplit()
	{
		static const std::function<const char*( )> func_title = []()->const char* { return ""; };
		static const std::function<const r2::eTestResult()> func_test = []()->const r2::eTestResult { return r2::eTestResult::RunTest; };

		mTests.push_back( { 42, func_title, func_test } );
	}
}