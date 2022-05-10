#include "pch.h"
#include "STDCoutMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_constant.h"

#include "test_cpp/item/std_cout_test.h"

#include "STDMenu.h"

r2cm::MenuUp STDCoutMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', std_cout_test::Basic::GetInstance() );
		ret->AddItem( '2', std_cout_test::FMTStatus::GetInstance() );
		ret->AddItem( '3', std_cout_test::NumberFormat_1::GetInstance() );
		ret->AddItem( '4', std_cout_test::NumberFormat_2::GetInstance() );
		ret->AddItem( '5', std_cout_test::NumberFormat_3::GetInstance() );
		ret->AddItem( '6', std_cout_test::NumberFormat_4::GetInstance() );


		ret->AddLineFeed();


		ret->AddItem( 'q', std_cout_test::Align::GetInstance() );
		ret->AddItem( 'w', std_cout_test::Flag::GetInstance() );
		ret->AddItem( 'e', std_cout_test::BoolAlpha::GetInstance() );


		ret->AddSplit();


		ret->AddItem(
			27
			, []()->const char* { return "Return To Root"; }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( STDMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
	}

	return ret;
}