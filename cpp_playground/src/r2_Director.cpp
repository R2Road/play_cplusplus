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
			mScene->ShowMenu();

			input = _getch();
			system( "cls" );

			if( mScene->Do( input ) )
			{
				std::cout << std::endl << "Press Any Key" << std::endl;
				_getch();
				system( "cls" );
			}
			else
			{
				break;
			}
		}
	}
}