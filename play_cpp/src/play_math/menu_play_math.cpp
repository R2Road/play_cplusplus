#include "menu_play_math.h"

#include "r2tm/r2tm_MenuProcessor.h"

#include "menu_root.h"

#include "play_math_basic.h"
#include "play_math_vector2_transform.h"
#include "play_math_vector3.h"
#include "play_math_vector3_transform.h"

r2tm::TitleFunctionT Menu_Play_Math::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Math";
	};
}
r2tm::DescriptionFunctionT Menu_Play_Math::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_Play_Math::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_math_vector3_transform::Need() );



		mp->AddLineFeed();



		mp->AddItem( '2', play_math_basic::Degree2Radian() );
		mp->AddItem( '3', play_math_basic::Radian2Degree() );
		mp->AddItem( '4', play_math_basic::Sine_Addition() );



		mp->AddLineFeed();



		mp->AddItem( 'q', play_math_vector3::Length() );
		mp->AddItem( 'w', play_math_vector3::Normalize() );
		mp->AddItem( 'e', play_math_vector3::Dot_Product_1() );
		mp->AddItem( 'r', play_math_vector3::Dot_Product_2() );
		mp->AddItem( 't', play_math_vector3::Dot_Product__Scalar_Projection() );
		mp->AddItem( 'y', play_math_vector3::Dot_Product__Vector_Projection() );
		mp->AddItem( 'u', play_math_vector3::Angle_Between_Two_Vectors() );
		mp->AddItem( 'i', play_math_vector3::Angle_Between_Two_Unit_Vectors() );
		mp->AddItem( 'o', play_math_vector3::Cross_Product() );



		mp->AddLineFeed();



		mp->AddItem( 'a', play_math_vector2_transform::Rotation_X__Basic() );
		mp->AddItem( 's', play_math_vector2_transform::Rotation_X() );
		mp->AddItem( 'd', play_math_vector3_transform::Rotation_XZ() );
		mp->AddItem( 'f', play_math_vector3_transform::Rotation_Y() );



		mp->AddSplit();



		mp->AddMenu( 27, Menu_Root() );
	};
}