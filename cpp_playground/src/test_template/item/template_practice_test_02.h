#pragma once

#include "r2cm/r2cm_iItem.h"

namespace template_practice_test_02
{
	class Basic : public r2cm::iItem
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() const override;
	};
}