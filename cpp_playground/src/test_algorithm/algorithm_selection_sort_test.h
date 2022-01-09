#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace algorithm_selection_sort_test
{
	class Case1 : public r2::iTest, public r2::SingleTon<Case1>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class Case2 : public r2::iTest, public r2::SingleTon<Case2>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}