#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace variadic_template_test
{
	class SizeOfArgs : public r2::iItem, public r2::SingleTon<SizeOfArgs>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class PrintValues : public r2::iItem, public r2::SingleTon<PrintValues>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class SumValues : public r2::iItem, public r2::SingleTon<SumValues>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class SubtractValues : public r2::iItem, public r2::SingleTon<SubtractValues>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}