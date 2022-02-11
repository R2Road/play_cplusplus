#include "pch.h"
#include "r2_STDContainerMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestEndAction.h"
#include "r2_STDMenu.h"

#include "test_cpp/std_array_test.h"
#include "test_cpp/std_list_test.h"
#include "test_cpp/std_vector_test.h"

namespace r2
{
	MenuUp STDContainerMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddChild( '1', std_array_test::Basic::GetInstance() );
			ret->AddChild( '2', std_array_test::Fill::GetInstance() );


			ret->AddLineFeed();


			ret->AddChild( 'q', std_list_test::Splice::GetInstance() );
			ret->AddChild( 'w', std_list_test::OthersIterator::GetInstance() );
			ret->AddChild( 'e', std_list_test::EndIterator::GetInstance() );


			ret->AddLineFeed();


			ret->AddChild( 'a', std_vector_test::Basic::GetInstance() );
			ret->AddChild( 's', std_vector_test::NoneDefaultConstructor::GetInstance() );
			ret->AddChild( 'd', std_vector_test::BoolVector::GetInstance() );
			ret->AddChild( 'f', std_vector_test::OthersIterator::GetInstance() );
			ret->AddChild( 'g', std_vector_test::EndIterator::GetInstance() );


			ret->AddSplit();


			ret->AddChild(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->eTestEndAction
				{
					director.Setup( r2::STDMenu::Create( director ) );
					return eTestEndAction::ChangeScene;
				}
			);
		}

		return ret;
	}
}