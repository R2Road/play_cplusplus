#pragma once

#include "r2_iNode.h"
#include "r2_Singleton.h"

namespace variadic_template_test
{
	class SizeOfArgs : public r2::iNode, public r2::SingleTon<SizeOfArgs>
	{
	public:
		const char* GetTitle() const override { return "Variadic Template : Size Of Args"; }
		void Do() override;
	};

	class PrintValues : public r2::iNode, public r2::SingleTon<PrintValues>
	{
	public:
		const char* GetTitle() const override { return "Variadic Template : Print Types"; }
		void Do() override;
	};

	class SumValues : public r2::iNode, public r2::SingleTon<SumValues>
	{
	public:
		const char* GetTitle() const override { return "Variadic Template : Sum Values"; }
		void Do() override;
	};

	class SubtractValues : public r2::iNode, public r2::SingleTon<SubtractValues>
	{
	public:
		const char* GetTitle() const override { return "Variadic Template : Subtract Values"; }
		void Do() override;
	};
}