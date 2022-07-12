#include "C_CPP_Menu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "item/array_test.h"
#include "item/operator_ternary_test.h"
#include "item/print_test.h"
#include "item/structured_binding_test.h"
#include "item/using_test.h"

#include "AlignMenu.h"
#include "BitOperationMenu.h"
#include "EnumMenu.h"
#include "LambdaMenu.h"
#include "NewMenu.h"
#include "TemplateMenu.h"

#include "ClassMenu.h"
#include "CharMenu.h"
#include "PointerMenu.h"
#include "RootMenu.h"

r2cm::MenuUp C_CPP_Menu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, C_CPP_Menu::GetTitle() ) );

	{
		ret->AddItem(
			'1'
			, []()->const char* { return BitOperationMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( BitOperationMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
		ret->AddItem( '2', array_test::Init::GetInstance() );
		ret->AddItem(
			'3'
			, []()->const char* { return ClassMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( ClassMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);


		ret->AddLineFeed();


		ret->AddItem(
			'5'
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
			, []()->const char* { return TemplateMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( TemplateMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
		ret->AddItem(
			'8'
			, []()->const char* { return AlignMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( AlignMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
		ret->AddItem(
			'9'
			, []()->const char* { return EnumMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( EnumMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);


		ret->AddLineFeed();


		ret->AddItem(
			'q'
			, []()->const char* { return NewMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( NewMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
		ret->AddItem(
			'w'
			, []()->const char* { return LambdaMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( LambdaMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
		ret->AddItem( 'e', structured_binding_test::Basic::GetInstance() );
		ret->AddItem( 'r', print_test::Basic::GetInstance() );
		ret->AddItem( 't', print_test::ShowNumbers::GetInstance() );
		ret->AddItem( 'y', using_test::Basic::GetInstance() );


		ret->AddLineFeed();


		ret->AddItem( 'a', operator_ternary_test::Basic::GetInstance() );


		ret->AddSplit();


		ret->AddMenu<RootMenu>( 27 );
	}

	return ret;
}