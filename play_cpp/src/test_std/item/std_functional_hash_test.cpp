#include "std_functional_hash_test.h"
#include "std_functional_hash_test_helper_cstring.hpp"

#include <functional>
#include <string>

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace std_functional_hash_test
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::hash : Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			{
				OUTPUT_VALUE( std::hash<int>{}( 1 ) );
			}

			std::cout << r2tm::split;

			{
				OUTPUT_VALUE( std::hash<std::string>{}( "" ) );
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT CString::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::hash : CString";
		};
	}
	r2tm::DoFunctionT CString::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			OUTPUT_FILE( "src/test_std/item/std_functional_hash_test_helper_cstring.hpp" );

			std::cout << r2tm::split;

			{
				OUTPUT_VALUE( std_functional_hash_test_helper_cstring::Hash4CString{}( "asdf", 4 ) );
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}