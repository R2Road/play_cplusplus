#include <cstring> // for std::strcmp
#include <type_traits> // for std::_Hash_array_representation
#include <unordered_map>

namespace std_unordered_map_test_helper_cstring
{
	struct CStringNSize
	{
		const char* str = nullptr;
		size_t size = 0;
	};

	struct Hash4CStringNSize
	{
		size_t operator()( const CStringNSize& sns ) const noexcept
		{
			return ( std::_Hash_array_representation( sns.str, sns.size ) );
		}
	};

	struct Compare4CStringNSize
	{
		bool operator()( const CStringNSize& lhs, const CStringNSize& rhs ) const noexcept
		{
			return ( 0 == std::strcmp( lhs.str, rhs.str ) );
		}
	};

	using UM4CStringT = std::unordered_map<CStringNSize, int, Hash4CStringNSize, Compare4CStringNSize>;
}