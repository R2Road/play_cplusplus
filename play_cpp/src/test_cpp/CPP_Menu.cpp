#include "CPP_Menu.h"

#include "r2tm/r2tm_Director.h"

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
#include "RootMenu.h"

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
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddMenu( '1', ClassMenu() );
		ret->AddMenu( '2', NameSpaceMenu() );


		ret->AddLineFeed();


		ret->AddMenu( '6', CharMenu() );
		ret->AddMenu( '7', AlignMenu() );
		ret->AddMenu( '8', EnumMenu() );


		ret->AddLineFeed();


		ret->AddMenu( 'q', NewMenu() );
		ret->AddMenu( 'w', LambdaMenu() );
		ret->AddItem( 'e', using_test::Basic() );


		ret->AddLineFeed();


		ret->AddItem( 'a', cpp_structured_binding_test::Basic() );
		ret->AddItem( 'b', number_test::Prefix() );


		ret->AddSplit();


		ret->AddMenu( 27, RootMenu() );
	};
}