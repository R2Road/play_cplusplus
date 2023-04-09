#include "STDThreadMenu.h"

#include "r2cm/r2cm_Director.h"

#include "test_std/item/std_atomic_test.h"
#include "test_std/item/std_thread_test.h"

#include "STDMenu.h"

r2cm::MenuUp STDThreadMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', std_thread_test::Basic() );
		ret->AddItem( '2', std_thread_test::Declaration() );
		ret->AddItem( '3', std_thread_test::CopyAssaignment() );
		ret->AddItem( '4', std_thread_test::WaitProcess_SleepFor() );
		ret->AddItem( '5', std_thread_test::WaitProcess_Yield() );
		ret->AddItem( '6', std_thread_test::ThisThread_SleepFor() );


		ret->AddSplit();


		ret->AddItem( 'q', std_atomic_test::IsLockFree() );
		ret->AddItem( 'w', std_atomic_test::LockFreeTest1() );
		ret->AddItem( 'e', std_atomic_test::LockFreeTest2() );


		ret->AddSplit();


		ret->AddMenu<STDMenu>( 27 );
	}

	return ret;
}