#pragma once

#include "r2cm/r2cm_iItem.h"

namespace template_practice_part_01_test
{
	class BufferWithTemplate : public r2cm::iItem
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() const override;
	};

	class VaridicMax : public r2cm::iItem
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() const override;
	};
}