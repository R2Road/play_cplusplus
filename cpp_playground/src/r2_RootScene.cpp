#include "r2_RootScene.h"

#include <iostream>

#include "r2_Director.h"
#include "r2_RandomTestScene.h"
#include "r2_Scene.h"

#include "filesystem_test.h"
#include "shared_pointer_test.h"
#include "variadic_template_test.h"
#include "template_meta_programming_test.h"
#include "optional_test.h"
#include "variant_test.h"
#include "tuple_test.h"
#include "structured_binding_test.h"
#include "const_pointer_test.h"
#include "assert_test.h"
#include "string_view_test.h"
#include "enum_test.h"

namespace r2
{
	SceneUp RootScene::Create( Director& director )
	{
		SceneUp ret( new ( std::nothrow ) Scene( director, "Root" ) );

		{
			ret->AddChild( '1', filesystem_test::CurrentDirectory::GetInstance() );

			ret->AddChild(
				'2'
				, []()->const char* { return "Random"; }
				, [&director]()->const eTestResult
				{
					director.Setup( r2::RandomTestScene::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);

			ret->AddChild( '3', shared_pointer_test::SharedPtr::GetInstance() );
			ret->AddChild( '4', variadic_template_test::PrintValues::GetInstance() );
			ret->AddChild( '5', variadic_template_test::SumValues::GetInstance() );
			ret->AddChild( '6', variadic_template_test::SubtractValues::GetInstance() );
			ret->AddChild( '7', template_meta_programming_test::CalculateFactorial::GetInstance() );
			ret->AddChild( '8', template_meta_programming_test::Integer2String::GetInstance() );
			ret->AddChild( '9', template_meta_programming_test::CalculatePlaceValue::GetInstance() );
			ret->AddChild( 'q', template_meta_programming_test::Integer2String_II::GetInstance() );
			ret->AddChild( 'w', optional_test::Basic::GetInstance() );
			ret->AddChild( 'e', variant_test::Basic::GetInstance() );
			ret->AddChild( 'r', variadic_template_test::SizeOfArgs::GetInstance() );
			ret->AddChild( 't', tuple_test::Basic::GetInstance() );
			ret->AddChild( 'y', structured_binding_test::Basic::GetInstance() );
			ret->AddChild( 'i', const_pointer_test::Basic::GetInstance() );
			ret->AddChild( 'o', assert_test::Basic::GetInstance() );
			ret->AddChild( 'p', template_meta_programming_test::MultiTypePackage::GetInstance() );

			ret->AddChild( 'a', stringview_test::Basic::GetInstance() );
			ret->AddChild( 's', enum_test::Basic::GetInstance() );
			ret->AddChild( 'd', enum_test::Convert::GetInstance() );

			ret->AddChild(
				27
				, []()->const char* { return "\nESC : Exit"; }
				, []()->const eTestResult { return eTestResult::Exit; }
			);
		}

		return ret;
	}
}