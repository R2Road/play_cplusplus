#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace performance_1_test
{
	class Assignment_With_Pointer : public r2::iTest, public r2::SingleTon<Assignment_With_Pointer>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}