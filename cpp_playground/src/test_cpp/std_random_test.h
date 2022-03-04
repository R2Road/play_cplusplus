#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace std_random_test
{
	class Basic : public r2::iItem, public r2::SingleTon<Basic>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};



	class StatusSaveAndLoad : public r2::iItem, public r2::SingleTon<StatusSaveAndLoad>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};



	class DiscreateDistribution : public r2::iItem, public r2::SingleTon<DiscreateDistribution>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}