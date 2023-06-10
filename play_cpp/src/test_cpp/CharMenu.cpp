#include "CharMenu.h"

#include "r2tm/r2tm_Director.h"

#include "test_cpp/item/char_test.h"
#include "test_cpp/item/korean_test.h"
#include "test_cpp/item/locale_test.h"

#include "CPP_Menu.h"

r2tm::TitleFunctionT CharMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Char";
	};
}
r2tm::DescriptionFunctionT CharMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT CharMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', char_test::Basic() );
		ret->AddItem( '2', char_test::Encoding() );
		ret->AddItem( '3', locale_test::Basic() );
		ret->AddItem( '4', char_test::RawStringLiteral() );


		ret->AddLineFeed();


		ret->AddItem( 'z', korean_test::Basic() );


		ret->AddSplit();


		ret->AddMenu( 27, CPP_Menu() );
	};
}