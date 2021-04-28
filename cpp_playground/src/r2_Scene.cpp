#include "pch.h"
#include "r2_Scene.h"

#include <cctype> // std::toupper

#include "r2_eTestResult.h"
#include "r2_iNode.h"

namespace r2
{
	Scene::Scene( Director& director, const char* title_string ) :
		mDirector( director )
		, mTitleString( title_string )
		, mTests()
	{}

	void Scene::ShowTitle() const
	{
		std::cout << "# " << mTitleString << " #" << r2::linefeed << r2::linefeed;
	}

	void Scene::ShowMenu() const
	{
		std::cout << "+ Menu" << r2::linefeed;

		for( const auto t : mTests )
		{
			//
			// Key
			//
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

		std::cout << r2::linefeed << "Select Menu";
	}

	eTestResult Scene::Do( const int key_code )
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

	void Scene::AddChild( const char key_code, const iNode& node )
	{
		mTests.emplace_back( key_code, node.GetTitleFunction(), node.GetDoFunction() );
	}
	void Scene::AddChild( const char key_code, const std::function<const char*( )> func_title, const std::function<const r2::eTestResult()> func_test )
	{
		mTests.emplace_back( key_code, func_title, func_test );
	}
	void Scene::AddSplit()
	{
		static const std::function<const char*()> func_title = []()->const char* { return ""; };
		static const std::function<const r2::eTestResult()> func_test = []()->const r2::eTestResult { return r2::eTestResult::RunTest; };

		mTests.push_back( { 64, func_title, func_test } );
	}
}