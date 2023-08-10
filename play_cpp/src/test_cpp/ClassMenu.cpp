#include "ClassMenu.h"

#include "r2tm/r2tm_Director.h"

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
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', cpp_class_test::Method() );
		ret->AddItem( '2', cpp_class_test::MemberValue() );
		ret->AddItem( '3', cpp_class_test::Braces_1() );
		ret->AddItem( '4', cpp_class_test::Braces_2() );
		ret->AddItem( '5', cpp_class_test::PrintName() );
		ret->AddItem( '6', cpp_class_test::ImplicitTypeConversion() );



		ret->AddLineFeed();



		ret->AddItem( 'q', cpp_class_private_inheritance_test::VirtualInterface() );
		ret->AddItem( 'w', cpp_class_private_inheritance_test::PureVirtualInterface() );
		ret->AddItem( 'e', cpp_class_private_inheritance_test::Demo1() );
		ret->AddItem( 'r', cpp_class_private_inheritance_test::Using() );
		ret->AddItem( 't', cpp_class_private_inheritance_test::PrivateInheritance_iEnum() );
		ret->AddItem( 'y', cpp_class_private_inheritance_test::NoneVirtualInterface() );



		ret->AddLineFeed();



		ret->AddItem( 'a', cpp_class_test::MemberAdress_Value() );
		ret->AddItem( 's', cpp_class_test::MemberAdress_Method() );
		ret->AddItem( 'd', cpp_class_test::Offset_SingleInheritance() );
		ret->AddItem( 'f', cpp_class_test::Offset_MultipleInheritance() );
		ret->AddItem( 'g', cpp_class_test::Offset_Singleton() );
		ret->AddItem( 'h', cpp_class_test::Size_And_Byte() );
		ret->AddItem( 'j', cpp_class_test::Size_With_Enum() );



		ret->AddSplit();


		ret->AddMenu( 27, CPP_Menu() );
	};
}