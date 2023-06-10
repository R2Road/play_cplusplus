#include "std_memory_shared_ptr_test.h"
#include "std_memory_unique_ptr_test_helper_forward_declaration.h"

#include <memory>

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace std_memory_shared_ptr_test
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::shared_ptr : Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				DECLARATION_MAIN( std::shared_ptr<int> sp );
				OUTPUT_CODE( *sp );
				OUTPUT_COMMENT( "Not Working" );
			}

			LS();

			{
				DECLARATION_MAIN( std::shared_ptr<int> sp( new int( 10 ) ) );
				OUTPUT_VALUE( *sp );
			}

			LS();
			
			{
				OUTPUT_NOTE( "const sp 는 [* const] 에 가깝다." );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( std::shared_ptr<int> sp1( new int( 10 ) ) );
				DECLARATION_MAIN( const std::shared_ptr<int> sp2 = sp1 );
				OUTPUT_CODE( sp2 = nullptr );
				OUTPUT_COMMENT( "지정된 pointer 변경 불가." );

				std::cout << r2tm::linefeed;

				PROCESS_MAIN( *sp2 = 11 );
				OUTPUT_VALUE( *sp2 );
				OUTPUT_COMMENT( "값 변경 가능" );
			}

			LS();

			{
				OUTPUT_NOTE( "Shared Pointer Has Const Value" );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( std::shared_ptr<const int> sp( new int( 10 ) ) );
				OUTPUT_VALUE( *sp );

				std::cout << r2tm::linefeed;

				OUTPUT_CODE( *sp = 11 );
				OUTPUT_COMMENT( "Failed : Change Value" );
			}

			LS();

			{
				OUTPUT_NOTE( "Make Shared" );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( auto sp = std::make_shared<int>( 10 ) );
				OUTPUT_VALUE( sizeof( sp ) );
				OUTPUT_VALUE( *sp );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Size::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::shared_ptr : Size";
		};
	}
	r2tm::DoFunctionT Size::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				DECLARATION_MAIN( std::shared_ptr<int> sp );
				OUTPUT_VALUE( sizeof( sp ) );
			}

			LS();

			{
				DECLARATION_MAIN( std::shared_ptr<int> sp( new int( 10 ) ) );
				OUTPUT_VALUE( sizeof( sp ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Binary::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::shared_ptr : Binary";
		};
	}
	r2tm::DoFunctionT Binary::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				DECLARATION_MAIN( std::shared_ptr<int> sp );
				OUTPUT_BINARY( sp );
			}

			LS();

			{
				DECLARATION_MAIN( std::shared_ptr<int> sp( new int( 3 ) ) );
				OUTPUT_BINARY( sp.get() );
				OUTPUT_BINARY( sp );

				std::cout << r2tm::linefeed;

				PROCESS_MAIN( sp.reset( new int( 3 ) ) );
				OUTPUT_BINARY( sp.get() );
				OUTPUT_BINARY( sp );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT MakeShared_And_Memory::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::shared_ptr : MakeShared And Memory";
		};
	}
	r2tm::DoFunctionT MakeShared_And_Memory::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_NOTE( "std::make_shared 로 메모리를 할당하면 ref count 와 weak count 를 위한 공간을..." );
			OUTPUT_NOTE( "메모리의 앞 부분에 붙여서 메모리를 할당한다." );
			OUTPUT_NOTE( "구조 : ref count + weak count + obj" );

			LS();

			DECLARATION_MAIN( auto sp = std::make_shared<int>( 255 ) );

			LS();

			DECLARATION_MAIN( int32_t* p = (int32_t* )sp.get() );
			PROCESS_MAIN( p -= 2 );
			OUTPUT_BINARIES( p, 3 );

			LS();

			{
				DECLARATION_MAIN( auto tp_1 = sp );
				OUTPUT_BINARIES( p, 3 );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( auto tp_2 = sp );
				OUTPUT_BINARIES( p, 3 );

				std::cout << r2tm::linefeed;

				PROCESS_MAIN( tp_2.reset() );
				OUTPUT_BINARIES( p, 3 );
			}

			LS();

			{
				DECLARATION_MAIN( std::weak_ptr<int> wp_1 = sp );
				OUTPUT_BINARIES( p, 3 );

				std::cout << r2tm::linefeed;

				PROCESS_MAIN( wp_1.reset() );
				OUTPUT_BINARIES( p, 3 );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}