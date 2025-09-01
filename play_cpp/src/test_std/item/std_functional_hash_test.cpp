#include "std_functional_hash_test.h"
#include "std_functional_hash_test_helper_cstring.hpp"

#include <functional>
#include <string>

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

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
			LS();

			{
				OUT_VALUE( std::hash<int>{}( 1 ) );
			}

			LS();

			{
				OUT_VALUE( std::hash<std::string>{}( "" ) );
			}

			LS();

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
			LS();

			OUT_FILE( "src/test_std/item/std_functional_hash_test_helper_cstring.hpp" );

			LS();

			{
				OUT_VALUE( std_functional_hash_test_helper_cstring::Hash4CString{}( "asdf", 4 ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}