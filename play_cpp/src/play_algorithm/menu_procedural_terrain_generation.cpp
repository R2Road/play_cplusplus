#include "menu_procedural_terrain_generation.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_procedural_terrain_generation_1.hpp"
#include "play_procedural_terrain_generation_2.hpp"
#include "play_procedural_terrain_generation_3.hpp"

#include "menu_algorithm.hpp"

r2tm::TitleFunctionT Menu_ProceduralTerrainGeneration::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Procedural Terrain Generation ";
	};
}
r2tm::DescriptionFunctionT Menu_ProceduralTerrainGeneration::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_ProceduralTerrainGeneration::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_procedural_terrain_generation_1::Basic() );
		mp->AddItem( '2', play_procedural_terrain_generation_1::Test_1() );


		mp->AddLineFeed();


		mp->AddItem( '3', play_procedural_terrain_generation_2::Bone() );
		mp->AddItem( '4', play_procedural_terrain_generation_3::Weights() );


		mp->AddSplit();


		mp->AddMenu( 27, Menu_Algorithm() );
	};
}