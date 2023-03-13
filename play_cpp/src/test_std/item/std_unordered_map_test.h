#pragma once

#include "r2cm/r2cm_iItem.h"

namespace std_unordered_map_test
{
	class CString : public r2cm::iItem
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() const override;
	};
}