#include "menu_play_math.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "menu_root.hpp"

#include "play_math_basic.hpp"
#include "play_math_numbers.hpp"
#include "play_math_sequence.hpp"

#include "menu_play_math_geometry.hpp"

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
		mp->AddItem( '1', play_math_numbers::_1() );



		mp->AddLineFeed();



		mp->AddItem( '2', play_math_basic::Degree2Radian() );
		mp->AddItem( '3', play_math_basic::Radian2Degree() );
		mp->AddItem( '4', play_math_basic::Sine_Addition() );



		mp->AddLineFeed();



		mp->AddItem( 'q', play_math_sequence::ArithmeticSequence_Sum() );



		mp->AddLineFeed();



		mp->AddMenu( 'z', Menu_Play_Math_Geomrtry() );



		mp->AddSplit();



		mp->AddMenu( 27, Menu_Root() );
	};
}