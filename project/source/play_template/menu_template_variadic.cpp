#include "menu_template_variadic.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_template_variadic.hpp"

#include "menu_template.hpp"

r2tm::TitleFunctionT Menu_TemplateVariadic::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Variadic";
	};
}
r2tm::DescriptionFunctionT Menu_TemplateVariadic::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_TemplateVariadic::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_template_variadic::SizeOfArgs() );
		mp->AddItem( '2', play_template_variadic::PrintValues() );
		mp->AddItem( '3', play_template_variadic::SumValues() );
		mp->AddItem( '4', play_template_variadic::SubtractValues() );


		mp->AddLineFeed();
		mp->AddLineFeed();


		mp->AddItem( 'a', play_template_variadic::Test() );


		mp->AddSplit();


		mp->AddMenu( 27, Menu_Template() );
	};
}