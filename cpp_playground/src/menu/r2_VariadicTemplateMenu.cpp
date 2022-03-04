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
			ret->AddItem( '1', variadic_template_test::SizeOfArgs::GetInstance() );
			ret->AddItem( '2', variadic_template_test::PrintValues::GetInstance() );
			ret->AddItem( '3', variadic_template_test::SumValues::GetInstance() );
			ret->AddItem( '4', variadic_template_test::SubtractValues::GetInstance() );


			ret->AddSplit();


			ret->AddItem(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->eTestEndAction
				{
					director.Setup( r2::TemplateMenu::Create( director ) );
					return r2::eTestEndAction::None;
				}
			);
		}

		return ret;
	}
}