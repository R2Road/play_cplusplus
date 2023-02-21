#pragma once

#include "r2cm/r2cm_iItem.h"

namespace c_random_test
{
	class Rand : public r2cm::iItem
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() const override;
	};
}