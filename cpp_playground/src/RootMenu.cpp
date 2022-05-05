#include "pch.h"
#include "RootMenu.h"

#include "base/r2cm_Director.h"
#include "base/r2cm_eTestEndAction.h"

#include "test_cpp/C_CPP_Menu.h"

#include "test_cpp/r2_ConsoleMenu.h"
#include "test_cpp/r2_DebugMenu.h"
#include "test_cpp/r2_FileSystemMenu.h"
#include "test_hobby/HobbyMenu.h"
#include "test_cpp/r2_PointerMenu.h"
#include "test_cpp/r2_RandomMenu.h"
#include "test_cpp/r2_TemplateMenu.h"
#include "test_cpp/r2_AlignMenu.h"
#include "test_cpp/r2_EnumMenu.h"
#include "test_cpp/r2_TimeMenu.h"

#include "test_cpp/r2_LambdaMenu.h"
#include "test_cpp/r2_NewMenu.h"

#include "test_cpp/item/structured_binding_test.h"
#include "test_cpp/item/pointer_test.h"

#include "test_cpp/item/lambda_test.h"
#include "test_cpp/item/print_test.h"
#include "test_cpp/r2_CharMenu.h"
#include "test_cpp/r2_STDMenu.h"

#include "test_cpp/item/console_input_test.h"
#include "test_cpp/r2_ETCMenu.h"
#include "test_cpp/r2_MathMenu.h"
#include "test_cpp/r2_PerformanceMenu.h"

#include "test_algorithm/TestAlgorithmMenu.h"

r2cm::MenuUp RootMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu(
		director
		, GetTitle(),
				"> To do : Regex"
		"\n"	"> To do : Vector3"
		"\n"	"> To do : Encoding"
		"\n"	"> To do : Infinite Number"
		"\n"	"> To do : Thread"
		"\n"	"> To do : Memory Pool"
	) );

	{
		ret->AddItem( '1', console_input_test::Basic::GetInstance() );
		ret->AddItem(
			'2'
			, []()->const char* { return r2::ConsoleMenu::GetTitle(); }
			, [&director]()->r2cm::eTestEndAction
			{
				director.Setup( r2::ConsoleMenu::Create( director ) );
				return r2cm::eTestEndAction::None;
			}
		);
		ret->AddItem(
			'3'
			, []()->const char* { return r2::FileSystemMenu::GetTitle(); }
			, [&director]()->r2cm::eTestEndAction
			{
				director.Setup( r2::FileSystemMenu::Create( director ) );
				return r2cm::eTestEndAction::None;
			}
		);
		ret->AddItem(
			'4'
			, []()->const char* { return r2::PointerMenu::GetTitle(); }
			, [&director]()->r2cm::eTestEndAction
			{
				director.Setup( r2::PointerMenu::Create( director ) );
				return r2cm::eTestEndAction::None;
			}
		);
		ret->AddItem(
			'5'
			, []()->const char* { return r2::TimeMenu::GetTitle(); }
			, [&director]()->r2cm::eTestEndAction
			{
				director.Setup( r2::TimeMenu::Create( director ) );
				return r2cm::eTestEndAction::None;
			}
		);
		ret->AddItem(
			'6'
			, []()->const char* { return r2::RandomMenu::GetTitle(); }
			, [&director]()->r2cm::eTestEndAction
			{
				director.Setup( r2::RandomMenu::Create( director ) );
				return r2cm::eTestEndAction::None;
			}
		);
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
			, []()->const char* { return C_CPP_Menu::GetTitle(); }
			, [&director]()->r2cm::eTestEndAction
			{
				director.Setup( C_CPP_Menu::Create( director ) );
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
		ret->AddItem(
			'r'
			, []()->const char* { return r2::DebugMenu::GetTitle(); }
			, [&director]()->r2cm::eTestEndAction
			{
				director.Setup( r2::DebugMenu::Create( director ) );
				return r2cm::eTestEndAction::None;
			}
		);


		ret->AddLineFeed();


		ret->AddItem(
			'a'
			, []()->const char* { return r2::STDMenu::GetTitle(); }
			, [&director]()->r2cm::eTestEndAction
			{
				director.Setup( r2::STDMenu::Create( director ) );
				return r2cm::eTestEndAction::None;
			}
		);
		ret->AddItem(
			's'
			, []()->const char* { return r2::NewMenu::GetTitle(); }
			, [&director]()->r2cm::eTestEndAction
			{
				director.Setup( r2::NewMenu::Create( director ) );
				return r2cm::eTestEndAction::None;
			}
		);
		ret->AddItem( 'd', print_test::Basic::GetInstance() );
		ret->AddItem( 'f', print_test::ShowNumbers::GetInstance() );
		ret->AddItem( 'g', print_test::BoolAlpha::GetInstance() );
		ret->AddItem(
			'h'
			, []()->const char* { return r2::CharMenu::GetTitle(); }
			, [&director]()->r2cm::eTestEndAction
			{
				director.Setup( r2::CharMenu::Create( director ) );
				return r2cm::eTestEndAction::None;
			}
		);


		ret->AddLineFeed();


		ret->AddItem(
			'z'
			, []()->const char* { return r2::ETCMenu::GetTitle(); }
			, [&director]()->r2cm::eTestEndAction
			{
				director.Setup( r2::ETCMenu::Create( director ) );
				return r2cm::eTestEndAction::None;
			}
		);
		ret->AddItem(
			'x'
			, []()->const char* { return r2::MathMenu::GetTitle(); }
			, [&director]()->r2cm::eTestEndAction
			{
				director.Setup( r2::MathMenu::Create( director ) );
				return r2cm::eTestEndAction::None;
			}
		);
		ret->AddItem(
			'c'
			, []()->const char* { return r2::PerformanceMenu::GetTitle(); }
			, [&director]()->r2cm::eTestEndAction
			{
				director.Setup( r2::PerformanceMenu::Create( director ) );
				return r2cm::eTestEndAction::None;
			}
		);


		ret->AddSplit();


		ret->AddItem(
			32
			, []()->const char* { return TestAlgorithmMenu::GetTitle(); }
			, [&director]()->r2cm::eTestEndAction
			{
				director.Setup( TestAlgorithmMenu::Create( director ) );
				return r2cm::eTestEndAction::None;
			}
		);
		ret->AddItem(
			'`'
			, []()->const char* { return HobbyMenu::GetTitle(); }
			, [&director]()->r2cm::eTestEndAction
			{
				director.Setup( HobbyMenu::Create( director ) );
				return r2cm::eTestEndAction::None;
			}
		);


		ret->AddSplit();


		ret->AddItem(
			27
			, []()->const char* { return "Exit"; }
			, []()->r2cm::eTestEndAction { return r2cm::eTestEndAction::Exit; }
		);
	}

	return ret;
}