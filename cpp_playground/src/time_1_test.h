#pragma once

#include "r2_iTest.h"
#include "r2_Singleton.h"

namespace time_test
{
	class Basic : public r2::iTest, public r2::SingleTon<Basic>
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