#pragma once

#include "r2_iNode.h"
#include "r2_Singleton.h"

namespace const_pointer_test
{
	class Basic : public r2::iNode, public r2::SingleTon<Basic>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		r2::eTestResult Do() override;
	};
}