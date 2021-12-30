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

	class LockFreeTest1 : public r2::iTest, public r2::SingleTon<LockFreeTest1>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class LockFreeTest2 : public r2::iTest, public r2::SingleTon<LockFreeTest2>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}