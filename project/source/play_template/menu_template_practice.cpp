#include "menu_template_practice.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_template_practice_part_01.hpp"

#include "menu_template.hpp"

r2tm::TitleFunctionT Menu_TemplatePractice::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Template Practice";
	};
}
r2tm::DescriptionFunctionT Menu_TemplatePractice::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_TemplatePractice::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_template_practice_part_01::BufferWithTemplate() );
		mp->AddItem( '2', play_template_practice_part_01::VaridicMax() );


		mp->AddSplit();


		mp->AddMenu( 27, Menu_Template() );
	};
}