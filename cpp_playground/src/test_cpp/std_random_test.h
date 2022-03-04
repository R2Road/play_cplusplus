#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace std_random_test
{
	class Basic : public r2cm::iItem, public r2::SingleTon<Basic>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};



	class StatusSaveAndLoad : public r2cm::iItem, public r2::SingleTon<StatusSaveAndLoad>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};



	class DiscreateDistribution : public r2cm::iItem, public r2::SingleTon<DiscreateDistribution>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}