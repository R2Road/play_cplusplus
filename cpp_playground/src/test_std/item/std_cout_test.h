#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace std_cout_test
{
	class Basic : public r2cm::iItem, public r2cm::SingleTon<Basic>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class FMTStatus : public r2cm::iItem, public r2cm::SingleTon<FMTStatus>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class NumberFormat_1 : public r2cm::iItem, public r2cm::SingleTon<NumberFormat_1>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class NumberFormat_2 : public r2cm::iItem, public r2cm::SingleTon<NumberFormat_2>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class NumberFormat_3 : public r2cm::iItem, public r2cm::SingleTon<NumberFormat_3>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class NumberFormat_4 : public r2cm::iItem, public r2cm::SingleTon<NumberFormat_4>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Align : public r2cm::iItem, public r2cm::SingleTon<Align>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Flag : public r2cm::iItem, public r2cm::SingleTon<Flag>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class BoolAlpha : public r2cm::iItem, public r2cm::SingleTon<BoolAlpha>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class UserDefinedType : public r2cm::iItem, public r2cm::SingleTon<UserDefinedType>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}