#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace random_test
{
	class Basic : public r2::iTest, public r2::SingleTon<Basic>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};



	class StatusSaveAndLoad : public r2::iTest, public r2::SingleTon<StatusSaveAndLoad>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};



	class DiscreateDistribution : public r2::iTest, public r2::SingleTon<DiscreateDistribution>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}