#include "pch.h"
#include "r2_ETCMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestEndAction.h"
#include "r2_RootMenu.h"

#include "test_cpp/class_test.h"
#include "test_cpp/etc_0_test.h"

namespace r2
{
	MenuUp ETCMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

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