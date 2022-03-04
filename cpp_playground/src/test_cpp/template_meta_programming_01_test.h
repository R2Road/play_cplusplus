#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace template_meta_programming_test
{
	class CalculateFactorial : public r2cm::iItem, public r2::SingleTon<CalculateFactorial>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};



	class GreatestCommonDivisor : public r2cm::iItem, public r2::SingleTon<GreatestCommonDivisor>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};



	class BasicRatio : public r2cm::iItem, public r2::SingleTon<BasicRatio>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
	class SumBasicRatio : public r2cm::iItem, public r2::SingleTon<SumBasicRatio>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
	class RatioWithGCD : public r2cm::iItem, public r2::SingleTon<RatioWithGCD>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
	class SumRatioWithGCD : public r2cm::iItem, public r2::SingleTon<SumRatioWithGCD>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
	class SumRatioAndOperator1 : public r2cm::iItem, public r2::SingleTon<SumRatioAndOperator1>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
	class SumRatioAndOperator2 : public r2cm::iItem, public r2::SingleTon<SumRatioAndOperator2>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}