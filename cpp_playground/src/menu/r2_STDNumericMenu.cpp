#include "pch.h"
#include "r2_STDNumericMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestEndAction.h"
#include "r2_STDMenu.h"

#include "test_cpp/std_numeric_test.h"

namespace r2
{
	MenuUp STDNumericMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddItem( '1', std_numeric_test::Accumulate_Number::GetInstance() );
			ret->AddItem( '2', std_numeric_test::Accumulate_String::GetInstance() );
			ret->AddItem( '3', std_numeric_test::Partial_Sum::GetInstance() );
			ret->AddItem( '4', std_numeric_test::FillSequenceNumber::GetInstance() );


			ret->AddSplit();


			ret->AddItem(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->eTestEndAction
				{
					director.Setup( r2::STDMenu::Create( director ) );
					return r2::eTestEndAction::None;
				}
			);
		}

		return ret;
	}
}