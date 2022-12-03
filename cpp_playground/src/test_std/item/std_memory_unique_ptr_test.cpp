#include "std_memory_unique_ptr_test.h"
#include "std_memory_test_helper_up_and_forward_declaration.h"

#include <memory>
#include <utility>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace std_memory_unique_ptr_test
{
	r2cm::iItem::TitleFunctionT UniquePointer::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Unique Pointer";
		};
	}
	r2cm::iItem::DoFunctionT UniquePointer::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( std::unique_ptr<int> up( new int( 3 ) ) );
				OUTPUT_VALUE( *up );

				std::cout << r2cm::linefeed;

				EXPECT_NE( nullptr, up );
				PROCESS_MAIN( up.reset() );
				EXPECT_EQ( nullptr, up );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( std::unique_ptr<int> up1( new int( 3 ) ) );

				std::cout << r2cm::linefeed;

				OUTPUT_CODE( auto up2 = test_up );
				OUTPUT_CODE( auto up3( test_up ) );
				OUTPUT_COMMENT( "복사, 대입 불가" );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( auto up4 = std::move( up1 ) );
				EXPECT_EQ( nullptr, up1 );
				EXPECT_NE( nullptr, up4 );
				OUTPUT_COMMENT( "move 가능" );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "release() 는 보유한 포인터를 반환하고 자신을 초기화 한다." );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( auto up1( std::make_unique<int>( 3 ) ) );
				DECLARATION_MAIN( std::unique_ptr<int> up2( up1.release() ) );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( nullptr, up1 );
				EXPECT_NE( nullptr, up2 );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( auto up( std::make_unique<int>( 3 ) ) );
				OUTPUT_VALUE( *up );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT UniquePointer_FowardDeclaration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Unique Pointer : Forward Declaration";
		};
	}
	r2cm::iItem::DoFunctionT UniquePointer_FowardDeclaration::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			OUTPUT_FILE( "src/test_std/item/std_memory_test_helper_up_and_forward_declaration.h" );

			std::cout << r2cm::split;

			OUTPUT_FILE( "src/test_std/item/std_memory_test_helper_up_and_forward_declaration.cpp" );

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( std_memory_test_helper_up_and_forward_declaration::Processor p );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}