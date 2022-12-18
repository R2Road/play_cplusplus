#pragma once

#include "r2cm/r2cm_iItem.h"

namespace c_system_test
{
	class Pause : public r2cm::iItem
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() const override;
	};
}