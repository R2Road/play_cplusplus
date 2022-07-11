#include "ProceduralTerrainGenerationMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "test_algorithm/item/procedural_terrain_generation_1_test.h"
#include "test_algorithm/item/procedural_terrain_generation_2_test.h"
#include "test_algorithm/item/procedural_terrain_generation_3_test.h"

#include "AlgorithmMenu.h"

r2cm::MenuUp ProceduralTerrainGenerationMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', procedural_terrain_generation_1_test::Basic::GetInstance() );
		ret->AddItem( '2', procedural_terrain_generation_1_test::Test_1::GetInstance() );


		ret->AddLineFeed();


		ret->AddItem( '3', procedural_terrain_generation_2_test::Bone::GetInstance() );
		ret->AddItem( '4', procedural_terrain_generation_3_test::Weights::GetInstance() );


		ret->AddSplit();


		ret->AddItem(
			27
			, []()->const char* { return "Return To Root"; }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( AlgorithmMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
	}

	return ret;
}