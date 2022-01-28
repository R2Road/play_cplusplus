#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace array_based_list_test
{
	class Basic : public r2::iTest, public r2::SingleTon<Basic>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}