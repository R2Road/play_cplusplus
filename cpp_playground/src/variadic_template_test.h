#pragma once

#include "r2_iNode.h"
#include "r2_Singleton.h"

namespace variadic_template_test
{
	class SizeOfArgs : public r2::iNode, public r2::SingleTon<SizeOfArgs>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		r2::eTestResult Do() override;
	};

	class PrintValues : public r2::iNode, public r2::SingleTon<PrintValues>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		r2::eTestResult Do() override;
	};

	class SumValues : public r2::iNode, public r2::SingleTon<SumValues>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		r2::eTestResult Do() override;
	};

	class SubtractValues : public r2::iNode, public r2::SingleTon<SubtractValues>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		r2::eTestResult Do() override;
	};
}