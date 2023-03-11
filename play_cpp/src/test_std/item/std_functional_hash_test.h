#pragma once

#include "r2cm/r2cm_iItem.h"

namespace std_functional_hash_test
{
	class Basic : public r2cm::iItem
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() const override;
	};
}