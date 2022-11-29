#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace cpp_align_test
{
	class AlignAs : public r2cm::iItem, public r2cm::SingleTon<AlignAs>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}