#pragma once

namespace variadic_template_test
{
	class PrintValues
	{
	public:
		static const char* GetTitle() { return "Variadic Template : Print Types"; }
		static void Do();
	};

	class SumValues
	{
	public:
		static const char* GetTitle() { return "Variadic Template : Sum Values"; }
		static void Do();
	};

	class SubtractValues
	{
	public:
		static const char* GetTitle() { return "Variadic Template : Subtract Values"; }
		static void Do();
	};
}