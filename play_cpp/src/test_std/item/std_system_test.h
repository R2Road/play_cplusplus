#pragma once

#include "r2tm/r2tm_iItem.h"

namespace std_system_test
{
	class Demo : public r2tm::iItem
	{
	public:
		r2tm::TitleFunctionT GetTitleFunction() const override;
		r2tm::DoFunctionT GetDoFunction() const override;
	};
}