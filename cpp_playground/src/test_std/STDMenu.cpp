#include "STDMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_constant.h"

#include "test_std/item/std_algorithm_test.h"
#include "test_std/item/std_cout_test.h"
#include "test_std/item/std_function_test.h"
#include "test_std/item/std_function_2_test.h"
#include "test_std/item/std_fstream_test.h"
#include "test_std/item/std_optional_test.h"
#include "test_std/item/std_regex_test.h"
#include "test_std/item/std_stringview_test.h"
#include "test_std/item/std_tuple_test.h"
#include "test_std/item/std_variant_test.h"


#include "RootMenu.h"
#include "STDContainerMenu.h"
#include "STDCoutMenu.h"
#include "STDFileSystemMenu.h"
#include "STDMemoryMenu.h"
#include "STDNumericMenu.h"
#include "STDThreadMenu.h"

r2cm::MenuUp STDMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem(
			'1'
			, []()->const char* { return FileSystemMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( FileSystemMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
		ret->AddItem( '2', std_optional_test::Basic::GetInstance() );
		ret->AddItem( '2', std_optional_test::Constructor::GetInstance() );
		ret->AddItem( '3', std_optional_test::Reference::GetInstance() );

		ret->AddLineFeed();

		ret->AddItem( '5', std_stringview_test::Basic::GetInstance() );
		ret->AddItem( '6', std_tuple_test::Basic::GetInstance() );
		ret->AddItem( '7', std_variant_test::Basic::GetInstance() );
		ret->AddItem( '8', std_fstream_test::Basic::GetInstance() );

		ret->AddLineFeed();

		ret->AddItem( 'q', std_function_test::Equality_FunctionPointer_1::GetInstance() );
		ret->AddItem( 'w', std_function_test::Equality_FunctionPointer_2::GetInstance() );
		ret->AddItem( 'e', std_function_test::Equality_FunctionPointer_3::GetInstance() );
		ret->AddItem( 'r', std_function_2_test::Equality_STDBind_1::GetInstance() );
		ret->AddItem( 't', std_function_test::Equality_Lambda_1::GetInstance() );

		ret->AddLineFeed();


		ret->AddItem(
			'a'
			, []()->const char* { return STDMemoryMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( STDMemoryMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
		ret->AddItem(
			's'
			, []()->const char* { return STDNumericMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( STDNumericMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
		ret->AddItem(
			'd'
			, []()->const char* { return STDContainerMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( STDContainerMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
		ret->AddItem(
			'f'
			, []()->const char* { return STDThreadMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( STDThreadMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
		ret->AddItem( 'g', std_algorithm_test::Shuffle::GetInstance() );

		ret->AddLineFeed();

		ret->AddItem( 'z', std_regex_test::Basic::GetInstance() );
		ret->AddItem(
			'x'
			, []()->const char* { return STDCoutMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( STDCoutMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);


		ret->AddSplit();


		ret->AddItem(
			27
			, []()->const char* { return "Return To Root"; }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( RootMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
	}

	return ret;
}