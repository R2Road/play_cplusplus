#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace memory_pool_test
{
	class MemoryAllocation : public r2cm::iItem, public r2cm::SingleTon<MemoryAllocation>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class MemoryPool_Declaration : public r2cm::iItem, public r2cm::SingleTon<MemoryPool_Declaration>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}