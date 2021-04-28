#pragma once

#include "r2_iTest.h"
#include "r2_Singleton.h"

namespace variadic_template_test
{
	class SizeOfArgs : public r2::iTest, public r2::SingleTon<SizeOfArgs>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};

	class PrintValues : public r2::iTest, public r2::SingleTon<PrintValues>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};

	class SumValues : public r2::iTest, public r2::SingleTon<SumValues>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};

	class SubtractValues : public r2::iTest, public r2::SingleTon<SubtractValues>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};
}