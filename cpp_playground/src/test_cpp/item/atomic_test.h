#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace atomic_test
{
	class IsLockFree : public r2cm::iItem, public r2cm::SingleTon<IsLockFree>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class LockFreeTest1 : public r2cm::iItem, public r2cm::SingleTon<LockFreeTest1>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class LockFreeTest2 : public r2cm::iItem, public r2cm::SingleTon<LockFreeTest2>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}