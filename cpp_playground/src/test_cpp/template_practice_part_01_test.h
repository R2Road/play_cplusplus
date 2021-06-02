#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace template_practice_part_01_test
{
	class BufferWithTemplate : public r2::iTest, public r2::SingleTon<BufferWithTemplate>
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