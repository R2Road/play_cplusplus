#pragma once

namespace play_template_type_extract
{
	template<typename T>
	struct Helper___TypeExtracter___MemberValuePointer;

	template<typename RetType, typename ClassType>
	struct Helper___TypeExtracter___MemberValuePointer<RetType ClassType::*>
	{
		using RetT = RetType;
		using ClassT = ClassType;
	};
}