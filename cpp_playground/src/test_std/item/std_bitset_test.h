#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace std_bitset_test
{
	class All_Any_None : public r2cm::iItem, public r2cm::SingleTon<All_Any_None>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Set_And_Test : public r2cm::iItem, public r2cm::SingleTon<Set_And_Test>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Size : public r2cm::iItem, public r2cm::SingleTon<Size>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Operator : public r2cm::iItem, public r2cm::SingleTon<Operator>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}