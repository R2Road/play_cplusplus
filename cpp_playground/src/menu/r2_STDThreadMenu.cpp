#include "pch.h"
#include "r2_STDThreadMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestEndAction.h"
#include "r2_STDMenu.h"

#include "test_cpp/atomic_test.h"
#include "test_cpp/std_thread_test.h"

namespace r2
{
	MenuUp STDThreadMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddChild( '1', std_thread_test::Basic::GetInstance() );
			ret->AddChild( '2', std_thread_test::Declaration::GetInstance() );
			ret->AddChild( '3', std_thread_test::CopyAssaignment::GetInstance() );
			ret->AddChild( '4', std_thread_test::WaitProcess_SleepFor::GetInstance() );
			ret->AddChild( '5', std_thread_test::WaitProcess_Yield::GetInstance() );


			ret->AddSplit();


			ret->AddChild( 'q', atomic_test::IsLockFree::GetInstance() );
			ret->AddChild( 'w', atomic_test::LockFreeTest1::GetInstance() );
			ret->AddChild( 'e', atomic_test::LockFreeTest2::GetInstance() );


			ret->AddSplit();


			ret->AddChild(
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