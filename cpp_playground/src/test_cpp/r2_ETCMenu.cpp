#include "pch.h"
#include "r2_ETCMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_eTestEndAction.h"
#include "RootMenu.h"

#include "test_cpp/item/class_test.h"
#include "test_cpp/item/etc_0_test.h"

namespace r2
{
	r2cm::MenuUp ETCMenu::Create( r2cm::Director& director )
	{
		r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

		{
			ret->AddItem( '1', etc_test::XOR_Swap::GetInstance() );
			ret->AddItem( '2', etc_test::InitArray::GetInstance() );
			ret->AddItem( '3', etc_test::Macro2String::GetInstance() );
			ret->AddItem( '4', etc_test::Pointer2Index::GetInstance() );


			ret->AddLineFeed();


			ret->AddItem( 'q', class_test::Braces::GetInstance() );
			ret->AddItem( 'w', class_test::PrintName::GetInstance() );
			ret->AddItem( 'e', class_test::PrivateInheritance_1::GetInstance() );
			ret->AddItem( 'r', class_test::PrivateInheritance_2::GetInstance() );
			ret->AddItem( 't', class_test::MemberAdress::GetInstance() );


			ret->AddSplit();


			ret->AddItem(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->r2cm::eTestEndAction
				{
					director.Setup( RootMenu::Create( director ) );
					return r2cm::eTestEndAction::None;
				}
			);
		}

		return ret;
	}
}