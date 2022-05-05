#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2/r2_Singleton.h"

namespace algorithm_etc_test
{
	class DJB2 : public r2cm::iItem, public r2::SingleTon<DJB2>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}