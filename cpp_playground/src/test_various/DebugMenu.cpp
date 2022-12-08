#include "DebugMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "test_various/item/various_debug_test.h"

#include "RootMenu.h"

r2cm::MenuUp DebugMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', various_debug_test::PredefinedMacro::GetInstance() );
		ret->AddItem( '2', various_debug_test::OutPutDebugString::GetInstance() );
		ret->AddItem( '3', various_debug_test::Assertion::GetInstance() );
		ret->AddItem( '4', various_debug_test::DebugBreak::GetInstance() );
		ret->AddItem( '5', various_debug_test::MyAssertion::GetInstance() );
		ret->AddItem( '6', various_debug_test::SimpleLog::GetInstance() );


		ret->AddSplit();


		ret->AddMenu<RootMenu>( 27 );
	}

	return ret;
}