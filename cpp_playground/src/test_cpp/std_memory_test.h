#pragma once

#include "base/r2cm_iItem.h"
#include "r2/r2_Singleton.h"

namespace std_memory_test
{
	class SharedPointer : public r2cm::iItem, public r2::SingleTon<SharedPointer>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class UniquePointer : public r2cm::iItem, public r2::SingleTon<UniquePointer>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}