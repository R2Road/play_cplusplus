#include "pch.h"
#include "C_CPP_Menu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_constant.h"

#include "item/bit_operation_test.h"
#include "item/print_test.h"
#include "item/structured_binding_test.h"

#include "r2_AlignMenu.h"
#include "r2_EnumMenu.h"
#include "r2_LambdaMenu.h"
#include "r2_NewMenu.h"
#include "r2_TemplateMenu.h"

#include "CharMenu.h"
#include "PointerMenu.h"
#include "RootMenu.h"

r2cm::MenuUp C_CPP_Menu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, C_CPP_Menu::GetTitle() ) );

	{
		ret->AddItem( '1', bit_operation_test::Basic::GetInstance() );
		ret->AddItem( '2', bit_operation_test::Mask::GetInstance() );

		ret->AddItem(
			'4'
			, []()->const char* { return PointerMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( PointerMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
		ret->AddItem(
			'6'
			, []()->const char* { return CharMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( CharMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
		ret->AddItem(
			'7'
			, []()->const char* { return r2::TemplateMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( r2::TemplateMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
		ret->AddItem(
			'8'
			, []()->const char* { return r2::AlignMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( r2::AlignMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
		ret->AddItem(
			'9'
			, []()->const char* { return r2::EnumMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( r2::EnumMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);


		ret->AddLineFeed();


		ret->AddItem(
			'q'
			, []()->const char* { return r2::NewMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( r2::NewMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
		ret->AddItem(
			'w'
			, []()->const char* { return r2::LambdaMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( r2::LambdaMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
		ret->AddItem( 'e', structured_binding_test::Basic::GetInstance() );
		ret->AddItem( 'r', print_test::Basic::GetInstance() );
		ret->AddItem( 't', print_test::ShowNumbers::GetInstance() );


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