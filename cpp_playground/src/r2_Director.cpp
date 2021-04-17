#include "pch.h"
#include "r2_Director.h"

#include <conio.h>
#include <utility>

#include "r2_eTestResult.h"

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
			case eTestResult::RunTest:
				std::cout << r2::linefeed;
				system( "pause" );

				system( "cls" );
				break;

			//case eTestResult::ChangeScene:
				//break;

			case eTestResult::Exit:
				return;
			}
		}
	}
}