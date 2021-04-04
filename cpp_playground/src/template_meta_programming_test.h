#pragma once

#include "r2_iNode.h"

namespace template_meta_programming_test
{
	class CalculateFactorial : public r2::iNode<CalculateFactorial>
	{
	public:
		static const char* GetTitle() { return "TMP : Factorial"; }
		static void Do();
	};


	class Integer2String : public r2::iNode<Integer2String>
	{
	public:
		static const char* GetTitle() { return "TMP : Integer 2 String"; }
		static void Do();
	};


	class CalculatePlaceValue : public r2::iNode<CalculatePlaceValue>
	{
	public:
		static const char* GetTitle() { return "TMP : Place Value"; }
		static void Do();
	};


	class Integer2String_II : public r2::iNode<Integer2String_II>
	{
	public:
		static const char* GetTitle() { return "TMP : Integer 2 String II"; }
		static void Do();
	};


	class MultiTypePackage : public r2::iNode<MultiTypePackage>
	{
	public:
		static const char* GetTitle() { return "TMP : Multi Type Package"; }
		static void Do();
	};
}