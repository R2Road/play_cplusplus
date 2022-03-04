#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace memory_pool_test
{
	class Step01 : public r2::iItem, public r2::SingleTon<Step01>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}