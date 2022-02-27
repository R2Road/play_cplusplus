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
			ret->AddChild( '1', struct_member_alignment_test::Basic::GetInstance() );


			ret->AddLineFeed();


			ret->AddChild( '2', alignof_test::Basic::GetInstance() );
			ret->AddChild( '3', alignof_test::MixedStruct::GetInstance() );


			ret->AddLineFeed();


			ret->AddChild( 'q', align_test::AlignAs::GetInstance() );


			ret->AddLineFeed();


			ret->AddChild( 'z', align_test::Align_0::GetInstance() );
			ret->AddChild( 'x', align_test::Align_1::GetInstance() );
			ret->AddChild( 'c', align_test::Align_2::GetInstance() );


			ret->AddSplit();


			ret->AddChild(
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