#pragma once

#include "r2_iNode.h"

namespace variadic_template_test
{
	class SizeOfArgs : public r2::iNode<SizeOfArgs>
	{
	public:
		static const char* GetTitle() { return "Variadic Template : Size Of Args"; }
		static void Do();
	};

	class PrintValues : public r2::iNode<PrintValues>
	{
	public:
		static const char* GetTitle() { return "Variadic Template : Print Types"; }
		static void Do();
	};

	class SumValues : public r2::iNode<SumValues>
	{
	public:
		static const char* GetTitle() { return "Variadic Template : Sum Values"; }
		static void Do();
	};

	class SubtractValues : public r2::iNode<SubtractValues>
	{
	public:
		static const char* GetTitle() { return "Variadic Template : Subtract Values"; }
		static void Do();
	};
}