#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace template_practice_part_01_test
{
	class BufferWithTemplate : public r2::iItem, public r2::SingleTon<BufferWithTemplate>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class VaridicMax : public r2::iItem, public r2::SingleTon<VaridicMax>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}