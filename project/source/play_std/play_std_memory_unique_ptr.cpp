#include "play_std_memory_unique_ptr.hpp"
#include "play_std_memory_unique_ptr_helper___forward_declaration.hpp"
#include "play_std_memory_unique_ptr_helper___template_deleter.hpp"

#include <memory>
#include <utility>

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

namespace play_std_memory_unique_ptr
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
				DECL_MAIN( std::unique_ptr<int> up( new int( 3 ) ) );
				OUT_VALUE( *up );

				LF();

				EXPECT_NE( nullptr, up );
				PROC_MAIN( up.reset() );
				EXPECT_EQ( nullptr, up );
			}

			LS();

			{
				DECL_MAIN( std::unique_ptr<int> up1( new int( 3 ) ) );

				LF();

				OUT_CODE( auto up2 = test_up );
				OUT_CODE( auto up3( test_up ) );
				OUT_COMMENT( "복사, 대입 불가" );

				LF();

				DECL_MAIN( auto up4 = std::move( up1 ) );
				EXPECT_EQ( nullptr, up1 );
				EXPECT_NE( nullptr, up4 );
				OUT_COMMENT( "move 가능" );
			}

			LS();

			{
				OUT_NOTE( "release() 는 보유한 포인터를 반환하고 자신을 초기화 한다." );

				LF();

				DECL_MAIN( auto up1( std::make_unique<int>( 3 ) ) );
				DECL_MAIN( std::unique_ptr<int> up2( up1.release() ) );

				LF();

				EXPECT_EQ( nullptr, up1 );
				EXPECT_NE( nullptr, up2 );
			}

			LS();

			{
				DECL_MAIN( auto up( std::make_unique<int>( 3 ) ) );
				OUT_VALUE( *up );
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
				DECL_MAIN( std::unique_ptr<int> up );
				OUT_VALUE( sizeof( up ) );
			}

			LS();

			{
				DECL_MAIN( std::unique_ptr<int> up( new int( 3 ) ) );
				OUT_VALUE( sizeof( up ) );
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
				DECL_MAIN( std::unique_ptr<int> up );
				OUT_BINARIES( (uint8_t*)&up, sizeof( up ) );
			}

			LS();

			{
				DECL_MAIN( std::unique_ptr<int> up( new int( 3 ) ) );
				OUT_BINARY( up.get() );
				OUT_BINARIES( (uint8_t*)&up, sizeof( up ) );
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

			OUT_NOTE( "memory pool 이나 caching 등을 활용하고 있다면 삭제자를 지정해서 쓰면 된다." );

			LS();

			DECL_MAIN( struct Deleter { void operator()( int* p ) { delete p; puts( "Deleter::operator()" ); } } );

			LS();

			{
				using U = std::unique_ptr<int, Deleter>;
				std::cout << "using U = std::unique_ptr<int, Deleter>;" << r2tm::linefeed;

				LF();

				DECL_MAIN( U up( new int( 3 ) ) );
				OUT_VALUE( *up );

				LF();

				PROC_MAIN( up.reset() );
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

			OUT_FILE( "source/play_std/play_std_memory_unique_ptr_helper___template_deleter.hpp" );

			LS();

			{
				DECL_MAIN( play_std_memory_unique_ptr_helper_template_deleter::U<int> up( new int( 3 ) ) );
				OUT_VALUE( *up );

				LF();

				PROC_MAIN( up.reset() );
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

			OUT_FILE( "source/play_std/play_std_memory_unique_ptr_helper___forward_declaration.hpp" );

			LS();

			OUT_FILE( "source/play_std/play_std_memory_unique_ptr_helper___forward_declaration.cpp" );

			LS();

			{
				DECL_MAIN( play_std_memory_unique_ptr_helper___forward_declaration::Processor p );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}