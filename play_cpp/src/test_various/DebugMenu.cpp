#include "DebugMenu.h"

#include "r2tm/r2tm_Director.h"

#include "item/various_debug_test.h"

#include "RootMenu.h"

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
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', various_debug_test::PredefinedMacro() );
		ret->AddItem( '2', various_debug_test::OutPutDebugString() );
		ret->AddItem( '3', various_debug_test::Assertion() );
		ret->AddItem( '4', various_debug_test::DebugBreak() );
		ret->AddItem( '5', various_debug_test::MyAssertion() );
		ret->AddItem( '6', various_debug_test::SimpleLog() );



		ret->AddSplit();



		ret->AddMenu( 27, RootMenu() );
	};
}