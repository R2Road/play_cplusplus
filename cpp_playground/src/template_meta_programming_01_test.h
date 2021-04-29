#pragma once

#include "r2_iTest.h"
#include "r2_Singleton.h"

namespace template_meta_programming_test
{
	class CalculateFactorial : public r2::iTest, public r2::SingleTon<CalculateFactorial>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};



	class GreatestCommonDivisor : public r2::iTest, public r2::SingleTon<GreatestCommonDivisor>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};



	class BasicRatio : public r2::iTest, public r2::SingleTon<BasicRatio>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};
	class SumBasicRatio : public r2::iTest, public r2::SingleTon<SumBasicRatio>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};
	class RatioWithGCD : public r2::iTest, public r2::SingleTon<RatioWithGCD>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};
	class SumRatioWithGCD : public r2::iTest, public r2::SingleTon<SumRatioWithGCD>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};
	class SumRatioAndOperator : public r2::iTest, public r2::SingleTon<SumRatioAndOperator>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};
}