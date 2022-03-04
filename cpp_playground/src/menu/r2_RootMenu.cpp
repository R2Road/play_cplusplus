#include "pch.h"
#include "r2_RootMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestEndAction.h"

#include "r2_ConsoleMenu.h"
#include "r2_DebugMenu.h"
#include "r2_FileSystemMenu.h"
#include "r2_HobbyMenu.h"
#include "r2_PointerMenu.h"
#include "r2_RandomMenu.h"
#include "r2_TemplateMenu.h"
#include "r2_AlignMenu.h"
#include "r2_EnumMenu.h"
#include "r2_TimeMenu.h"

#include "r2_LambdaMenu.h"
#include "r2_NewMenu.h"

#include "test_cpp/structured_binding_test.h"
#include "test_cpp/pointer_test.h"

#include "test_cpp/lambda_test.h"
#include "test_cpp/print_test.h"
#include "r2_CharMenu.h"
#include "r2_STDMenu.h"

#include "test_cpp/console_input_test.h"
#include "r2_ETCMenu.h"
#include "r2_MathMenu.h"
#include "r2_PerformanceMenu.h"

#include "r2_AlgorithmMenu.h"

namespace r2
{
	MenuUp RootMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu(
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
				, []()->const char* { return ConsoleMenu::GetTitle(); }
				, [&director]()->eTestEndAction
				{
					director.Setup( ConsoleMenu::Create( director ) );
					return r2::eTestEndAction::None;
				}
			);
			ret->AddItem(
				'3'
				, []()->const char* { return r2::FileSystemMenu::GetTitle(); }
				, [&director]()->eTestEndAction
				{
					director.Setup( r2::FileSystemMenu::Create( director ) );
					return r2::eTestEndAction::None;
				}
			);
			ret->AddItem(
				'4'
				, []()->const char* { return r2::PointerMenu::GetTitle(); }
				, [&director]()->eTestEndAction
				{
					director.Setup( r2::PointerMenu::Create( director ) );
					return r2::eTestEndAction::None;
				}
			);
			ret->AddItem(
				'5'
				, []()->const char* { return r2::TimeMenu::GetTitle(); }
				, [&director]()->eTestEndAction
				{
					director.Setup( r2::TimeMenu::Create( director ) );
					return r2::eTestEndAction::None;
				}
			);
			ret->AddItem(
				'6'
				, []()->const char* { return r2::RandomMenu::GetTitle(); }
				, [&director]()->eTestEndAction
				{
					director.Setup( r2::RandomMenu::Create( director ) );
					return r2::eTestEndAction::None;
				}
			);
			ret->AddItem(
				'7'
				, []()->const char* { return r2::TemplateMenu::GetTitle(); }
				, [&director]()->eTestEndAction
				{
					director.Setup( r2::TemplateMenu::Create( director ) );
					return r2::eTestEndAction::None;
				}
			);
			ret->AddItem(
				'8'
				, []()->const char* { return r2::AlignMenu::GetTitle(); }
				, [&director]()->eTestEndAction
				{
					director.Setup( r2::AlignMenu::Create( director ) );
					return r2::eTestEndAction::None;
				}
			);
			ret->AddItem(
				'9'
				, []()->const char* { return r2::EnumMenu::GetTitle(); }
				, [&director]()->eTestEndAction
				{
					director.Setup( r2::EnumMenu::Create( director ) );
					return r2::eTestEndAction::None;
				}
			);


			ret->AddLineFeed();


			ret->AddItem(
				'q'
				, []()->const char* { return r2::LambdaMenu::GetTitle(); }
				, [&director]()->eTestEndAction
				{
					director.Setup( r2::LambdaMenu::Create( director ) );
					return r2::eTestEndAction::None;
				}
			);
			ret->AddItem( 'w', structured_binding_test::Basic::GetInstance() );			
			ret->AddItem(
				'e'
				, []()->const char* { return r2::DebugMenu::GetTitle(); }
				, [&director]()->eTestEndAction
				{
					director.Setup( r2::DebugMenu::Create( director ) );
					return r2::eTestEndAction::None;
				}
			);


			ret->AddLineFeed();


			ret->AddItem(
				'a'
				, []()->const char* { return r2::STDMenu::GetTitle(); }
				, [&director]()->eTestEndAction
				{
					director.Setup( r2::STDMenu::Create( director ) );
					return r2::eTestEndAction::None;
				}
			);
			ret->AddItem(
				's'
				, []()->const char* { return r2::NewMenu::GetTitle(); }
				, [&director]()->eTestEndAction
				{
					director.Setup( r2::NewMenu::Create( director ) );
					return r2::eTestEndAction::None;
				}
			);
			ret->AddItem( 'd', print_test::Basic::GetInstance() );
			ret->AddItem( 'f', print_test::ShowNumbers::GetInstance() );
			ret->AddItem( 'g', print_test::BoolAlpha::GetInstance() );
			ret->AddItem(
				'h'
				, []()->const char* { return r2::CharMenu::GetTitle(); }
				, [&director]()->eTestEndAction
				{
					director.Setup( r2::CharMenu::Create( director ) );
					return r2::eTestEndAction::None;
				}
			);


			ret->AddLineFeed();


			ret->AddItem(
				'z'
				, []()->const char* { return r2::ETCMenu::GetTitle(); }
				, [&director]()->eTestEndAction
				{
					director.Setup( r2::ETCMenu::Create( director ) );
					return r2::eTestEndAction::None;
				}
			);
			ret->AddItem(
				'x'
				, []()->const char* { return r2::MathMenu::GetTitle(); }
				, [&director]()->eTestEndAction
				{
					director.Setup( r2::MathMenu::Create( director ) );
					return r2::eTestEndAction::None;
				}
			);
			ret->AddItem(
				'c'
				, []()->const char* { return r2::PerformanceMenu::GetTitle(); }
				, [&director]()->eTestEndAction
				{
					director.Setup( r2::PerformanceMenu::Create( director ) );
					return r2::eTestEndAction::None;
				}
			);


			ret->AddSplit();


			ret->AddItem(
				32
				, []()->const char* { return r2::AlgorithmMenu::GetTitle(); }
				, [&director]()->eTestEndAction
				{
					director.Setup( r2::AlgorithmMenu::Create( director ) );
					return r2::eTestEndAction::None;
				}
			);
			ret->AddItem(
				'`'
				, []()->const char* { return r2::HobbyMenu::GetTitle(); }
				, [&director]()->eTestEndAction
				{
					director.Setup( r2::HobbyMenu::Create( director ) );
					return r2::eTestEndAction::None;
				}
			);


			ret->AddSplit();


			ret->AddItem(
				27
				, []()->const char* { return "Exit"; }
				, []()->eTestEndAction { return eTestEndAction::Exit; }
			);
		}

		return ret;
	}
}