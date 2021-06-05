#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace algorithm_test
{
	class Accumulate_Number : public r2::iTest, public r2::SingleTon<Accumulate_Number>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}