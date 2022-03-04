#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace c_time_test
{
	class Basic : public r2::iItem, public r2::SingleTon<Basic>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class Y_M_D_H_S : public r2::iItem, public r2::SingleTon<Y_M_D_H_S>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class Clock : public r2::iItem, public r2::SingleTon<Clock>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}