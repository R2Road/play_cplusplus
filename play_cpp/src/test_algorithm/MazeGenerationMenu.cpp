#include "MazeGenerationMenu.h"

#include "r2tm/r2tm_MenuProcessor.h"

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
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', algorithm_maze_test::Basic() );
		mp->AddItem( '2', algorithm_maze_test::Test() );


		mp->AddLineFeed();


		mp->AddItem( 'q', maze_generation_kruskals_test::ViewTest() );
		mp->AddItem( 'w', maze_generation_kruskals_test::Basic() );


		mp->AddSplit();


		mp->AddMenu( 27, AlgorithmMenu() );
	};
}