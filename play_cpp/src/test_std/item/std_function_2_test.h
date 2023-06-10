#pragma once

#include "r2tm/r2tm_iItem.h"

namespace std_function_2_test
{
	class Equality_STDBind_1 : public r2tm::iItem
	{
	public:
		r2tm::TitleFunctionT GetTitleFunction() const override;
		r2tm::DoFunctionT GetDoFunction() const override;
	};
}