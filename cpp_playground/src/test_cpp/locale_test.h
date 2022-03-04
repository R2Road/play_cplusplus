#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace locale_test
{
	class Basic : public r2::iItem, public r2::SingleTon<Basic>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}