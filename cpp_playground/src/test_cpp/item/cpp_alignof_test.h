#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace cpp_alignof_test
{
	class PrimitiveType : public r2cm::iItem, public r2cm::SingleTon<PrimitiveType>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class STDContainer : public r2cm::iItem, public r2cm::SingleTon<STDContainer>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Struct : public r2cm::iItem, public r2cm::SingleTon<Struct>
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