#pragma once

#include "r2_iTest.h"
#include "r2_Singleton.h"

namespace template_meta_programming_test
{
	class MultiTypePackage : public r2::iTest, public r2::SingleTon<MultiTypePackage>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};
}