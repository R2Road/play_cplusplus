#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace std_memory_test
{
	class SharedPointer : public r2cm::iItem, public r2cm::SingleTon<SharedPointer>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class UniquePointer : public r2cm::iItem, public r2cm::SingleTon<UniquePointer>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}