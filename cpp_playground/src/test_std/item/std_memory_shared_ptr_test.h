#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace std_memory_shared_ptr_test
{
	class SharedPointer : public r2cm::iItem, public r2cm::SingleTon<SharedPointer>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class SharedPointer_MakeShared_And_Memory : public r2cm::iItem, public r2cm::SingleTon<SharedPointer_MakeShared_And_Memory>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}