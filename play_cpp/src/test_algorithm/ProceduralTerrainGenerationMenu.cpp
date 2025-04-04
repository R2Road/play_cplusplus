#include "ProceduralTerrainGenerationMenu.h"

#include "r2tm/r2tm_Director.h"

#include "test_algorithm/item/procedural_terrain_generation_1_test.h"
#include "test_algorithm/item/procedural_terrain_generation_2_test.h"
#include "test_algorithm/item/procedural_terrain_generation_3_test.h"

#include "AlgorithmMenu.h"

r2tm::TitleFunctionT ProceduralTerrainGenerationMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Procedural Terrain Generation ";
	};
}
r2tm::DescriptionFunctionT ProceduralTerrainGenerationMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT ProceduralTerrainGenerationMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', procedural_terrain_generation_1_test::Basic() );
		ret->AddItem( '2', procedural_terrain_generation_1_test::Test_1() );


		ret->AddLineFeed();


		ret->AddItem( '3', procedural_terrain_generation_2_test::Bone() );
		ret->AddItem( '4', procedural_terrain_generation_3_test::Weights() );


		ret->AddSplit();


		ret->AddMenu( 27, AlgorithmMenu() );
	};
}