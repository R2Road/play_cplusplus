#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace atomic_test
{
	class IsLockFree : public r2cm::iItem, public r2::SingleTon<IsLockFree>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class LockFreeTest1 : public r2cm::iItem, public r2::SingleTon<LockFreeTest1>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class LockFreeTest2 : public r2cm::iItem, public r2::SingleTon<LockFreeTest2>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}