#include "pch.h"
#include "r2_VariadicTemplateMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestEndAction.h"
#include "r2_TemplateMenu.h"

#include "test_cpp/variadic_template_test.h"

namespace r2
{
	MenuUp VariadicTemplateMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddChild( '1', variadic_template_test::SizeOfArgs::GetInstance() );
			ret->AddChild( '2', variadic_template_test::PrintValues::GetInstance() );
			ret->AddChild( '3', variadic_template_test::SumValues::GetInstance() );
			ret->AddChild( '4', variadic_template_test::SubtractValues::GetInstance() );


			ret->AddSplit();


			ret->AddChild(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->eTestEndAction
				{
					director.Setup( r2::TemplateMenu::Create( director ) );
					return eTestEndAction::ChangeScene;
				}
			);
		}

		return ret;
	}
}