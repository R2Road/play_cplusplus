#include "MazeGenerationMenu.h"

#include "r2tm/r2tm_Director.h"

#include "test_algorithm/item/algorithm_maze_test.h"
#include "test_algorithm/item/maze_generation_kruskals_test.h"

#include "AlgorithmMenu.h"

r2tm::TitleFunctionT MazeGenerationMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "MazeGeneration";
	};
}
r2tm::DescriptionFunctionT MazeGenerationMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT MazeGenerationMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', algorithm_maze_test::Basic() );


		ret->AddLineFeed();


		ret->AddItem( 'q', maze_generation_kruskals_test::ViewTest() );
		ret->AddItem( 'w', maze_generation_kruskals_test::Basic() );


		ret->AddSplit();


		ret->AddMenu( 27, AlgorithmMenu() );
	};
}