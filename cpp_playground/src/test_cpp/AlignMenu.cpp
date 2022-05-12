#include "AlignMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_constant.h"

#include "test_cpp/item/alignof_test.h"
#include "test_cpp/item/alignas_test.h"
#include "test_cpp/item/align_test.h"
#include "test_cpp/item/struct_member_alignment_test.h"

#include "C_CPP_Menu.h"

r2cm::MenuUp AlignMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

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
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( C_CPP_Menu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
	}

	return ret;
}