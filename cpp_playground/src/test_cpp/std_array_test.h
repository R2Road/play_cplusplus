#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace std_array_test
{
	class Basic : public r2::iTest, public r2::SingleTon<Basic>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class Fill : public r2::iTest, public r2::SingleTon<Fill>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}