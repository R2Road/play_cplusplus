#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace variadic_template_test
{
	class SizeOfArgs : public r2cm::iItem, public r2cm::SingleTon<SizeOfArgs>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class PrintValues : public r2cm::iItem, public r2cm::SingleTon<PrintValues>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class SumValues : public r2cm::iItem, public r2cm::SingleTon<SumValues>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class SubtractValues : public r2cm::iItem, public r2cm::SingleTon<SubtractValues>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}