#include "menu_math.h"

#include "r2tm/r2tm_MenuProcessor.h"

#include "RootMenu.h"

#include "test_angle.h"

r2tm::TitleFunctionT Menu_Math::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Math";
	};
}
r2tm::DescriptionFunctionT Menu_Math::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_Math::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', test_angle::Degree2Radian() );
		mp->AddItem( '2', test_angle::Radian2Degree() );
		mp->AddItem( '3', test_angle::Sine_Addition() );



		mp->AddSplit();



		mp->AddMenu( 27, RootMenu() );
	};
}