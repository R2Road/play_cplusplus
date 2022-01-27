#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace c_time_test
{
	class Basic : public r2::iTest, public r2::SingleTon<Basic>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class Y_M_D_H_S : public r2::iTest, public r2::SingleTon<Y_M_D_H_S>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class Clock : public r2::iTest, public r2::SingleTon<Clock>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}