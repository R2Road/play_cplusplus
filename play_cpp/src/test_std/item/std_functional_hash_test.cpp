#include "std_functional_hash_test.h"

#include <functional>
#include <string>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace std_functional_hash_test
{
	//
	// Copy From <xstring>
	//
	struct Hash4CString
	{
		_NODISCARD size_t operator()( const char* str, const std::size_t size ) const noexcept
		{	// hash _Keyval to size_t value by pseudorandomizing transform
			return ( std::_Hash_array_representation( str, size ) );
		}
	};



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

			{
				OUTPUT_VALUE( Hash4CString{}( "asdf", 4 ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}