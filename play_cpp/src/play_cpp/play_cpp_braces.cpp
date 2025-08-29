#include "play_cpp_braces.hpp"

#include <memory>

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

namespace play_cpp_braces
{
	r2tm::TitleFunctionT Braces_PrimitiveType::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "{}";
		};
	}
	r2tm::DoFunctionT Braces_PrimitiveType::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				DECL_MAIN( int i{} );

				LF();

				OUTPUT_VALUE( i );
			}

			LS();

			{
				DECL_MAIN( int i = 123 );

				LF();

				PROC_MAIN( i = {} );
				OUTPUT_VALUE( i );
			}

			LS();

			{
				DECL_MAIN( std::shared_ptr<int> i = std::make_shared<int>( 123 ) );

				LF();

				EXPECT_NE( nullptr, i );

				LF();

				PROC_MAIN( i = {} );
				EXPECT_EQ( nullptr, i );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}