#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace template_meta_programming_test
{
	class MultiTypePackage : public r2::iItem, public r2::SingleTon<MultiTypePackage>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}