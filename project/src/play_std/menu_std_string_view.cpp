#include "menu_std_string_view.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_std_string_view.hpp"

#include "menu_std.hpp"

r2tm::TitleFunctionT Menu_STDStringView::GetTitleFunction() const
{
	return []()->const char*
	{
		return "<string_view>";
	};
}
r2tm::DescriptionFunctionT Menu_STDStringView::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_STDStringView::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_std_string_view::Declaration() );
		mp->AddItem( '2', play_std_string_view::Iteration() );
		mp->AddItem( '3', play_std_string_view::Literal_Operator_sv() );
		mp->AddItem( '4', play_std_string_view::Remove() );
		mp->AddItem( '5', play_std_string_view::SubStr() );



		mp->AddSplit();



		mp->AddMenu( 27, Menu_STD() );
	};
}