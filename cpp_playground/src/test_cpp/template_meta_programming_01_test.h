#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace template_meta_programming_test
{
	class CalculateFactorial : public r2::iTest, public r2::SingleTon<CalculateFactorial>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};



	class GreatestCommonDivisor : public r2::iTest, public r2::SingleTon<GreatestCommonDivisor>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};



	class BasicRatio : public r2::iTest, public r2::SingleTon<BasicRatio>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
	class SumBasicRatio : public r2::iTest, public r2::SingleTon<SumBasicRatio>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
	class RatioWithGCD : public r2::iTest, public r2::SingleTon<RatioWithGCD>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
	class SumRatioWithGCD : public r2::iTest, public r2::SingleTon<SumRatioWithGCD>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
	class SumRatioAndOperator1 : public r2::iTest, public r2::SingleTon<SumRatioAndOperator1>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
	class SumRatioAndOperator2 : public r2::iTest, public r2::SingleTon<SumRatioAndOperator2>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}