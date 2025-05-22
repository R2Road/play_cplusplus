#include "cpp_braces.h"

#include <memory>

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace cpp_braces
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
				DECLARATION_MAIN( int i{} );
				OUTPUT_VALUE( i );
			}

			LS();

			{
				DECLARATION_MAIN( int i = 123 );
				PROCESS_MAIN( i = {} );
				OUTPUT_VALUE( i );
			}

			LS();

			{
				DECLARATION_MAIN( std::shared_ptr<int> i = std::make_shared<int>( 123 ) );
				EXPECT_NE( nullptr, i );
				PROCESS_MAIN( i = {} );
				EXPECT_EQ( nullptr, i );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}