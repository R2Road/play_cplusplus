#include "menu_class.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_cpp_class.hpp"
#include "play_cpp_class_private_inheritance.hpp"

#include "menu_cpp.hpp"

r2tm::TitleFunctionT Menu_Class::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Class";
	};
}
r2tm::DescriptionFunctionT Menu_Class::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_Class::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_cpp_class::Method() );
		mp->AddItem( '2', play_cpp_class::MemberValue() );
		mp->AddItem( '3', play_cpp_class::Braces_1() );
		mp->AddItem( '4', play_cpp_class::Braces_2() );
		mp->AddItem( '5', play_cpp_class::Braces_3() );
		mp->AddItem( '6', play_cpp_class::PrintName() );
		mp->AddItem( '7', play_cpp_class::ImplicitTypeConversion() );



		mp->AddLineFeed();



		mp->AddItem( 'q', play_cpp_class_private_inheritance::VirtualInterface() );
		mp->AddItem( 'w', play_cpp_class_private_inheritance::PureVirtualInterface() );
		mp->AddItem( 'e', play_cpp_class_private_inheritance::Demo1() );
		mp->AddItem( 'r', play_cpp_class_private_inheritance::Using() );
		mp->AddItem( 't', play_cpp_class_private_inheritance::PrivateInheritance_iEnum() );
		mp->AddItem( 'y', play_cpp_class_private_inheritance::NoneVirtualInterface() );



		mp->AddLineFeed();



		mp->AddItem( 'a', play_cpp_class::MemberAdress_Value() );
		mp->AddItem( 's', play_cpp_class::MemberAdress_Method() );
		mp->AddItem( 'd', play_cpp_class::Offset_SingleInheritance() );
		mp->AddItem( 'f', play_cpp_class::Offset_MultipleInheritance_1() );
		mp->AddItem( 'g', play_cpp_class::Offset_MultipleInheritance_2() );
		mp->AddItem( 'h', play_cpp_class::Offset_Singleton() );



		mp->AddLineFeed();



		mp->AddItem( 'z', play_cpp_class::Size_And_Byte_1() );
		mp->AddItem( 'x', play_cpp_class::Size_And_Byte_2() );
		mp->AddItem( 'c', play_cpp_class::Size_And_Byte_3() );
		mp->AddItem( 'v', play_cpp_class::Size_With_Enum() );



		mp->AddSplit();


		mp->AddMenu( 27, Menu_CPP() );
	};
}