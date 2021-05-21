#include "pch.h"
#include "r2_VariadicTemplateMenu.h"

#include "r2_Director.h"
#include "r2_eTestResult.h"
#include "r2_TemplateMenu.h"

#include "variadic_template_test.h"

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
				, [&director]()->eTestResult
				{
					director.Setup( r2::TemplateMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);


			ret->AddSplit();
		}

		return ret;
	}
}