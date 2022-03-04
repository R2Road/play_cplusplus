#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace std_memory_test
{
	class SharedPointer : public r2::iItem, public r2::SingleTon<SharedPointer>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class UniquePointer : public r2::iItem, public r2::SingleTon<UniquePointer>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}