#include "std_memory_test.h"
#include "std_memory_unique_ptr_test_helper_forward_declaration.h"

#include <memory>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace std_memory_test
{
	r2cm::iItem::TitleFunctionT SharedPointer::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Shared Pointer";
		};
	}
	r2cm::iItem::DoFunctionT SharedPointer::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( std::shared_ptr<int> sp( new int( 10 ) ) );
				OUTPUT_VALUE( sizeof( sp ) );
				OUTPUT_VALUE( *sp );
			}

			std::cout << r2cm::split;
			
			{
				OUTPUT_NOTE( "const sp �� [* const] �� ������." );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( std::shared_ptr<int> sp1( new int( 10 ) ) );
				DECLARATION_MAIN( const auto sp2 = sp1 );
				OUTPUT_CODE( sp2 = nullptr );
				OUTPUT_COMMENT( "������ pointer ���� �Ұ�." );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( *sp2 = 11 );
				OUTPUT_VALUE( *sp2 );
				OUTPUT_COMMENT( "�� ���� ����" );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "Shared Pointer Has Const Value" );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( std::shared_ptr<const int> sp( new int( 10 ) ) );
				OUTPUT_VALUE( *sp );

				std::cout << r2cm::linefeed;

				OUTPUT_CODE( *sp = 11 );
				OUTPUT_COMMENT( "Failed : Change Value" );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "Make Shared" );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( auto sp = std::make_shared<int>( 10 ) );
				OUTPUT_VALUE( sizeof( sp ) );
				OUTPUT_VALUE( *sp );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT SharedPointer_MakeShared_And_Memory::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Shared Pointer : MakeShared And Memory";
		};
	}
	r2cm::iItem::DoFunctionT SharedPointer_MakeShared_And_Memory::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			OUTPUT_NOTE( "std::make_shared �� �޸𸮸� �Ҵ��ϸ� ref count �� weak count �� ���� ������..." );
			OUTPUT_NOTE( "�޸��� �� �κп� �ٿ��� �޸𸮸� �Ҵ��Ѵ�." );
			OUTPUT_NOTE( "���� : ref count + weak count + obj" );

			std::cout << r2cm::split;

			DECLARATION_MAIN( auto sp = std::make_shared<int>( 255 ) );

			std::cout << r2cm::split;

			DECLARATION_MAIN( int32_t* p = (int32_t* )sp.get() );
			PROCESS_MAIN( p -= 2 );
			OUTPUT_BINARIES( p, 3 );

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( auto tp_1 = sp );
				OUTPUT_BINARIES( p, 3 );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( auto tp_2 = sp );
				OUTPUT_BINARIES( p, 3 );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( tp_2.reset() );
				OUTPUT_BINARIES( p, 3 );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( std::weak_ptr<int> wp_1 = sp );
				OUTPUT_BINARIES( p, 3 );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( wp_1.reset() );
				OUTPUT_BINARIES( p, 3 );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}