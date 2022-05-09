#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace template_meta_programming_test
{
	class CalculateFactorial : public r2cm::iItem, public r2cm::SingleTon<CalculateFactorial>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};



	class GreatestCommonDivisor : public r2cm::iItem, public r2cm::SingleTon<GreatestCommonDivisor>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};



	class BasicRatio : public r2cm::iItem, public r2cm::SingleTon<BasicRatio>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
	class SumBasicRatio : public r2cm::iItem, public r2cm::SingleTon<SumBasicRatio>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
	class RatioWithGCD : public r2cm::iItem, public r2cm::SingleTon<RatioWithGCD>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
	class SumRatioWithGCD : public r2cm::iItem, public r2cm::SingleTon<SumRatioWithGCD>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
	class SumRatioAndOperator1 : public r2cm::iItem, public r2cm::SingleTon<SumRatioAndOperator1>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
	class SumRatioAndOperator2 : public r2cm::iItem, public r2cm::SingleTon<SumRatioAndOperator2>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}