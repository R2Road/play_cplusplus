#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace memory_pool_test
{
	class Step01 : public r2::iTest, public r2::SingleTon<Step01>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}