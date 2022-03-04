#include "pch.h"
#include "r2_AlignMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestEndAction.h"
#include "r2_RootMenu.h"

#include "test_cpp/alignof_test.h"
#include "test_cpp/alignas_test.h"
#include "test_cpp/align_test.h"
#include "test_cpp/struct_member_alignment_test.h"

namespace r2
{
	MenuUp AlignMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddItem( '1', struct_member_alignment_test::Basic::GetInstance() );


			ret->AddLineFeed();


			ret->AddItem( '2', alignof_test::Basic::GetInstance() );
			ret->AddItem( '3', alignof_test::MixedStruct::GetInstance() );


			ret->AddLineFeed();


			ret->AddItem( 'q', align_test::AlignAs::GetInstance() );


			ret->AddLineFeed();


			ret->AddItem( 'z', align_test::Align_0::GetInstance() );
			ret->AddItem( 'x', align_test::Align_1::GetInstance() );
			ret->AddItem( 'c', align_test::Align_2::GetInstance() );


			ret->AddSplit();


			ret->AddItem(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->eTestEndAction
				{
					director.Setup( r2::RootMenu::Create( director ) );
					return r2::eTestEndAction::None;
				}
			);
		}

		return ret;
	}
}