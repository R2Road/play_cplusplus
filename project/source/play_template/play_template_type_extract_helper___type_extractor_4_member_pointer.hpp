#pragma once

namespace play_template_type_extract
{
	template<typename T>
	struct Helper_TypeExtracter_4_MemberPointer;

	template<typename RetType, typename ClassType>
	struct Helper_TypeExtracter_4_MemberPointer<RetType ClassType::*>
	{
		using RetT = RetType;
		using ClassT = ClassType;
	};
}