#include "DebugMenu.h"

#include "r2tm/r2tm_MenuProcessor.h"

#include "item/various_debug_test.h"

#include "menu_root.h"

r2tm::TitleFunctionT DebugMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Debug";
	};
}
r2tm::DescriptionFunctionT DebugMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT DebugMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', various_debug_test::PredefinedMacro() );
		mp->AddItem( '2', various_debug_test::OutPutDebugString() );
		mp->AddItem( '3', various_debug_test::Assertion() );
		mp->AddItem( '4', various_debug_test::DebugBreak() );
		mp->AddItem( '5', various_debug_test::MyAssertion() );
		mp->AddItem( '6', various_debug_test::SimpleLog() );



		mp->AddSplit();



		mp->AddMenu( 27, RootMenu() );
	};
}