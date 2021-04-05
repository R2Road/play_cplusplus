#pragma once

#include "r2_iNode.h"
#include "r2_Singleton.h"

namespace variadic_template_test
{
	class SizeOfArgs : public r2::iNode, public r2::SingleTon<SizeOfArgs>
	{
	public:
		const char* GetTitle() const override { return "Variadic Template : Size Of Args"; }
		r2::eTestResult Do() override;
	};

	class PrintValues : public r2::iNode, public r2::SingleTon<PrintValues>
	{
	public:
		const char* GetTitle() const override { return "Variadic Template : Print Types"; }
		r2::eTestResult Do() override;
	};

	class SumValues : public r2::iNode, public r2::SingleTon<SumValues>
	{
	public:
		const char* GetTitle() const override { return "Variadic Template : Sum Values"; }
		r2::eTestResult Do() override;
	};

	class SubtractValues : public r2::iNode, public r2::SingleTon<SubtractValues>
	{
	public:
		const char* GetTitle() const override { return "Variadic Template : Subtract Values"; }
		r2::eTestResult Do() override;
	};
}