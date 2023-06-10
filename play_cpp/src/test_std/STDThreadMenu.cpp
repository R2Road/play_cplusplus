#include "STDThreadMenu.h"

#include "r2tm/r2tm_Director.h"

#include "test_std/item/std_atomic_test.h"
#include "test_std/item/std_thread_test.h"

#include "STDMenu.h"

r2tm::TitleFunctionT STDThreadMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Thread";
	};
}
r2tm::DescriptionFunctionT STDThreadMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT STDThreadMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* ret )
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


		ret->AddMenu( 27, STDMenu() );
	};
}