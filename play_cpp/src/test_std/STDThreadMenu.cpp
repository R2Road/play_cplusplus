#include "STDThreadMenu.h"

#include "r2tm/r2tm_MenuProcessor.h"

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
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', std_thread_test::Declaration_1() );
		mp->AddItem( '2', std_thread_test::Declaration_2() );
		mp->AddItem( '3', std_thread_test::Declaration_3() );
		mp->AddItem( '4', std_thread_test::Demo() );



		mp->AddLineFeed();



		mp->AddItem( 'q', std_thread_test::CopyAssaignment() );
		mp->AddItem( 'w', std_thread_test::WaitProcess_SleepFor() );
		mp->AddItem( 'e', std_thread_test::WaitProcess_Yield() );



		mp->AddLineFeed();



		mp->AddItem( 'a', std_atomic_test::Declaration_1() );
		mp->AddItem( 's', std_atomic_test::Declaration_2() );
		mp->AddItem( 'd', std_atomic_test::IsLockFree() );
		mp->AddItem( 'f', std_atomic_test::LockFreeTest1() );
		mp->AddItem( 'g', std_atomic_test::LockFreeTest2() );



		mp->AddSplit();



		mp->AddMenu( 27, STDMenu() );
	};
}