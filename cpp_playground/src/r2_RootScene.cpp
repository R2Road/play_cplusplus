#include "pch.h"
#include "r2_RootScene.h"

#include "r2_ConsoleScene.h"
#include "r2_Director.h"
#include "r2_eTestResult.h"
#include "r2_FileSystemScene.h"
#include "r2_PointerTestScene.h"
#include "r2_RandomScene.h"
#include "r2_TemplateScene.h"
#include "r2_VariadicTemplateScene.h"
#include "r2_AlignScene.h"
#include "r2_MemoryScene.h"
#include "r2_RendererScene.h"
#include "r2_EnumScene.h"
#include "r2_LambdaMenu.h"
#include "r2_NewScene.h"

#include "optional_test.h"
#include "variant_test.h"
#include "tuple_test.h"
#include "structured_binding_test.h"
#include "pointer_test.h"
#include "assert_test.h"
#include "string_view_test.h"
#include "korean_test.h"
#include "lambda_test.h"
#include "print_test.h"
#include "char_test.h"

namespace r2
{
	SceneUp RootScene::Create( Director& director )
	{
		SceneUp ret( new ( std::nothrow ) Scene(
			director
			, GetTitle()
			, "> Inprogress : Renderer" "\n" "> To do : Memory Pool" "\n"
		) );

		{
			ret->AddChild(
				'1'
				, []()->const char* { return ConsoleScene::GetTitle(); }
				, [&director]()->const eTestResult
				{
					director.Setup( ConsoleScene::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);
			
			ret->AddChild(
				'2'
				, []()->const char* { return r2::FileSystemScene::GetTitle(); }
				, [&director]()->const eTestResult
				{
					director.Setup( r2::FileSystemScene::Create( director ) );
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
				, []()->const char* { return r2::RandomScene::GetTitle(); }
				, [&director]()->const eTestResult
				{
					director.Setup( r2::RandomScene::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);

			ret->AddChild(
				'5'
				, []()->const char* { return r2::VariadicTemplateScene::GetTitle(); }
				, [&director]()->const eTestResult
				{
					director.Setup( r2::VariadicTemplateScene::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);

			ret->AddChild(
				'6'
				, []()->const char* { return r2::TemplateScene::GetTitle(); }
				, [&director]()->const eTestResult
				{
					director.Setup( r2::TemplateScene::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);

			ret->AddChild(
				'7'
				, []()->const char* { return r2::AlignScene::GetTitle(); }
				, [&director]()->const eTestResult
				{
					director.Setup( r2::AlignScene::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);

			ret->AddChild(
				'8'
				, []()->const char* { return r2::MemoryScene::GetTitle(); }
				, [&director]()->const eTestResult
				{
					director.Setup( r2::MemoryScene::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);

			ret->AddChild(
				'9'
				, []()->const char* { return r2::EnumScene::GetTitle(); }
				, [&director]()->const eTestResult
				{
					director.Setup( r2::EnumScene::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);

			ret->AddSplit();

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

			ret->AddSplit();

			ret->AddChild( 'a', stringview_test::Basic::GetInstance() );

			ret->AddChild(
				's'
				, []()->const char* { return r2::NewScene::GetTitle(); }
				, [&director]()->const eTestResult
				{
					director.Setup( r2::NewScene::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);

			ret->AddChild( 'd', print_test::Basic::GetInstance() );
			ret->AddChild( 'f', char_test::Basic::GetInstance() );

			ret->AddSplit();

			ret->AddChild( 'z', korean_test::Basic::GetInstance() );

			ret->AddSplit();

			ret->AddChild(
				32
				, []()->const char* { return r2::RendererScene::GetTitle(); }
				, [&director]()->const eTestResult
				{
					director.Setup( r2::RendererScene::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);

			ret->AddSplit();

			ret->AddChild(
				27
				, []()->const char* { return "Exit"; }
				, []()->const eTestResult { return eTestResult::Exit; }
			);
		}

		return ret;
	}
}