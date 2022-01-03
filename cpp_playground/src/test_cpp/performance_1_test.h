#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace performance_1_test
{
	class IncrementOperator : public r2::iTest, public r2::SingleTon<IncrementOperator>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class Loop : public r2::iTest, public r2::SingleTon<Loop>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class LoopWithArray : public r2::iTest, public r2::SingleTon<LoopWithArray>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}