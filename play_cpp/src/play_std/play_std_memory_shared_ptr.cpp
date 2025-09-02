#include "play_std_memory_shared_ptr.hpp"
#include "play_std_memory_unique_ptr_helper___forward_declaration.hpp"

#include <memory>

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

namespace play_std_memory_shared_ptr
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
				DECL_MAIN( std::shared_ptr<int> sp );
				OUT_CODE( *sp );
				OUT_COMMENT( "Not Working" );
			}

			LS();

			{
				DECL_MAIN( std::shared_ptr<int> sp( new int( 10 ) ) );
				OUT_VALUE( *sp );
			}

			LS();
			
			{
				OUT_NOTE( "const sp 는 [* const] 에 가깝다." );

				LF();

				DECL_MAIN( std::shared_ptr<int> sp1( new int( 10 ) ) );
				DECL_MAIN( const std::shared_ptr<int> sp2 = sp1 );
				OUT_CODE( sp2 = nullptr );
				OUT_COMMENT( "지정된 pointer 변경 불가." );

				LF();

				PROC_MAIN( *sp2 = 11 );
				OUT_VALUE( *sp2 );
				OUT_COMMENT( "값 변경 가능" );
			}

			LS();

			{
				OUT_NOTE( "Shared Pointer Has Const Value" );

				LF();

				DECL_MAIN( std::shared_ptr<const int> sp( new int( 10 ) ) );
				OUT_VALUE( *sp );

				LF();

				OUT_CODE( *sp = 11 );
				OUT_COMMENT( "Failed : Change Value" );
			}

			LS();

			{
				OUT_NOTE( "Make Shared" );

				LF();

				DECL_MAIN( auto sp = std::make_shared<int>( 10 ) );
				OUT_VALUE( sizeof( sp ) );
				OUT_VALUE( *sp );
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
				DECL_MAIN( std::shared_ptr<int> sp );
				OUT_VALUE( sizeof( sp ) );
			}

			LS();

			{
				DECL_MAIN( std::shared_ptr<int> sp( new int( 10 ) ) );
				OUT_VALUE( sizeof( sp ) );
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
				DECL_MAIN( std::shared_ptr<int> sp );
				OUT_BINARY( sp );
			}

			LS();

			{
				DECL_MAIN( std::shared_ptr<int> sp( new int( 3 ) ) );
				OUT_BINARY( sp.get() );
				OUT_BINARY( sp );

				LF();

				PROC_MAIN( sp.reset( new int( 3 ) ) );
				OUT_BINARY( sp.get() );
				OUT_BINARY( sp );
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

			OUT_NOTE( "std::make_shared 로 메모리를 할당하면 ref count 와 weak count 를 위한 공간을..." );
			OUT_NOTE( "메모리의 앞 부분에 붙여서 메모리를 할당한다." );
			OUT_NOTE( "구조 : ref count + weak count + obj" );

			LS();

			DECL_MAIN( auto sp = std::make_shared<int>( 255 ) );

			LS();

			DECL_MAIN( int32_t* p = (int32_t* )sp.get() );
			PROC_MAIN( p -= 2 );
			OUT_BINARIES( p, 3 );

			LS();

			{
				DECL_MAIN( auto tp_1 = sp );
				OUT_BINARIES( p, 3 );

				LF();

				DECL_MAIN( auto tp_2 = sp );
				OUT_BINARIES( p, 3 );

				LF();

				PROC_MAIN( tp_2.reset() );
				OUT_BINARIES( p, 3 );
			}

			LS();

			{
				DECL_MAIN( std::weak_ptr<int> wp_1 = sp );
				OUT_BINARIES( p, 3 );

				LF();

				PROC_MAIN( wp_1.reset() );
				OUT_BINARIES( p, 3 );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}