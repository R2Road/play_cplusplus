#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace template_meta_programming_test
{
	class MultiTypePackage : public r2::iTest, public r2::SingleTon<MultiTypePackage>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}