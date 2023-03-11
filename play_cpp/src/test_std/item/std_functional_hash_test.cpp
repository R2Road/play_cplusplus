#include "std_functional_hash_test.h"
#include "std_functional_hash_test_helper_cstring.hpp"

#include <functional>
#include <string>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace std_functional_hash_test
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::hash : Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				OUTPUT_VALUE( std::hash<int>{}( 1 ) );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_VALUE( std::hash<std::string>{}( "" ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT CString::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::hash : CString";
		};
	}
	r2cm::iItem::DoFunctionT CString::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			OUTPUT_FILE( "src/test_std/item/std_functional_hash_test_helper_cstring.hpp" );

			std::cout << r2cm::split;

			{
				OUTPUT_VALUE( std_functional_hash_test_helper_cstring::Hash4CString{}( "asdf", 4 ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}