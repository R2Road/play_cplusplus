#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace c_struct_test
{
	class Array_Size_0 : public r2cm::iItem, public r2cm::SingleTon<Array_Size_0>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}