#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace new_test
{
	class Basic : public r2::iTest, public r2::SingleTon<Basic>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class PlacementNew : public r2::iTest, public r2::SingleTon<PlacementNew>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}