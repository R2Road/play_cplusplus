#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace algorithm_etc_test
{
	class DJB2 : public r2cm::iItem, public r2cm::SingleTon<DJB2>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}