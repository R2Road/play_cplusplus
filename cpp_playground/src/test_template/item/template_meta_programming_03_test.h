#pragma once

#include "r2cm/r2cm_iItem.h"

namespace template_meta_programming_test
{
	class MultiTypePackage : public r2cm::iItem
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() const override;
	};
}