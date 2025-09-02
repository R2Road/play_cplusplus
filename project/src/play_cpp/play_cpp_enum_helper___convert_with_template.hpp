#include <type_traits>

namespace play_cpp_enum_helper___convert_with_template
{
	template<typename EnumT>
	constexpr auto Enum2Value( EnumT e )
	{
		return static_cast<std::underlying_type_t<EnumT>>( e );
	}
}