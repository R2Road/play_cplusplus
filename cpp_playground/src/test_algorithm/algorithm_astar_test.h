#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace algorithm_astar_test
{
	class Basic : public r2::iTest, public r2::SingleTon<Basic>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class WithVector : public r2::iTest, public r2::SingleTon<WithVector>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}