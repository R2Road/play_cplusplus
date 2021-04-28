#pragma once

#include "r2_iTest.h"
#include "r2_Singleton.h"

namespace memory_pool_test
{
	class Step01 : public r2::iTest, public r2::SingleTon<Step01>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};
}