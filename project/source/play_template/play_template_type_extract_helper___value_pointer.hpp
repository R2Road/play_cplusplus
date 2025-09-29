#pragma once

namespace play_template_type_extract
{
	template<typename T>
	struct Helper___TypeExtracter___ValuePointer;



	template<typename Value_T, typename Owner_T>
	struct Helper___TypeExtracter___ValuePointer<Value_T Owner_T::*>
	{
		using ValueT = Value_T;
		using OwnerT = Owner_T;
	};



	template<typename Value_T>
	struct Helper___TypeExtracter___ValuePointer<Value_T*>
	{
		using ValueT = Value_T;
	};
}