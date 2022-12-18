#pragma once

#include "r2cm/r2cm_iItem.h"

namespace cpp_align_test
{
	class AlignAs : public r2cm::iItem
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() const override;
	};
}