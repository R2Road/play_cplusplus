#include "ClassMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "item/cpp_class_test.h"
#include "item/cpp_class_private_inheritance_test.h"

#include "CPP_Menu.h"

r2cm::MenuUp ClassMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', cpp_class_test::Method::GetInstance() );
		ret->AddItem( '2', cpp_class_test::MemberValue::GetInstance() );
		ret->AddItem( '3', cpp_class_test::Braces::GetInstance() );
		ret->AddItem( '4', cpp_class_test::PrintName::GetInstance() );
		ret->AddItem( '5', cpp_class_test::ImplicitTypeConversion::GetInstance() );



		ret->AddLineFeed();



		ret->AddItem( 'q', cpp_class_private_inheritance_test::PrivateInheritance_1::GetInstance() );
		ret->AddItem( 'w', cpp_class_private_inheritance_test::PrivateInheritance_2::GetInstance() );
		ret->AddItem( 'e', cpp_class_private_inheritance_test::PrivateInheritance_iEnum::GetInstance() );
		ret->AddItem( 'r', cpp_class_private_inheritance_test::NoneVirtualInterface::GetInstance() );



		ret->AddLineFeed();



		ret->AddItem( 'a', cpp_class_test::MemberAdress_Value::GetInstance() );
		ret->AddItem( 's', cpp_class_test::MemberAdress_Method::GetInstance() );
		ret->AddItem( 'd', cpp_class_test::Offset_SingleInheritance::GetInstance() );
		ret->AddItem( 'f', cpp_class_test::Offset_MultipleInheritance::GetInstance() );
		ret->AddItem( 'g', cpp_class_test::Offset_Singleton::GetInstance() );
		ret->AddItem( 'h', cpp_class_test::Size::GetInstance() );



		ret->AddSplit();


		ret->AddMenu<CPP_Menu>( 27 );
	}

	return ret;
}