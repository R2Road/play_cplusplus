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

	class CTime : public r2::iTest, public r2::SingleTon<CTime>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}