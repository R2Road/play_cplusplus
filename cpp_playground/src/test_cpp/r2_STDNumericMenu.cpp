#include "pch.h"
#include "r2_STDNumericMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_eTestEndAction.h"
#include "r2_STDMenu.h"

#include "test_cpp/item/std_numeric_test.h"

namespace r2
{
	r2cm::MenuUp STDNumericMenu::Create( r2cm::Director& director )
	{
		r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

		{
			ret->AddItem( '1', std_numeric_test::Accumulate_Number::GetInstance() );
			ret->AddItem( '2', std_numeric_test::Accumulate_String::GetInstance() );
			ret->AddItem( '3', std_numeric_test::Partial_Sum::GetInstance() );
			ret->AddItem( '4', std_numeric_test::FillSequenceNumber::GetInstance() );


			ret->AddSplit();


			ret->AddItem(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->r2cm::eTestEndAction
				{
					director.Setup( r2::STDMenu::Create( director ) );
					return r2cm::eTestEndAction::None;
				}
			);
		}

		return ret;
	}
}