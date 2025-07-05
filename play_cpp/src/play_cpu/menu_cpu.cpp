#include "menu_cpu.h"

#include "r2tm/r2tm_MenuProcessor.h"

#include "play_cpu_basic.h"

#include "menu_root.h"

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
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', test_cpu_basic::CoreInformation() );
		mp->AddItem( '2', test_cpu_basic::CacheInformation() );


		mp->AddSplit();


		mp->AddMenu( 27, Menu_Root() );
	};
}