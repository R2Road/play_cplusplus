#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace algorithm_astar_test
{
	class Basic : public r2::iItem, public r2::SingleTon<Basic>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class Use_STDListSplice : public r2::iItem, public r2::SingleTon<Use_STDListSplice>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class Use_STDListSplice_STDVectorResultPath : public r2::iItem, public r2::SingleTon<Use_STDListSplice_STDVectorResultPath>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
	class Use_STDListSplice_DecreaseCloseList_STDVectorResultPath : public r2::iItem, public r2::SingleTon<Use_STDListSplice_DecreaseCloseList_STDVectorResultPath>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class Use_CostMap_STDListSplice_STDVectorResultPath : public r2::iItem, public r2::SingleTon<Use_CostMap_STDListSplice_STDVectorResultPath>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
	class Use_TinyCostMap_STDListSplice_STDVectorResultPath : public r2::iItem, public r2::SingleTon<Use_TinyCostMap_STDListSplice_STDVectorResultPath>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class Use_ArrayBasedList_TinyCostMap_STDVectorResultPath : public r2::iItem, public r2::SingleTon<Use_ArrayBasedList_TinyCostMap_STDVectorResultPath>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};



	class PerformanceTest : public r2::iItem, public r2::SingleTon<PerformanceTest>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}