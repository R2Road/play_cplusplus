#include "AlignMenu.h"

#include "r2tm/r2tm_menu_processor.hpp"

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
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', cpp_alignof_test::PrimitiveType() );
		mp->AddItem( '2', cpp_alignof_test::STDContainer() );
		mp->AddItem( '3', cpp_alignof_test::Struct() );
		mp->AddItem( '4', cpp_alignof_test::MixedStruct() );



		mp->AddLineFeed();



		mp->AddItem( 'q', cpp_align_test::AlignAs() );



		mp->AddSplit();



		mp->AddMenu( 27, CPP_Menu() );
	};
}