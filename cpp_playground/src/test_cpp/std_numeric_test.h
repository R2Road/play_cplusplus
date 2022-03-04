#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace std_numeric_test
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

	class FillSequenceNumber : public r2::iTest, public r2::SingleTon<FillSequenceNumber>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}