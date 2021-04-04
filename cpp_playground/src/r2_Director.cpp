#include "r2_Director.h"

#include <conio.h>
#include <iostream>
#include <utility>

namespace r2
{
	Director::Director() : mScene()
	{}

	void Director::Setup( SceneUp scene )
	{
		mScene = std::move( scene );
	}

	void Director::Update()
	{
		int input = 0;
		while( true )
		{
			mScene->ShowTitle();
			mScene->ShowMenu();

			input = _getch();
			system( "cls" );

			switch( mScene->Do( input ) )
			{
			case iScene::eResult::RunTest:
				std::cout << std::endl << "Press Any Key" << std::endl;
				_getch();
				system( "cls" );
				break;

			//case iScene::eResult::ChangeScene:
				//break;

			case iScene::eResult::Exit:
				return;
			}
		}
	}
}