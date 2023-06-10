#include "MathMenu.h"

#include "r2tm/r2tm_Director.h"

#include "RootMenu.h"

r2tm::TitleFunctionT MathMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Math";
	};
}
r2tm::DescriptionFunctionT MathMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT MathMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddSplit();


		ret->AddMenu( 27, RootMenu() );
	};
}