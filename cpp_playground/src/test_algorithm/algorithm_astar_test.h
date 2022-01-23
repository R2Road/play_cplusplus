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
}