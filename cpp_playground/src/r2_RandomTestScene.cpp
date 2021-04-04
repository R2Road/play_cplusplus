#include "r2_RandomTestScene.h"

#include <iostream>
#include <sstream>

#include "r2_Director.h"
#include "r2_Scene.h"
#include "random_test.h"

namespace
{
	std::string MakeMenuString()
	{
		std::stringstream ss;
		ss << "+ Menu" << std::endl;
		ss << "1 : " << random_test::Basic::GetTitle() << std::endl;
		ss << "2 : " << random_test::StatusSaveAndLoad::GetTitle() << std::endl;

		ss << std::endl << "Press Number" << std::endl;

		return std::string( ss.str() );
	}
}

namespace r2
{
	RandomTestScene::RandomTestScene( Director& director ) : iScene( director ) {}

	SceneUp RandomTestScene::Create( Director& director )
	{
		return SceneUp( new ( std::nothrow ) MyT( director ) );
	}

	void RandomTestScene::ShowTitle() const
	{
		std::cout << "# Random #" << std::endl << std::endl;
	}
	void RandomTestScene::ShowMenu() const
	{
		static std::string menu_string( std::move( MakeMenuString() ) );
		std::cout << menu_string;
	}

	iScene::eResult RandomTestScene::Do( const int key_code )
	{
		switch( key_code )
		{
		case '1':
			random_test::Basic::Do();
			break;
		case '2':
			random_test::StatusSaveAndLoad::Do();
			break;

		case 27: // ESC
			mDirector.Setup( r2::Scene::Create( mDirector ) );
			return iScene::eResult::ChangeScene;
		}

		return iScene::eResult::RunTest;
	}
}