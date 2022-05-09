#include "pch.h"
#include "r2_RandomMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_constant.h"
#include "RootMenu.h"

#include "test_cpp/item/c_random_test.h"
#include "test_cpp/item/std_random_test.h"

namespace r2
{
	r2cm::MenuUp RandomMenu::Create( r2cm::Director& director )
	{
		r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, RandomMenu::GetTitle() ) );

		{
			ret->AddItem( '1', c_random_test::Rand::GetInstance() );


			ret->AddLineFeed();


			ret->AddItem( 'q', std_random_test::Basic::GetInstance() );
			ret->AddItem( 'w', std_random_test::StatusSaveAndLoad::GetInstance() );
			ret->AddItem( 'e', std_random_test::DiscreateDistribution::GetInstance() );


			ret->AddSplit();


			ret->AddItem(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->r2cm::eItemLeaveAction
				{
					director.Setup( RootMenu::Create( director ) );
					return r2cm::eItemLeaveAction::None;
				}
			);
		}

		return ret;
	}
}