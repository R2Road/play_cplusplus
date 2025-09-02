#include "menu_c.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_c_array.hpp"
#include "play_c_atexit.hpp"
#include "play_c_printf.hpp"
#include "play_c_macro.hpp"
#include "play_c_memset.hpp"
#include "play_c_sizeof.hpp"
#include "play_c_struct.hpp"
#include "play_c_system.hpp"
#include "play_c_union.hpp"

#include "menu_c_bit_operation.hpp"
#include "menu_c_file.hpp"
#include "menu_c_operator.hpp"
#include "menu_c_pointer.hpp"
#include "menu_c_union.hpp"

#include "menu_root.hpp"

r2tm::TitleFunctionT Menu_C::GetTitleFunction() const
{
	return []()->const char*
	{
		return "C";
	};
}
r2tm::DescriptionFunctionT Menu_C::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_C::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_c_array::Init() );
		mp->AddItem( '2', play_c_array::Address() );
		mp->AddMenu( '3', Menu_C_Operator() );
		mp->AddItem( '4', play_c_struct::ByteAlignment() );
		mp->AddItem( '5', play_c_struct::PragmaPack() );
		mp->AddItem( '6', play_c_struct::Array_Size_0() );
		


		mp->AddLineFeed();


		mp->AddItem( '9', play_c_printf::Basic() );
		mp->AddItem( '0', play_c_printf::ShowNumbers() );


		mp->AddLineFeed();


		mp->AddItem( 'q', play_c_sizeof::Basic() );
		mp->AddItem( 'w', play_c_memset::Basic() );
		mp->AddItem( 'e', play_c_memset::Size() );
		mp->AddItem( 'r', play_c_macro::ToString() );


		mp->AddLineFeed();


		mp->AddMenu( 'a', Menu_C_Pointer() );
		mp->AddMenu( 's', Menu_C_BitOperation() );
		mp->AddMenu( 'd', Menu_C_Union() );
		mp->AddItem( 'f', play_c_system::Pause() );
		mp->AddItem( 'g', play_c_atexit::Basic() );


		mp->AddLineFeed();


		mp->AddMenu( 'z', Menu_C_File() );



		mp->AddSplit();


		mp->AddMenu( 27, Menu_Root() );
	};
}