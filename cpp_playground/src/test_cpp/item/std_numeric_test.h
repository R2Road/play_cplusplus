#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace std_numeric_test
{
	class Accumulate_Number : public r2cm::iItem, public r2cm::SingleTon<Accumulate_Number>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class Accumulate_String : public r2cm::iItem, public r2cm::SingleTon<Accumulate_String>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class Partial_Sum: public r2cm::iItem, public r2cm::SingleTon<Partial_Sum>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class FillSequenceNumber : public r2cm::iItem, public r2cm::SingleTon<FillSequenceNumber>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}