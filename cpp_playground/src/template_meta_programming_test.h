#pragma once

#include "r2_iNode.h"
#include "r2_Singleton.h"

namespace template_meta_programming_test
{
	class CalculateFactorial : public r2::iNode, public r2::SingleTon<CalculateFactorial>
	{
	public:
		const char* GetTitle() const override { return "TMP : Factorial"; }
		r2::eTestResult Do() override;
	};


	class Integer2String : public r2::iNode, public r2::SingleTon<Integer2String>
	{
	public:
		const char* GetTitle() const override { return "TMP : Integer 2 String"; }
		r2::eTestResult Do() override;
	};


	class CalculatePlaceValue : public r2::iNode, public r2::SingleTon<CalculatePlaceValue>
	{
	public:
		const char* GetTitle() const override { return "TMP : Place Value"; }
		r2::eTestResult Do() override;
	};


	class Integer2String_II : public r2::iNode, public r2::SingleTon<Integer2String_II>
	{
	public:
		const char* GetTitle() const override { return "TMP : Integer 2 String II"; }
		r2::eTestResult Do() override;
	};


	class MultiTypePackage : public r2::iNode, public r2::SingleTon<MultiTypePackage>
	{
	public:
		const char* GetTitle() const override { return "TMP : Multi Type Package"; }
		r2::eTestResult Do() override;
	};
}