#include "ClassMenu.h"

#include "r2tm/r2tm_MenuProcessor.h"

#include "item/cpp_class_test.h"
#include "item/cpp_class_private_inheritance_test.h"

#include "CPP_Menu.h"

r2tm::TitleFunctionT ClassMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Class";
	};
}
r2tm::DescriptionFunctionT ClassMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT ClassMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', cpp_class_test::Method() );
		mp->AddItem( '2', cpp_class_test::MemberValue() );
		mp->AddItem( '3', cpp_class_test::Braces_1() );
		mp->AddItem( '4', cpp_class_test::Braces_2() );
		mp->AddItem( '5', cpp_class_test::Braces_3() );
		mp->AddItem( '6', cpp_class_test::PrintName() );
		mp->AddItem( '7', cpp_class_test::ImplicitTypeConversion() );



		mp->AddLineFeed();



		mp->AddItem( 'q', cpp_class_private_inheritance_test::VirtualInterface() );
		mp->AddItem( 'w', cpp_class_private_inheritance_test::PureVirtualInterface() );
		mp->AddItem( 'e', cpp_class_private_inheritance_test::Demo1() );
		mp->AddItem( 'r', cpp_class_private_inheritance_test::Using() );
		mp->AddItem( 't', cpp_class_private_inheritance_test::PrivateInheritance_iEnum() );
		mp->AddItem( 'y', cpp_class_private_inheritance_test::NoneVirtualInterface() );



		mp->AddLineFeed();



		mp->AddItem( 'a', cpp_class_test::MemberAdress_Value() );
		mp->AddItem( 's', cpp_class_test::MemberAdress_Method() );
		mp->AddItem( 'd', cpp_class_test::Offset_SingleInheritance() );
		mp->AddItem( 'f', cpp_class_test::Offset_MultipleInheritance_1() );
		mp->AddItem( 'g', cpp_class_test::Offset_MultipleInheritance_2() );
		mp->AddItem( 'h', cpp_class_test::Offset_Singleton() );



		mp->AddLineFeed();



		mp->AddItem( 'z', cpp_class_test::Size_And_Byte_1() );
		mp->AddItem( 'x', cpp_class_test::Size_And_Byte_2() );
		mp->AddItem( 'c', cpp_class_test::Size_And_Byte_3() );
		mp->AddItem( 'v', cpp_class_test::Size_With_Enum() );



		mp->AddSplit();


		mp->AddMenu( 27, CPP_Menu() );
	};
}