#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace enum_test
{
	class Basic : public r2cm::iItem, public r2cm::SingleTon<Basic>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Cast : public r2cm::iItem, public r2cm::SingleTon<Cast>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class ConvertWithTemplate : public r2cm::iItem, public r2cm::SingleTon<ConvertWithTemplate>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class MakeEnumWithMacro : public r2cm::iItem, public r2cm::SingleTon<MakeEnumWithMacro>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class XMacro_1 : public r2cm::iItem, public r2cm::SingleTon<XMacro_1>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class XMacro_2 : public r2cm::iItem, public r2cm::SingleTon<XMacro_2>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}