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
		std::cout << "# " << mTitleString << " #" << std::endl << std::endl;
	}

	void Scene::ShowMenu() const
	{
		std::cout << "+ Menu" << std::endl;

		for( const auto t : mTests )
		{
			std::cout
				<< static_cast<char>( std::toupper( std::get<0>( t ) ) )
				<< " : "
				<< std::get<1>( t )( )
				<< std::endl;
		}

		std::cout << std::endl << "Select Menu";
	}

	eTestResult Scene::Do( const int key_code )
	{
		for( const auto t : mTests )
		{
			if( key_code == std::get<0>( t ) )
			{
				return std::get<2>( t )( );
			}
		}

		return eTestResult::RunTest;
	}

	void Scene::AddChild( const char key_code, const iNode& node )
	{
		mTests.push_back( std::make_tuple( key_code, node.GetTitleFunction(), node.GetDoFunction() ) );
	}
	void Scene::AddChild( const char key_code, const std::function<const char*( )> func_title, const std::function<const r2::eTestResult()> func_test )
	{
		mTests.push_back( std::make_tuple( key_code, func_title, func_test ) );
	}
}