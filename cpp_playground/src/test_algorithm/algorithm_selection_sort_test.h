#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace algorithm_selection_sort_test
{
	class Case1 : public r2cm::iItem, public r2::SingleTon<Case1>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class Case2 : public r2cm::iItem, public r2::SingleTon<Case2>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}