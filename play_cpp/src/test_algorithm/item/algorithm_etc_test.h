#pragma once

#include "r2cm/r2cm_iItem.h"

namespace algorithm_etc_test
{
	class DJB2 : public r2cm::iItem
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() const override;
	};
}