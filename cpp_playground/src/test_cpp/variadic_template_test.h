#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace variadic_template_test
{
	class SizeOfArgs : public r2::iItem, public r2::SingleTon<SizeOfArgs>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class PrintValues : public r2::iItem, public r2::SingleTon<PrintValues>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class SumValues : public r2::iItem, public r2::SingleTon<SumValues>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class SubtractValues : public r2::iItem, public r2::SingleTon<SubtractValues>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}