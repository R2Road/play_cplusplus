#include "CPP_Menu.h"

#include "r2tm/r2tm_menu_processor.hpp"

#include "item/cpp_structured_binding_test.h"
#include "item/number_test.h"
#include "item/using_test.h"

#include "AlignMenu.h"
#include "EnumMenu.h"
#include "LambdaMenu.h"
#include "NameSpaceMenu.h"
#include "NewMenu.h"

#include "ClassMenu.h"
#include "CharMenu.h"
#include "menu_root.h"

#include "item/cpp_braces.h"

r2tm::TitleFunctionT CPP_Menu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "CPP";
	};
}
r2tm::DescriptionFunctionT CPP_Menu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT CPP_Menu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddMenu( '1', ClassMenu() );
		mp->AddMenu( '2', NameSpaceMenu() );
		mp->AddItem( '3', cpp_braces::Braces_PrimitiveType() );


		mp->AddLineFeed();


		mp->AddMenu( '6', CharMenu() );
		mp->AddMenu( '7', AlignMenu() );
		mp->AddMenu( '8', EnumMenu() );


		mp->AddLineFeed();


		mp->AddMenu( 'q', NewMenu() );
		mp->AddMenu( 'w', LambdaMenu() );
		mp->AddItem( 'e', using_test::Basic() );


		mp->AddLineFeed();


		mp->AddItem( 'a', cpp_structured_binding_test::Basic() );
		mp->AddItem( 'b', number_test::Prefix() );


		mp->AddSplit();


		mp->AddMenu( 27, Menu_Root() );
	};
}