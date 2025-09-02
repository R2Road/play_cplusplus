#include "menu_std_memory.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_std_memory_shared_ptr.hpp"
#include "play_std_memory_unique_ptr.hpp"

#include "menu_std_align.hpp"

#include "menu_std.hpp"

r2tm::TitleFunctionT STDMemoryMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "<memory>";
	};
}
r2tm::DescriptionFunctionT STDMemoryMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT STDMemoryMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_std_memory_unique_ptr::Basic() );
		mp->AddItem( '2', play_std_memory_unique_ptr::Size() );
		mp->AddItem( '3', play_std_memory_unique_ptr::Binary() );
		mp->AddItem( '4', play_std_memory_unique_ptr::Deleter() );
		mp->AddItem( '5', play_std_memory_unique_ptr::TemplateDeleter() );
		mp->AddItem( '6', play_std_memory_unique_ptr::FowardDeclaration() );



		mp->AddLineFeed();



		mp->AddItem( 'q', play_std_memory_shared_ptr::Basic() );
		mp->AddItem( 'w', play_std_memory_shared_ptr::Size() );
		mp->AddItem( 'e', play_std_memory_shared_ptr::Binary() );
		mp->AddItem( 'r', play_std_memory_shared_ptr::MakeShared_And_Memory() );



		mp->AddLineFeed();



		mp->AddMenu( 'z', STDAlignMenu() );



		mp->AddSplit();



		mp->AddMenu( 27, STDMenu() );
	};
}