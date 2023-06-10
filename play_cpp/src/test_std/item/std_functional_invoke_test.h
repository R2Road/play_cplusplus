#pragma once

#include "r2tm/r2tm_iItem.h"

namespace std_functional_invoke_test
{
	class Basic : public r2tm::iItem
	{
	public:
		r2tm::TitleFunctionT GetTitleFunction() const override;
		r2tm::DoFunctionT GetDoFunction() const override;
	};
}