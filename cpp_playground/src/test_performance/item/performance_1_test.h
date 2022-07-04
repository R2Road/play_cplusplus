#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace performance_1_test
{
	class IncrementOperator : public r2cm::iItem, public r2cm::SingleTon<IncrementOperator>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Loop : public r2cm::iItem, public r2cm::SingleTon<Loop>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
	class LoopWithBuildInArray : public r2cm::iItem, public r2cm::SingleTon<LoopWithBuildInArray>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
	class LoopWithSTDArray : public r2cm::iItem, public r2cm::SingleTon<LoopWithSTDArray>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class CompareIteratorOperator : public r2cm::iItem, public r2cm::SingleTon<CompareIteratorOperator>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}