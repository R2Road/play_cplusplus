#pragma once

#include "r2cm/r2cm_iItem.h"

namespace c_array_test
{
	class Init : public r2cm::iItem
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() const override;
	};
}