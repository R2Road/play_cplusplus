#include "STDCoutMenu.h"

#include "r2tm/r2tm_Director.h"

#include "test_std/item/std_cout_test.h"

#include "STDMenu.h"

r2tm::TitleFunctionT STDCoutMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "std::cout";
	};
}
r2tm::DescriptionFunctionT STDCoutMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT STDCoutMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', std_cout_test::Basic() );
		ret->AddItem( '2', std_cout_test::FMTStatus() );
		ret->AddItem( '3', std_cout_test::NumberFormat_1() );
		ret->AddItem( '4', std_cout_test::NumberFormat_2() );
		ret->AddItem( '5', std_cout_test::NumberFormat_3() );
		ret->AddItem( '6', std_cout_test::NumberFormat_4() );


		ret->AddLineFeed();


		ret->AddItem( 'q', std_cout_test::Align() );
		ret->AddItem( 'w', std_cout_test::Flag() );
		ret->AddItem( 'e', std_cout_test::BoolAlpha() );


		ret->AddLineFeed();


		ret->AddItem( 'a', std_cout_test::UserDefinedType() );


		ret->AddSplit();


		ret->AddMenu( 27, STDMenu() );
	};
}