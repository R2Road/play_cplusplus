#include "ClassMenu.h"

#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_Director.h"

#include "test_cpp/item/class_test.h"

#include "C_CPP_Menu.h"

r2cm::MenuUp ClassMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', class_test::Braces::GetInstance() );
		ret->AddItem( '2', class_test::PrintName::GetInstance() );
		ret->AddItem( '3', class_test::PrivateInheritance_1::GetInstance() );
		ret->AddItem( '4', class_test::PrivateInheritance_2::GetInstance() );
		ret->AddItem( '5', class_test::MemberAdress::GetInstance() );
		ret->AddItem( '6', class_test::ImplicitTypeConversion::GetInstance() );


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