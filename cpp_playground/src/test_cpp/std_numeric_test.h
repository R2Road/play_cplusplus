#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace std_numeric_test
{
	class Accumulate_Number : public r2cm::iItem, public r2::SingleTon<Accumulate_Number>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class Accumulate_String : public r2cm::iItem, public r2::SingleTon<Accumulate_String>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class Partial_Sum: public r2cm::iItem, public r2::SingleTon<Partial_Sum>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class FillSequenceNumber : public r2cm::iItem, public r2::SingleTon<FillSequenceNumber>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}