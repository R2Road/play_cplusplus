#include "menu_template_meta_programming.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_template_meta_programming_01.hpp"
#include "play_template_meta_programming_02.hpp"
#include "play_template_meta_programming_03.hpp"

#include "menu_template.hpp"

r2tm::TitleFunctionT Menu_TemplateMetaProgramming::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Template Meta Programming";
	};
}
r2tm::DescriptionFunctionT Menu_TemplateMetaProgramming::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_TemplateMetaProgramming::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_template_meta_programming_01::Factorial() );
		mp->AddItem( '2', play_template_meta_programming_01::Factorial_Printer() );
		mp->AddItem( '3', play_template_meta_programming_01::GreatestCommonDivisor() );
		mp->AddItem( '4', play_template_meta_programming_01::GreatestCommonDivisor_ProcessPrinter() );



		mp->AddLineFeed();



		mp->AddItem( 'q', play_template_meta_programming_01::BasicRatio() );
		mp->AddItem( 'w', play_template_meta_programming_01::SumBasicRatio() );
		mp->AddItem( 'e', play_template_meta_programming_01::RatioWithGCD() );
		mp->AddItem( 'r', play_template_meta_programming_01::SumRatioWithGCD() );
		mp->AddItem( 't', play_template_meta_programming_01::SumRatioAndOperator1() );
		mp->AddItem( 'y', play_template_meta_programming_01::SumRatioAndOperator2() );



		mp->AddLineFeed();



		mp->AddItem( 'a', play_template_meta_programming_01::Character2String() );
		mp->AddItem( 's', play_template_meta_programming_01::Integer2String() );
		mp->AddItem( 'd', play_template_meta_programming_01::CalculatePlaceValue() );
		mp->AddItem( 'f', play_template_meta_programming_01::Integer2String_II() );



		mp->AddLineFeed();



		mp->AddItem( 'z', play_template_meta_programming_01::MultiTypePackage() );



		mp->AddSplit();



		mp->AddMenu( 27, Menu_Template() );
	};
}