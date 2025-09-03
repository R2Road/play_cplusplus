#include "menu_std_file_system.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_std_filesystem.hpp"

#include "menu_std.hpp"

r2tm::TitleFunctionT Menu_STDFileSystem::GetTitleFunction() const
{
	return []()->const char*
	{
		return "<filesystem>";
	};
}
r2tm::DescriptionFunctionT Menu_STDFileSystem::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_STDFileSystem::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_std_filesystem::DirectoryPath() );
		mp->AddItem( '2', play_std_filesystem::DirectoryIterator() );
		mp->AddItem( '3', play_std_filesystem::RecursiveDirectoryIterator() );



		mp->AddLineFeed();



		mp->AddItem( 'q', play_std_filesystem::PathOperation_1() );
		mp->AddItem( 'w', play_std_filesystem::PathOperation_2() );
		mp->AddItem( 'e', play_std_filesystem::PathOperation_3() );
		mp->AddItem( 'r', play_std_filesystem::PathOperation_4() );



		mp->AddLineFeed();



		mp->AddItem( 'a', play_std_filesystem::Exist() );
		mp->AddItem( 's', play_std_filesystem::Directory_Make_Delete() );
		mp->AddItem( 'd', play_std_filesystem::Directories_Make() );



		mp->AddLineFeed();



		mp->AddItem( 'z', play_std_filesystem::FileStatus() );



		mp->AddSplit();


		mp->AddMenu( 27, Menu_STD() );
	};
}