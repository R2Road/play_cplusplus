#include "MazeGenerationMenu.h"

#include "r2cm/r2cm_Director.h"

#include "test_algorithm/item/algorithm_maze_test.h"
#include "test_algorithm/item/maze_generation_kruskals_test.h"

#include "AlgorithmMenu.h"

r2cm::MenuUp MazeGenerationMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', algorithm_maze_test::Basic() );


		ret->AddLineFeed();


		ret->AddItem( 'q', maze_generation_kruskals_test::ViewTest() );
		ret->AddItem( 'w', maze_generation_kruskals_test::Basic() );


		ret->AddSplit();


		ret->AddMenu<AlgorithmMenu>( 27 );
	}

	return ret;
}