#include <type_traits> // for std::_Hash_array_representation

namespace std_functional_hash_test_helper_cstring
{
	//
	// Copy From <xstring>
	//
	struct Hash4CString
	{
		size_t operator()( const char* str, const size_t size ) const noexcept
		{
			// hash _Keyval to size_t value by pseudorandomizing transform
			return ( std::_Hash_array_representation( str, size ) );
		}
	};
}