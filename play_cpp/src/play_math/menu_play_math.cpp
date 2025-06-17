#include "menu_play_math.h"

#include "r2tm/r2tm_MenuProcessor.h"

#include "menu_root.h"

#include "play_math_basic.h"

r2tm::TitleFunctionT Menu_Math::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Play Math";
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
		mp->AddItem( '1', play_math_basic::Degree2Radian() );
		mp->AddItem( '2', play_math_basic::Radian2Degree() );
		mp->AddItem( '3', play_math_basic::Sine_Addition() );



		mp->AddSplit();



		mp->AddMenu( 27, RootMenu() );
	};
}