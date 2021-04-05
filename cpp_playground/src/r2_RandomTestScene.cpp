#include "r2_RandomTestScene.h"

#include <iostream>
#include <sstream>

#include "r2_Director.h"
#include "r2_RootScene.h"
#include "random_test.h"

namespace
{
	std::string MakeMenuString()
	{
		std::stringstream ss;
		ss << "+ Menu" << std::endl;
		ss << "1 : " << random_test::Basic::GetInstance().GetTitleFunction()() << std::endl;
		ss << "2 : " << random_test::StatusSaveAndLoad::GetInstance().GetTitleFunction()() << std::endl;

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

	eTestResult RandomTestScene::Do( const int key_code )
	{
		switch( key_code )
		{
		case '1':
			return random_test::Basic::GetInstance().GetDoFunction()();
		case '2':
			return random_test::StatusSaveAndLoad::GetInstance().GetDoFunction()();

		case 27: // ESC
			mDirector.Setup( r2::RootScene::Create( mDirector ) );
			return eTestResult::ChangeScene;
		}

		return eTestResult::RunTest;
	}
}