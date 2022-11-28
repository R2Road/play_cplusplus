#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace alignof_test
{
	class PrimitiveType : public r2cm::iItem, public r2cm::SingleTon<PrimitiveType>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Basic : public r2cm::iItem, public r2cm::SingleTon<Basic>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class MixedStruct : public r2cm::iItem, public r2cm::SingleTon<MixedStruct>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}