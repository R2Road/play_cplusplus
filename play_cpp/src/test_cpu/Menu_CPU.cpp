#include "Menu_CPU.h"

#include "r2tm/r2tm_Director.h"

#include "test_cpu_basic.h"

#include "RootMenu.h"

r2tm::TitleFunctionT Menu_CPU::GetTitleFunction() const
{
	return []()->const char*
	{
		return "CPU";
	};
}
r2tm::DescriptionFunctionT Menu_CPU::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_CPU::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', test_cpu_basic::Test() );


		ret->AddSplit();


		ret->AddMenu( 27, RootMenu() );
	};
}