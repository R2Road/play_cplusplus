#include "pch.h"
#include "r2_STDContainerMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestResult.h"
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
			ret->AddChild( '3', std_list_test::Splice::GetInstance() );
			ret->AddChild( '4', std_list_test::OthersIterator::GetInstance() );
			ret->AddChild( '5', std_vector_test::Basic::GetInstance() );
			ret->AddChild( '6', std_vector_test::BoolVector::GetInstance() );
			ret->AddChild( '7', std_vector_test::OthersIterator::GetInstance() );


			ret->AddSplit();


			ret->AddChild(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->eTestResult
				{
					director.Setup( r2::STDMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);
		}

		return ret;
	}
}