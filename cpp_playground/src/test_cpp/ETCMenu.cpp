#include "ETCMenu.h"

#include "r2cm/r2cm_constant.h"
#include "r2cm/r2cm_Director.h"

#include "test_cpp/item/class_test.h"
#include "test_cpp/item/etc_0_test.h"

#include "RootMenu.h"

r2cm::MenuUp ETCMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '3', etc_test::Macro2String::GetInstance() );


		ret->AddLineFeed();


		ret->AddItem( 'q', class_test::Braces::GetInstance() );
		ret->AddItem( 'w', class_test::PrintName::GetInstance() );
		ret->AddItem( 'e', class_test::PrivateInheritance_1::GetInstance() );
		ret->AddItem( 'r', class_test::PrivateInheritance_2::GetInstance() );
		ret->AddItem( 't', class_test::MemberAdress::GetInstance() );
		ret->AddItem( 'y', class_test::ImplicitTypeConversion::GetInstance() );


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