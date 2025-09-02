#include "menu_std_functional.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_std_function.hpp"
#include "play_std_function_2.hpp"
#include "play_std_functional_hash.hpp"
#include "play_std_functional_invoke.hpp"
#include "play_std_functional_mem_fn.hpp"

#include "menu_std.hpp"

r2tm::TitleFunctionT STDFunctionalMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "<functional>";
	};
}
r2tm::DescriptionFunctionT STDFunctionalMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT STDFunctionalMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_std_functional_invoke::Basic() );



		mp->AddLineFeed();



		mp->AddItem( '6', play_std_functional_mem_fn::Basic() );



		mp->AddLineFeed();



		mp->AddItem( 'q', play_std_function::Basic() );



		mp->AddLineFeed();



		mp->AddItem( 'w', play_std_function::Equality_FunctionPointer_1() );
		mp->AddItem( 'e', play_std_function::Equality_FunctionPointer_2() );
		mp->AddItem( 'r', play_std_function::Equality_FunctionPointer_3() );
		mp->AddItem( 't', play_std_function_2::Equality_STDBind_1() );
		mp->AddItem( 'y', play_std_function::Equality_Lambda_1() );



		mp->AddLineFeed();



		mp->AddItem( 'a', play_std_functional_hash::Basic() );
		mp->AddItem( 's', play_std_functional_hash::CString() );



		mp->AddSplit();



		mp->AddMenu( 27, STDMenu() );
	};
}