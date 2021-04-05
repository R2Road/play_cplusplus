#include "r2_RootScene.h"

#include <iostream>

#include "r2_Director.h"
#include "r2_RandomTestScene.h"

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

namespace r2
{
	RootScene::RootScene( Director& director ) : iScene( director )
	{
		AddChild( '1', filesystem_test::CurrentDirectory::GetInstance() );

		AddChild(
			'2'
			, []()->const char* { return "Random"; }
			, [this]()->const eTestResult
			{
				mDirector.Setup( r2::RandomTestScene::Create( mDirector ) );
				return eTestResult::ChangeScene;
			}
		);

		AddChild( '3', shared_pointer_test::SharedPtr::GetInstance() );
		AddChild( '4', variadic_template_test::PrintValues::GetInstance() );
		AddChild( '5', variadic_template_test::SumValues::GetInstance() );
		AddChild( '6', variadic_template_test::SubtractValues::GetInstance() );
		AddChild( '7', template_meta_programming_test::CalculateFactorial::GetInstance() );
		AddChild( '8', template_meta_programming_test::Integer2String::GetInstance() );
		AddChild( '9', template_meta_programming_test::CalculatePlaceValue::GetInstance() );
		AddChild( 'q', template_meta_programming_test::Integer2String_II::GetInstance() );
		AddChild( 'w', optional_test::Basic::GetInstance() );
		AddChild( 'e', variant_test::Basic::GetInstance() );
		AddChild( 'r', variadic_template_test::SizeOfArgs::GetInstance() );
		AddChild( 't', tuple_test::Basic::GetInstance() );
		AddChild( 'y', structured_binding_test::Basic::GetInstance() );
		AddChild( 'i', const_pointer_test::Basic::GetInstance() );
		AddChild( 'o', assert_test::Basic::GetInstance() );
		AddChild( 'p', template_meta_programming_test::MultiTypePackage::GetInstance() );

		AddChild( 'a', stringview_test::Basic::GetInstance() );

		AddChild(
			27
			, []()->const char* { return "\nESC : Exit"; }
			, [this]()->const eTestResult { return eTestResult::Exit; }
		);
	}

	SceneUp RootScene::Create( Director& director )
	{
		return SceneUp( new ( std::nothrow ) MyT( director ) );
	}

	void RootScene::ShowTitle() const
	{
		std::cout << "# Root #" << std::endl << std::endl;
	}
}