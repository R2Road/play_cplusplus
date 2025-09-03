#include "menu_debug.h"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_debug.h"

#include "menu_root.hpp"

r2tm::TitleFunctionT Menu_Debug::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Debug";
	};
}
r2tm::DescriptionFunctionT Menu_Debug::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_Debug::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_debug::PredefinedMacro() );
		mp->AddItem( '2', play_debug::OutPutDebugString() );
		mp->AddItem( '3', play_debug::Assertion() );
		mp->AddItem( '4', play_debug::DebugBreak() );
		mp->AddItem( '5', play_debug::MyAssertion() );
		mp->AddItem( '6', play_debug::SimpleLog() );



		mp->AddSplit();



		mp->AddMenu( 27, Menu_Root() );
	};
}