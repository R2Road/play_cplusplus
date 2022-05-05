#include "pch.h"
#include "r2_STDThreadMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_eTestEndAction.h"
#include "r2_STDMenu.h"

#include "test_cpp/item/atomic_test.h"
#include "test_cpp/item/std_thread_test.h"

namespace r2
{
	r2cm::MenuUp STDThreadMenu::Create( r2cm::Director& director )
	{
		r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

		{
			ret->AddItem( '1', std_thread_test::Basic::GetInstance() );
			ret->AddItem( '2', std_thread_test::Declaration::GetInstance() );
			ret->AddItem( '3', std_thread_test::CopyAssaignment::GetInstance() );
			ret->AddItem( '4', std_thread_test::WaitProcess_SleepFor::GetInstance() );
			ret->AddItem( '5', std_thread_test::WaitProcess_Yield::GetInstance() );


			ret->AddSplit();


			ret->AddItem( 'q', atomic_test::IsLockFree::GetInstance() );
			ret->AddItem( 'w', atomic_test::LockFreeTest1::GetInstance() );
			ret->AddItem( 'e', atomic_test::LockFreeTest2::GetInstance() );


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