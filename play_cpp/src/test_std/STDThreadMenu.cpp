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
		ret->AddItem( '1', std_thread_test::Declaration_1() );
		ret->AddItem( '2', std_thread_test::Declaration_2() );
		ret->AddItem( '3', std_thread_test::Declaration_3() );
		ret->AddItem( '4', std_thread_test::Demo() );



		ret->AddLineFeed();



		ret->AddItem( 'q', std_thread_test::CopyAssaignment() );
		ret->AddItem( 'w', std_thread_test::WaitProcess_SleepFor() );
		ret->AddItem( 'e', std_thread_test::WaitProcess_Yield() );



		ret->AddLineFeed();



		ret->AddItem( 'a', std_atomic_test::Declaration() );
		ret->AddItem( 's', std_atomic_test::IsLockFree() );
		ret->AddItem( 'd', std_atomic_test::LockFreeTest1() );
		ret->AddItem( 'f', std_atomic_test::LockFreeTest2() );



		ret->AddSplit();



		ret->AddMenu( 27, STDMenu() );
	};
}