#include "CharMenu.h"

#include "r2tm/r2tm_menu_processor.hpp"

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
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', char_test::Basic() );
		mp->AddItem( '2', char_test::Encoding() );
		mp->AddItem( '3', locale_test::Basic() );
		mp->AddItem( '4', char_test::RawStringLiteral() );


		mp->AddLineFeed();


		mp->AddItem( 'z', korean_test::Basic() );


		mp->AddSplit();


		mp->AddMenu( 27, CPP_Menu() );
	};
}