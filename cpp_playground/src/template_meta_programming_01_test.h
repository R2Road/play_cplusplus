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



	class RatioBasic : public r2::iTest, public r2::SingleTon<RatioBasic>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};
}