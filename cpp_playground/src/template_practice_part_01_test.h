#pragma once

#include "r2_iTest.h"
#include "r2_Singleton.h"

namespace template_practice_part_01_test
{
	class Practice01 : public r2::iTest, public r2::SingleTon<Practice01>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class VaridicMax : public r2::iTest, public r2::SingleTon<VaridicMax>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}