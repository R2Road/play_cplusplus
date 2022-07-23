#include "STDThreadMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "test_cpp/item/atomic_test.h"
#include "test_std/item/std_thread_test.h"

#include "STDMenu.h"

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


		ret->AddMenu<STDMenu>( 27 );
	}

	return ret;
}