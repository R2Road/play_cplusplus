#pragma once

#include "r2_iNode.h"
#include "r2_Singleton.h"

namespace filesystem_test
{
	class CurrentDirectory : public r2::iNode, public r2::SingleTon<CurrentDirectory>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		r2::eTestResult Do() override;
	};
}