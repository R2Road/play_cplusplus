#include "menu_play_math_geometry.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "menu_play_math.hpp"

#include "play_math_quaternion.hpp"
#include "play_math_vector2_transform.hpp"
#include "play_math_vector3.hpp"
#include "play_math_vector3_transform.hpp"

r2tm::TitleFunctionT Menu_Play_Math_Geomrtry::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Geometry";
	};
}
r2tm::DescriptionFunctionT Menu_Play_Math_Geomrtry::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_Play_Math_Geomrtry::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_math_vector3::Length() );
		mp->AddItem( '2', play_math_vector3::Normalize() );
		mp->AddItem( '3', play_math_vector3::Dot_Product_1() );
		mp->AddItem( '4', play_math_vector3::Dot_Product_2() );
		mp->AddItem( '5', play_math_vector3::Dot_Product__Scalar_Projection() );
		mp->AddItem( '6', play_math_vector3::Dot_Product__Vector_Projection() );
		mp->AddItem( '7', play_math_vector3::Angle_Between_Two_Vectors() );
		mp->AddItem( '8', play_math_vector3::Angle_Between_Two_Unit_Vectors() );
		mp->AddItem( '9', play_math_vector3::Cross_Product() );



		mp->AddLineFeed();



		mp->AddItem( 'q', play_math_vector2_transform::Rotation_X__Basic() );
		mp->AddItem( 'w', play_math_vector2_transform::Rotation_X() );
		mp->AddItem( 'e', play_math_vector3_transform::Rotation_XZ() );
		mp->AddItem( 'r', play_math_vector3_transform::Rotation_Y() );



		mp->AddLineFeed();



		mp->AddItem( 'a', play_math_quaternion::Basic() );
		mp->AddItem( 's', play_math_quaternion::Length() );
		mp->AddItem( 'd', play_math_quaternion::Normalize() );
		mp->AddItem( 'f', play_math_quaternion::Inverse() );
		mp->AddItem( 'g', play_math_quaternion::Multiply() );
		mp->AddItem( 'h', play_math_quaternion::Rotation() );
		mp->AddItem( 'j', play_math_quaternion::Convert_2_Matrix() );



		mp->AddSplit();



		mp->AddMenu( 27, Menu_Play_Math() );
	};
}