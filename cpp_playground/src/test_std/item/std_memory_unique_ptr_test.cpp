#include "std_memory_unique_ptr_test.h"
#include "std_memory_unique_ptr_test_helper_forward_declaration.h"
#include "std_memory_unique_ptr_test_helper_template_deleter.hpp"

#include <memory>
#include <utility>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace std_memory_unique_ptr_test
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::unique_ptr : Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction() const
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
				OUTPUT_COMMENT( "����, ���� �Ұ�" );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( auto up4 = std::move( up1 ) );
				EXPECT_EQ( nullptr, up1 );
				EXPECT_NE( nullptr, up4 );
				OUTPUT_COMMENT( "move ����" );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "release() �� ������ �����͸� ��ȯ�ϰ� �ڽ��� �ʱ�ȭ �Ѵ�." );

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



	r2cm::iItem::TitleFunctionT Size::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::unique_ptr : Size";
		};
	}
	r2cm::iItem::DoFunctionT Size::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( std::unique_ptr<int> up );
				OUTPUT_VALUE( sizeof( up ) );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( std::unique_ptr<int> up( new int( 3 ) ) );
				OUTPUT_VALUE( sizeof( up ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Deleter::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::unique_ptr : Deleter";
		};
	}
	r2cm::iItem::DoFunctionT Deleter::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			OUTPUT_NOTE( "memory pool �̳� caching ���� Ȱ���ϰ� �ִٸ� �����ڸ� �����ؼ� ���� �ȴ�." );

			std::cout << r2cm::split;

			DECLARATION_MAIN( struct Deleter { void operator()( int* p ) { delete p; puts( "Deleter::operator()" ); } } );

			std::cout << r2cm::split;

			{
				using U = std::unique_ptr<int, Deleter>;
				std::cout << "using U = std::unique_ptr<int, Deleter>;" << r2cm::linefeed;

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( U up( new int( 3 ) ) );
				OUTPUT_VALUE( *up );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( up.reset() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT TemplateDeleter::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::unique_ptr : Template Deleter";
		};
	}
	r2cm::iItem::DoFunctionT TemplateDeleter::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			OUTPUT_FILE( "src/test_std/item/std_memory_unique_ptr_test_helper_template_deleter.hpp" );

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( std_memory_unique_ptr_test_helper_template_deleter::U<int> up( new int( 3 ) ) );
				OUTPUT_VALUE( *up );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( up.reset() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT FowardDeclaration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::unique_ptr : Forward Declaration";
		};
	}
	r2cm::iItem::DoFunctionT FowardDeclaration::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			OUTPUT_FILE( "src/test_std/item/std_memory_unique_ptr_test_helper_forward_declaration.h" );

			std::cout << r2cm::split;

			OUTPUT_FILE( "src/test_std/item/std_memory_unique_ptr_test_helper_forward_declaration.cpp" );

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( std_memory_unique_ptr_test_helper_forward_declaration::Processor p );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}