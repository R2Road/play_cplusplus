#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace performance_2_test
{
	class LoopWithBuildInArray : public r2::iTest, public r2::SingleTon<LoopWithBuildInArray>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
	class LoopWithSTDArray : public r2::iTest, public r2::SingleTon<LoopWithSTDArray>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class VectorIteration: public r2::iTest, public r2::SingleTon<VectorIteration>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
	class ListIteration : public r2::iTest, public r2::SingleTon<ListIteration>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}