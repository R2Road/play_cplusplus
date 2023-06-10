#pragma once

#include "r2tm/r2tm_iItem.h"

namespace algorithm_insertion_sort_test
{
	class Basic : public r2tm::iItem
	{
	public:
		r2tm::TitleFunctionT GetTitleFunction() const override;
		r2tm::DoFunctionT GetDoFunction() const override;
	};
}