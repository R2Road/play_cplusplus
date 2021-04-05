#include "r2_RandomTestScene.h"

#include <iostream>

#include "r2_Director.h"
#include "r2_RootScene.h"
#include "random_test.h"

namespace r2
{
	RandomTestScene::RandomTestScene( Director& director ) : iScene( director )
	{
		AddChild( '1', random_test::Basic::GetInstance() );
		AddChild( '2', random_test::StatusSaveAndLoad::GetInstance() );

		AddChild(
			27
			, []()->const char* { return "\nESC : Return To Root"; }
			, [this]()->const eTestResult
			{
				mDirector.Setup( r2::RootScene::Create( mDirector ) );
				return eTestResult::ChangeScene;
			}
		);
	}

	SceneUp RandomTestScene::Create( Director& director )
	{
		return SceneUp( new ( std::nothrow ) MyT( director ) );
	}

	void RandomTestScene::ShowTitle() const
	{
		std::cout << "# Random #" << std::endl << std::endl;
	}
}