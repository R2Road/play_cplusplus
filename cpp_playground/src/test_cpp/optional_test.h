#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace optional_test
{
	class Basic_discard : public r2::iTest, public r2::SingleTon<Basic_discard>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}