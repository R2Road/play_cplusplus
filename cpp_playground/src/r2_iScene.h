#pragma once

#include <cctype>
#include <functional>
#include <iostream>
#include <memory>
#include <tuple>
#include <vector>

#include "r2_iNode.h"

#include "r2_eTestResult.h"

namespace r2
{
	class Director;

	using SceneUp = std::unique_ptr<class iScene>;
	class iScene
	{
	public:
		iScene( Director& director ) : mDirector( director ), mTests() {}
		virtual ~iScene() {}

		virtual void ShowTitle() const = 0;

		void ShowMenu() const
		{
			std::cout << "+ Menu" << std::endl;

			for( const auto t : mTests )
			{
				std::cout
					<< static_cast<char>( std::toupper( std::get<0>( t ) ) )
					<< " : "
					<< std::get<1>( t )()
					<< std::endl;
			}

			std::cout << std::endl << "Select Menu";
		}

		eTestResult Do( const int key_code )
		{
			for( const auto t : mTests )
			{
				if( key_code == std::get<0>( t ) )
				{
					return std::get<2>( t )();
				}
			}

			return eTestResult::RunTest;
		}

		void AddChild( const char key_code, const iNode& node )
		{
			mTests.push_back( std::make_tuple( key_code, node.GetTitleFunction(), node.GetDoFunction() ) );
		}
		void AddChild( const char key_code, const std::function<const char*()> func_title, const std::function<const r2::eTestResult()> func_test )
		{
			mTests.push_back( std::make_tuple( key_code, func_title, func_test ) );
		}

	protected:
		Director& mDirector;

		std::vector<std::tuple<char, std::function<const char*()>, std::function<const r2::eTestResult()>>> mTests;
	};
}