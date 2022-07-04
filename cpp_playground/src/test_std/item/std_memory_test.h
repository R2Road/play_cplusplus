#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace std_memory_test
{
	class SharedPointer : public r2cm::iItem, public r2cm::SingleTon<SharedPointer>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class UniquePointer : public r2cm::iItem, public r2cm::SingleTon<UniquePointer>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}