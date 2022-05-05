#include "pch.h"
#include "r2_STDContainerMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_eTestEndAction.h"

#include "test_cpp/item/std_array_test.h"
#include "test_cpp/item/std_list_test.h"
#include "test_cpp/item/std_vector_test.h"

#include "STDMenu.h"

namespace r2
{
	r2cm::MenuUp STDContainerMenu::Create( r2cm::Director& director )
	{
		r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

		{
			ret->AddItem( '1', std_array_test::Basic::GetInstance() );
			ret->AddItem( '2', std_array_test::Fill::GetInstance() );
			ret->AddItem( '3', std_array_test::Copy::GetInstance() );


			ret->AddLineFeed();


			ret->AddItem( 'q', std_list_test::Splice::GetInstance() );
			ret->AddItem( 'w', std_list_test::OthersIterator::GetInstance() );
			ret->AddItem( 'e', std_list_test::EndIterator::GetInstance() );


			ret->AddLineFeed();


			ret->AddItem( 'a', std_vector_test::Basic::GetInstance() );
			ret->AddItem( 's', std_vector_test::NoneDefaultConstructor::GetInstance() );
			ret->AddItem( 'd', std_vector_test::BoolVector::GetInstance() );
			ret->AddItem( 'f', std_vector_test::OthersIterator::GetInstance() );
			ret->AddItem( 'g', std_vector_test::EndIterator::GetInstance() );


			ret->AddSplit();


			ret->AddItem(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->r2cm::eTestEndAction
				{
					director.Setup( STDMenu::Create( director ) );
					return r2cm::eTestEndAction::None;
				}
			);
		}

		return ret;
	}
}