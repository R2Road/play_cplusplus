#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace memory_pool_test
{
	class MemoryBlock_Declaration : public r2cm::iItem, public r2cm::SingleTon<MemoryBlock_Declaration>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class MemoryBlock_New_Fundamental_Type : public r2cm::iItem, public r2cm::SingleTon<MemoryBlock_New_Fundamental_Type>
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

	class MemoryPool_New : public r2cm::iItem, public r2cm::SingleTon<MemoryPool_New>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}