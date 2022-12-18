#pragma once

#include "r2cm/r2cm_iItem.h"

namespace std_function_2_test
{
	class Equality_STDBind_1 : public r2cm::iItem
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() const override;
	};
}