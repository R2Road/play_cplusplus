#include "menu_std_thread.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_std_atomic.hpp"
#include "play_std_thread.hpp"

#include "menu_std.hpp"

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
		mp->AddItem( '1', play_std_thread::Declaration_1() );
		mp->AddItem( '2', play_std_thread::Declaration_2() );
		mp->AddItem( '3', play_std_thread::Declaration_3() );
		mp->AddItem( '4', play_std_thread::Demo() );



		mp->AddLineFeed();



		mp->AddItem( 'q', play_std_thread::CopyAssaignment() );
		mp->AddItem( 'w', play_std_thread::WaitProcess_SleepFor() );
		mp->AddItem( 'e', play_std_thread::WaitProcess_Yield() );



		mp->AddLineFeed();



		mp->AddItem( 'a', play_std_atomic::Declaration_1() );
		mp->AddItem( 's', play_std_atomic::Declaration_2() );
		mp->AddItem( 'd', play_std_atomic::IsLockFree() );
		mp->AddItem( 'f', play_std_atomic::LockFreeTest1() );
		mp->AddItem( 'g', play_std_atomic::LockFreeTest2() );



		mp->AddSplit();



		mp->AddMenu( 27, STDMenu() );
	};
}