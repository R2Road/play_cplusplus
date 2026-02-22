#include "menu_cpp.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_cpp_structured_binding.hpp"
#include "play_cpp_number.hpp"
#include "play_cpp_using.hpp"
#include "play_cpp_braces.hpp"
#include "play_cpp_noexcept.hpp"

#include "menu_align.hpp"
#include "menu_decltype.hpp"
#include "menu_enum.hpp"
#include "menu_lambda.hpp"
#include "menu_namespace.hpp"
#include "menu_new.hpp"

#include "menu_char.hpp"
#include "menu_class.hpp"
#include "menu_root.hpp"

r2tm::TitleFunctionT Menu_CPP::GetTitleFunction() const
{
	return []()->const char*
	{
		return "CPP";
	};
}
r2tm::DescriptionFunctionT Menu_CPP::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_CPP::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddMenu( '1', Menu_Class() );
		mp->AddMenu( '2', Menu_NameSpace() );
		mp->AddItem( '3', play_cpp_braces::Braces_PrimitiveType() );
		mp->AddMenu( '4', Menu_Decltype() );
		mp->AddItem( '5', play_cpp_noexcept::Basic() );
		


		mp->AddLineFeed();


		mp->AddMenu( 'q', Menu_Char() );
		mp->AddMenu( 'w', Menu_Align() );
		mp->AddMenu( 'e', EnumMenu() );


		mp->AddLineFeed();


		mp->AddMenu( 'a', Menu_New() );
		mp->AddMenu( 's', menu_lambda() );
		mp->AddItem( 'd', play_cpp_using::Basic() );


		mp->AddLineFeed();


		mp->AddItem( 'z', play_cpp_structured_binding::Basic() );
		mp->AddItem( 'x', play_cpp_number::Prefix() );


		mp->AddSplit();


		mp->AddMenu( 27, Menu_Root() );
	};
}