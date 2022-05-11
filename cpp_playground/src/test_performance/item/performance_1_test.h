#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace performance_1_test
{
	class IncrementOperator : public r2cm::iItem, public r2cm::SingleTon<IncrementOperator>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class Loop : public r2cm::iItem, public r2cm::SingleTon<Loop>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
	class LoopWithBuildInArray : public r2cm::iItem, public r2cm::SingleTon<LoopWithBuildInArray>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
	class LoopWithSTDArray : public r2cm::iItem, public r2cm::SingleTon<LoopWithSTDArray>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class CompareIteratorOperator : public r2cm::iItem, public r2cm::SingleTon<CompareIteratorOperator>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}