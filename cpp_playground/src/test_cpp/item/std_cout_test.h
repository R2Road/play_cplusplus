#pragma once

#include "base/r2cm_iItem.h"
#include "r2/r2_Singleton.h"

namespace std_cout_test
{
	class FMTStatus : public r2cm::iItem, public r2::SingleTon<FMTStatus>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class NumberFormat_1 : public r2cm::iItem, public r2::SingleTon<NumberFormat_1>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class NumberFormat_2 : public r2cm::iItem, public r2::SingleTon<NumberFormat_2>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class NumberFormat_3 : public r2cm::iItem, public r2::SingleTon<NumberFormat_3>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class NumberFormat_4 : public r2cm::iItem, public r2::SingleTon<NumberFormat_4>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class Align : public r2cm::iItem, public r2::SingleTon<Align>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class Flag : public r2cm::iItem, public r2::SingleTon<Flag>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class BoolAlpha : public r2cm::iItem, public r2::SingleTon<BoolAlpha>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}