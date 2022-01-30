#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace algorithm_astar_test
{
	class Basic : public r2::iTest, public r2::SingleTon<Basic>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class UseSTDListSplice : public r2::iTest, public r2::SingleTon<UseSTDListSplice>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class UseSTDListSplice_And_STDVectorResultPath : public r2::iTest, public r2::SingleTon<UseSTDListSplice_And_STDVectorResultPath>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
	class UseSTDListSplice_And_STDVectorResultPath_DecreaseCloseList : public r2::iTest, public r2::SingleTon<UseSTDListSplice_And_STDVectorResultPath_DecreaseCloseList>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class UseCostMap : public r2::iTest, public r2::SingleTon<UseCostMap>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
	class UseCostMap_And_TinyData : public r2::iTest, public r2::SingleTon<UseCostMap_And_TinyData>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class Use_ArrayBasedList_CostMap_STDVectorResultPath : public r2::iTest, public r2::SingleTon<Use_ArrayBasedList_CostMap_STDVectorResultPath>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};



	class PerformanceTest : public r2::iTest, public r2::SingleTon<PerformanceTest>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}