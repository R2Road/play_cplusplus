#include "pch.h"
#include "C_CPP_Menu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_eTestEndAction.h"

#include "test_cpp/item/structured_binding_test.h"

#include "RootMenu.h"
#include "test_cpp/r2_AlignMenu.h"
#include "test_cpp/r2_EnumMenu.h"
#include "test_cpp/r2_LambdaMenu.h"
#include "test_cpp/r2_NewMenu.h"
#include "test_cpp/r2_TemplateMenu.h"

r2cm::MenuUp C_CPP_Menu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, C_CPP_Menu::GetTitle() ) );

	{
		ret->AddItem(
			'7'
			, []()->const char* { return r2::TemplateMenu::GetTitle(); }
			, [&director]()->r2cm::eTestEndAction
			{
				director.Setup( r2::TemplateMenu::Create( director ) );
				return r2cm::eTestEndAction::None;
			}
		);
		ret->AddItem(
			'8'
			, []()->const char* { return r2::AlignMenu::GetTitle(); }
			, [&director]()->r2cm::eTestEndAction
			{
				director.Setup( r2::AlignMenu::Create( director ) );
				return r2cm::eTestEndAction::None;
			}
		);
		ret->AddItem(
			'9'
			, []()->const char* { return r2::EnumMenu::GetTitle(); }
			, [&director]()->r2cm::eTestEndAction
			{
				director.Setup( r2::EnumMenu::Create( director ) );
				return r2cm::eTestEndAction::None;
			}
		);


		ret->AddLineFeed();


		ret->AddItem(
			'q'
			, []()->const char* { return r2::NewMenu::GetTitle(); }
			, [&director]()->r2cm::eTestEndAction
			{
				director.Setup( r2::NewMenu::Create( director ) );
				return r2cm::eTestEndAction::None;
			}
		);
		ret->AddItem(
			'w'
			, []()->const char* { return r2::LambdaMenu::GetTitle(); }
			, [&director]()->r2cm::eTestEndAction
			{
				director.Setup( r2::LambdaMenu::Create( director ) );
				return r2cm::eTestEndAction::None;
			}
		);
		ret->AddItem( 'e', structured_binding_test::Basic::GetInstance() );


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