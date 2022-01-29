#include "pch.h"
#include "r2_ThreadMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestResult.h"
#include "r2_RootMenu.h"

#include "test_cpp/atomic_test.h"
#include "test_cpp/std_thread_test.h"

namespace r2
{
	MenuUp ThreadMenu::Create( Director& director )
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
				, [&director]()->eTestResult
				{
					director.Setup( r2::RootMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);
		}

		return ret;
	}
}