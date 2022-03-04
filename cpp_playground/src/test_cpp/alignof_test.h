#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace alignof_test
{
	class Basic : public r2::iItem, public r2::SingleTon<Basic>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class MixedStruct : public r2::iItem, public r2::SingleTon<MixedStruct>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}