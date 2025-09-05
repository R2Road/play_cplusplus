#include "play_std_functional_hash.hpp"
#include "play_std_functional_hash_helper___cstring.hpp"

#include <functional>
#include <string>

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

namespace play_std_functional_hash
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

			OUT_FILE( "source/play_std/play_std_functional_hash_helper___cstring.hpp" );

			LS();

			{
				OUT_VALUE( play_std_functional_hash_helper_cstring::Hash4CString{}( "asdf", 4 ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}