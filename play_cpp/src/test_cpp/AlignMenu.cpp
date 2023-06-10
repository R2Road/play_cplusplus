#include "AlignMenu.h"

#include "r2tm/r2tm_Director.h"

#include "test_cpp/item/cpp_alignas_test.h"
#include "test_cpp/item/cpp_alignof_test.h"

#include "CPP_Menu.h"

r2tm::TitleFunctionT AlignMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Align";
	};
}
r2tm::DescriptionFunctionT AlignMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT AlignMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', cpp_alignof_test::PrimitiveType() );
		ret->AddItem( '2', cpp_alignof_test::STDContainer() );
		ret->AddItem( '3', cpp_alignof_test::Struct() );
		ret->AddItem( '4', cpp_alignof_test::MixedStruct() );



		ret->AddLineFeed();



		ret->AddItem( 'q', cpp_align_test::AlignAs() );



		ret->AddSplit();



		ret->AddMenu( 27, CPP_Menu() );
	};
}