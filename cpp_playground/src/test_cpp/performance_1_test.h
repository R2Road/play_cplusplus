#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace performance_1_test
{
	class IncrementOperator : public r2::iItem, public r2::SingleTon<IncrementOperator>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class Loop : public r2::iItem, public r2::SingleTon<Loop>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
	class LoopWithBuildInArray : public r2::iItem, public r2::SingleTon<LoopWithBuildInArray>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
	class LoopWithSTDArray : public r2::iItem, public r2::SingleTon<LoopWithSTDArray>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class CompareIteratorOperator : public r2::iItem, public r2::SingleTon<CompareIteratorOperator>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}