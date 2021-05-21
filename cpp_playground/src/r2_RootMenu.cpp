#include "pch.h"
#include "r2_RootMenu.h"

#include "r2_ConsoleMenu.h"
#include "r2_Director.h"
#include "r2_eTestResult.h"
#include "r2_FileSystemMenu.h"
#include "r2_PointerTestScene.h"
#include "r2_RandomMenu.h"
#include "r2_TemplateMenu.h"
#include "r2_AlignMenu.h"
#include "r2_MemoryMenu.h"
#include "r2_RendererMenu.h"
#include "r2_EnumMenu.h"
#include "r2_LambdaMenu.h"
#include "r2_NewMenu.h"

#include "optional_test.h"
#include "variant_test.h"
#include "tuple_test.h"
#include "structured_binding_test.h"
#include "pointer_test.h"
#include "assert_test.h"
#include "string_view_test.h"
#include "lambda_test.h"
#include "print_test.h"
#include "char_test.h"

#include "korean_test.h"
#include "key_test.h"
#include "r2_ETCMenu.h"

namespace r2
{
	MenuUp RootMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu(
			director
			, GetTitle()
			, "> Inprogress : Renderer" "\n" "> To do : Memory Pool"
		) );

		{
			ret->AddChild(
				'1'
				, []()->const char* { return ConsoleMenu::GetTitle(); }
				, [&director]()->const eTestResult
				{
					director.Setup( ConsoleMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);
			
			ret->AddChild(
				'2'
				, []()->const char* { return r2::FileSystemMenu::GetTitle(); }
				, [&director]()->const eTestResult
				{
					director.Setup( r2::FileSystemMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);

			ret->AddChild(
				'3'
				, []()->const char* { return r2::PointerTestScene::GetTitle(); }
				, [&director]()->const eTestResult
				{
					director.Setup( r2::PointerTestScene::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);

			ret->AddChild(
				'4'
				, []()->const char* { return r2::RandomMenu::GetTitle(); }
				, [&director]()->const eTestResult
				{
					director.Setup( r2::RandomMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);

			ret->AddChild(
				'5'
				, []()->const char* { return r2::TemplateMenu::GetTitle(); }
				, [&director]()->const eTestResult
				{
					director.Setup( r2::TemplateMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);

			ret->AddChild(
				'6'
				, []()->const char* { return r2::AlignMenu::GetTitle(); }
				, [&director]()->const eTestResult
				{
					director.Setup( r2::AlignMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);

			ret->AddChild(
				'7'
				, []()->const char* { return r2::MemoryMenu::GetTitle(); }
				, [&director]()->const eTestResult
				{
					director.Setup( r2::MemoryMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);

			ret->AddChild(
				'8'
				, []()->const char* { return r2::EnumMenu::GetTitle(); }
				, [&director]()->const eTestResult
				{
					director.Setup( r2::EnumMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);

			ret->AddLineFeed();

			ret->AddChild(
				'q'
				, []()->const char* { return r2::LambdaMenu::GetTitle(); }
				, [&director]()->const eTestResult
				{
					director.Setup( r2::LambdaMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);
			ret->AddChild( 'w', optional_test::Basic::GetInstance() );
			ret->AddChild( 'e', variant_test::Basic::GetInstance() );
			ret->AddChild( 'r', tuple_test::Basic::GetInstance() );
			ret->AddChild( 't', structured_binding_test::Basic::GetInstance() );			
			ret->AddChild( 'y', assert_test::Basic::GetInstance() );

			ret->AddLineFeed();

			ret->AddChild( 'a', stringview_test::Basic::GetInstance() );

			ret->AddChild(
				's'
				, []()->const char* { return r2::NewMenu::GetTitle(); }
				, [&director]()->const eTestResult
				{
					director.Setup( r2::NewMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);

			ret->AddChild( 'd', print_test::Basic::GetInstance() );
			ret->AddChild( 'f', char_test::Basic::GetInstance() );

			ret->AddLineFeed();

			ret->AddChild( 'z', korean_test::Basic::GetInstance() );
			ret->AddChild( 'x', key_test::Basic::GetInstance() );
			ret->AddChild(
				'c'
				, []()->const char* { return r2::ETCMenu::GetTitle(); }
				, [&director]()->const eTestResult
				{
					director.Setup( r2::ETCMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);

			ret->AddSplit();

			ret->AddChild(
				32
				, []()->const char* { return r2::RendererMenu::GetTitle(); }
				, [&director]()->const eTestResult
				{
					director.Setup( r2::RendererMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);

			ret->AddSplit();

			ret->AddChild(
				27
				, []()->const char* { return "Exit"; }
				, []()->const eTestResult { return eTestResult::Exit; }
			);

			ret->AddSplit();
		}

		return ret;
	}
}