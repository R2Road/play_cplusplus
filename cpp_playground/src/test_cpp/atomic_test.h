#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace atomic_test
{
	class IsLockFree : public r2::iTest, public r2::SingleTon<IsLockFree>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}