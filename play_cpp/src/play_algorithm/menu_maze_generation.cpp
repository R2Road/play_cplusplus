#include "menu_maze_generation.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_algorithm_maze.hpp"
#include "play_maze_generation_kruskals.hpp"

#include "menu_algorithm.hpp"

r2tm::TitleFunctionT Menu_MazeGeneration::GetTitleFunction() const
{
	return []()->const char*
	{
		return "MazeGeneration";
	};
}
r2tm::DescriptionFunctionT Menu_MazeGeneration::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_MazeGeneration::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_algorithm_maze::Basic() );
		mp->AddItem( '2', play_algorithm_maze::Test() );


		mp->AddLineFeed();


		mp->AddItem( 'q', play_maze_generation_kruskals::ViewTest() );
		mp->AddItem( 'w', play_maze_generation_kruskals::Basic() );


		mp->AddSplit();


		mp->AddMenu( 27, Menu_Algorithm() );
	};
}