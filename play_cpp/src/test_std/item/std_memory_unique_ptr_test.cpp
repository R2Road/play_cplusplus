#include "std_memory_unique_ptr_test.h"
#include "std_memory_unique_ptr_test_helper_forward_declaration.h"
#include "std_memory_unique_ptr_test_helper_template_deleter.hpp"

#include <memory>
#include <utility>

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace std_memory_unique_ptr_test
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::unique_ptr : Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				DECLARATION_MAIN( std::unique_ptr<int> up( new int( 3 ) ) );
				OUTPUT_VALUE( *up );

				std::cout << r2tm::linefeed;

				EXPECT_NE( nullptr, up );
				PROCESS_MAIN( up.reset() );
				EXPECT_EQ( nullptr, up );
			}

			LS();

			{
				DECLARATION_MAIN( std::unique_ptr<int> up1( new int( 3 ) ) );

				std::cout << r2tm::linefeed;

				OUTPUT_CODE( auto up2 = test_up );
				OUTPUT_CODE( auto up3( test_up ) );
				OUTPUT_COMMENT( "복사, 대입 불가" );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( auto up4 = std::move( up1 ) );
				EXPECT_EQ( nullptr, up1 );
				EXPECT_NE( nullptr, up4 );
				OUTPUT_COMMENT( "move 가능" );
			}

			LS();

			{
				OUTPUT_NOTE( "release() 는 보유한 포인터를 반환하고 자신을 초기화 한다." );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( auto up1( std::make_unique<int>( 3 ) ) );
				DECLARATION_MAIN( std::unique_ptr<int> up2( up1.release() ) );

				std::cout << r2tm::linefeed;

				EXPECT_EQ( nullptr, up1 );
				EXPECT_NE( nullptr, up2 );
			}

			LS();

			{
				DECLARATION_MAIN( auto up( std::make_unique<int>( 3 ) ) );
				OUTPUT_VALUE( *up );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Size::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::unique_ptr : Size";
		};
	}
	r2tm::DoFunctionT Size::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				DECLARATION_MAIN( std::unique_ptr<int> up );
				OUTPUT_VALUE( sizeof( up ) );
			}

			LS();

			{
				DECLARATION_MAIN( std::unique_ptr<int> up( new int( 3 ) ) );
				OUTPUT_VALUE( sizeof( up ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Binary::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::unique_ptr : Binary";
		};
	}
	r2tm::DoFunctionT Binary::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				DECLARATION_MAIN( std::unique_ptr<int> up );
				OUTPUT_BINARIES( (uint8_t*)&up, sizeof( up ) );
			}

			LS();

			{
				DECLARATION_MAIN( std::unique_ptr<int> up( new int( 3 ) ) );
				OUTPUT_BINARY( up.get() );
				OUTPUT_BINARIES( (uint8_t*)&up, sizeof( up ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Deleter::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::unique_ptr : Deleter";
		};
	}
	r2tm::DoFunctionT Deleter::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_NOTE( "memory pool 이나 caching 등을 활용하고 있다면 삭제자를 지정해서 쓰면 된다." );

			LS();

			DECLARATION_MAIN( struct Deleter { void operator()( int* p ) { delete p; puts( "Deleter::operator()" ); } } );

			LS();

			{
				using U = std::unique_ptr<int, Deleter>;
				std::cout << "using U = std::unique_ptr<int, Deleter>;" << r2tm::linefeed;

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( U up( new int( 3 ) ) );
				OUTPUT_VALUE( *up );

				std::cout << r2tm::linefeed;

				PROCESS_MAIN( up.reset() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT TemplateDeleter::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::unique_ptr : Template Deleter";
		};
	}
	r2tm::DoFunctionT TemplateDeleter::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_FILE( "src/test_std/item/std_memory_unique_ptr_test_helper_template_deleter.hpp" );

			LS();

			{
				DECLARATION_MAIN( std_memory_unique_ptr_test_helper_template_deleter::U<int> up( new int( 3 ) ) );
				OUTPUT_VALUE( *up );

				std::cout << r2tm::linefeed;

				PROCESS_MAIN( up.reset() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT FowardDeclaration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::unique_ptr : Forward Declaration";
		};
	}
	r2tm::DoFunctionT FowardDeclaration::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_FILE( "src/test_std/item/std_memory_unique_ptr_test_helper_forward_declaration.h" );

			LS();

			OUTPUT_FILE( "src/test_std/item/std_memory_unique_ptr_test_helper_forward_declaration.cpp" );

			LS();

			{
				DECLARATION_MAIN( std_memory_unique_ptr_test_helper_forward_declaration::Processor p );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}