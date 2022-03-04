#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace c_random_test
{
	class Rand : public r2::iItem, public r2::SingleTon<Rand>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}