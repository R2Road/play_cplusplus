#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace numeric_test
{
	class Accumulate_Number : public r2::iTest, public r2::SingleTon<Accumulate_Number>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class Accumulate_String : public r2::iTest, public r2::SingleTon<Accumulate_String>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class Partial_Sum: public r2::iTest, public r2::SingleTon<Partial_Sum>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}