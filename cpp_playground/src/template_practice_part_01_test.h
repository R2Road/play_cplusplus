#pragma once

#include "r2_iNode.h"
#include "r2_Singleton.h"

namespace template_practice_part_01_test
{
	class Practice01 : public r2::iNode, public r2::SingleTon<Practice01>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};
}