#pragma once

#include "r2_iNode.h"
#include "r2_Singleton.h"

namespace template_practice_part_02_test
{
	class GreatestCommonDivisor : public r2::iNode, public r2::SingleTon<GreatestCommonDivisor>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};
}