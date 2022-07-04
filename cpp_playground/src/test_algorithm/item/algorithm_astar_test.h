#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace algorithm_astar_test
{
	class Basic : public r2cm::iItem, public r2cm::SingleTon<Basic>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Use_STDListSplice : public r2cm::iItem, public r2cm::SingleTon<Use_STDListSplice>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Use_STDListSplice_STDVectorResultPath : public r2cm::iItem, public r2cm::SingleTon<Use_STDListSplice_STDVectorResultPath>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
	class Use_STDListSplice_DecreaseCloseList_STDVectorResultPath : public r2cm::iItem, public r2cm::SingleTon<Use_STDListSplice_DecreaseCloseList_STDVectorResultPath>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Use_CostMap_STDListSplice_STDVectorResultPath : public r2cm::iItem, public r2cm::SingleTon<Use_CostMap_STDListSplice_STDVectorResultPath>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
	class Use_TinyCostMap_STDListSplice_STDVectorResultPath : public r2cm::iItem, public r2cm::SingleTon<Use_TinyCostMap_STDListSplice_STDVectorResultPath>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Use_ArrayBasedList_TinyCostMap_STDVectorResultPath : public r2cm::iItem, public r2cm::SingleTon<Use_ArrayBasedList_TinyCostMap_STDVectorResultPath>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};



	class PerformanceTest : public r2cm::iItem, public r2cm::SingleTon<PerformanceTest>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}