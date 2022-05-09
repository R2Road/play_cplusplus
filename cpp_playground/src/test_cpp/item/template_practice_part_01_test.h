#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace template_practice_part_01_test
{
	class BufferWithTemplate : public r2cm::iItem, public r2cm::SingleTon<BufferWithTemplate>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class VaridicMax : public r2cm::iItem, public r2cm::SingleTon<VaridicMax>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}