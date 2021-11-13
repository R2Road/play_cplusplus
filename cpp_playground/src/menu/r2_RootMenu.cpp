#include "pch.h"
#include "r2_RootMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestResult.h"

#include "r2_ConsoleMenu.h"
#include "r2_FileSystemMenu.h"
#include "r2_PointerMenu.h"
#include "r2_RandomMenu.h"
#include "r2_TemplateMenu.h"
#include "r2_AlignMenu.h"
#include "r2_MemoryMenu.h"
#include "r2_EnumMenu.h"
#include "r2_TimeMenu.h"

#include "r2_LambdaMenu.h"
#include "r2_NewMenu.h"

#include "test_cpp/optional_test.h"
#include "test_cpp/variant_test.h"
#include "test_cpp/tuple_test.h"
#include "test_cpp/structured_binding_test.h"
#include "test_cpp/pointer_test.h"
#include "test_cpp/assert_test.h"
#include "r2_ThreadMenu.h"

#include "test_cpp/string_view_test.h"
#include "test_cpp/lambda_test.h"
#include "test_cpp/print_test.h"
#include "r2_CharMenu.h"
#include "r2_ContainerMenu.h"
#include "r2_AlgorithmMenu.h"

#include "test_cpp/thread_test.h"
#include "test_cpp/key_test.h"
#include "r2_ETCMenu.h"
#include "r2_MathMenu.h"

#include "r2_RenderMenu.h"

namespace r2
{
	MenuUp RootMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu(
			director
			, GetTitle()
			, "> Inprogress : Thread"
			"\n" "> Inprogress : Vector3"
			"\n" "> Inprogress : Encoding"
			"\n" "> To do : Renderer"
			"\n" "> To do : Memory Pool"
		) );

		{
			ret->AddChild(
				'1'
				, []()->const char* { return ConsoleMenu::GetTitle(); }
				, [&director]()->eTestResult
				{
					director.Setup( ConsoleMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);
			ret->AddChild(
				'2'
				, []()->const char* { return r2::FileSystemMenu::GetTitle(); }
				, [&director]()->eTestResult
				{
					director.Setup( r2::FileSystemMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);
			ret->AddChild(
				'3'
				, []()->const char* { return r2::PointerMenu::GetTitle(); }
				, [&director]()->eTestResult
				{
					director.Setup( r2::PointerMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);
			ret->AddChild(
				'4'
				, []()->const char* { return r2::RandomMenu::GetTitle(); }
				, [&director]()->eTestResult
				{
					director.Setup( r2::RandomMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);
			ret->AddChild(
				'5'
				, []()->const char* { return r2::TemplateMenu::GetTitle(); }
				, [&director]()->eTestResult
				{
					director.Setup( r2::TemplateMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);
			ret->AddChild(
				'6'
				, []()->const char* { return r2::AlignMenu::GetTitle(); }
				, [&director]()->eTestResult
				{
					director.Setup( r2::AlignMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);
			ret->AddChild(
				'7'
				, []()->const char* { return r2::MemoryMenu::GetTitle(); }
				, [&director]()->eTestResult
				{
					director.Setup( r2::MemoryMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);
			ret->AddChild(
				'8'
				, []()->const char* { return r2::EnumMenu::GetTitle(); }
				, [&director]()->eTestResult
				{
					director.Setup( r2::EnumMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);
			ret->AddChild(
				'9'
				, []()->const char* { return r2::TimeMenu::GetTitle(); }
				, [&director]()->eTestResult
				{
					director.Setup( r2::TimeMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);


			ret->AddLineFeed();


			ret->AddChild(
				'q'
				, []()->const char* { return r2::LambdaMenu::GetTitle(); }
				, [&director]()->eTestResult
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
			ret->AddChild(
				'u'
				, []()->const char* { return r2::ThreadMenu::GetTitle(); }
				, [&director]()->eTestResult
				{
					director.Setup( r2::ThreadMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);


			ret->AddLineFeed();


			ret->AddChild( 'a', stringview_test::Basic::GetInstance() );
			ret->AddChild(
				's'
				, []()->const char* { return r2::NewMenu::GetTitle(); }
				, [&director]()->eTestResult
				{
					director.Setup( r2::NewMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);
			ret->AddChild( 'd', print_test::Basic::GetInstance() );
			ret->AddChild(
				'f'
				, []()->const char* { return r2::CharMenu::GetTitle(); }
				, [&director]()->eTestResult
				{
					director.Setup( r2::CharMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);
			ret->AddChild(
				'g'
				, []()->const char* { return r2::ContainerMenu::GetTitle(); }
				, [&director]()->eTestResult
				{
					director.Setup( r2::ContainerMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);
			ret->AddChild(
				'h'
				, []()->const char* { return r2::AlgorithmMenu::GetTitle(); }
				, [&director]()->eTestResult
				{
					director.Setup( r2::AlgorithmMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);


			ret->AddLineFeed();


			ret->AddChild( 'z', thread_test::Basic::GetInstance() );
			ret->AddChild( 'x', key_test::Basic::GetInstance() );
			ret->AddChild(
				'c'
				, []()->const char* { return r2::ETCMenu::GetTitle(); }
				, [&director]()->eTestResult
				{
					director.Setup( r2::ETCMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);
			ret->AddChild(
				'v'
				, []()->const char* { return r2::MathMenu::GetTitle(); }
				, [&director]()->eTestResult
				{
					director.Setup( r2::MathMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);


			ret->AddSplit();


			ret->AddChild(
				32
				, []()->const char* { return r2::RenderMenu::GetTitle(); }
				, [&director]()->eTestResult
				{
					director.Setup( r2::RenderMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);


			ret->AddSplit();


			ret->AddChild(
				27
				, []()->const char* { return "Exit"; }
				, []()->eTestResult { return eTestResult::Exit; }
			);
		}

		return ret;
	}
}