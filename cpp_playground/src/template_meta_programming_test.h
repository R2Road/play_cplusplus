#pragma once

namespace template_meta_programming_test
{
	class CalculateFactorial
	{
	public:
		static const char* GetTitle() { return "TMP : Factorial"; }
		static void Do();
	};


	class Integer2String
	{
	public:
		static const char* GetTitle() { return "TMP : Integer 2 String"; }
		static void Do();
	};


	class CalculatePlaceValue
	{
	public:
		static const char* GetTitle() { return "TMP : Place Value"; }
		static void Do();
	};


	class Integer2String_II
	{
	public:
		static const char* GetTitle() { return "TMP : Integer 2 String II"; }
		static void Do();
	};
}