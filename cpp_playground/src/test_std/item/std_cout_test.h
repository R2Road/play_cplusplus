#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace std_cout_test
{
	class Basic : public r2cm::iItem, public r2cm::SingleTon<Basic>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class FMTStatus : public r2cm::iItem, public r2cm::SingleTon<FMTStatus>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class NumberFormat_1 : public r2cm::iItem, public r2cm::SingleTon<NumberFormat_1>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class NumberFormat_2 : public r2cm::iItem, public r2cm::SingleTon<NumberFormat_2>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class NumberFormat_3 : public r2cm::iItem, public r2cm::SingleTon<NumberFormat_3>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class NumberFormat_4 : public r2cm::iItem, public r2cm::SingleTon<NumberFormat_4>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class Align : public r2cm::iItem, public r2cm::SingleTon<Align>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class Flag : public r2cm::iItem, public r2cm::SingleTon<Flag>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class BoolAlpha : public r2cm::iItem, public r2cm::SingleTon<BoolAlpha>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class UserDefinedType : public r2cm::iItem, public r2cm::SingleTon<UserDefinedType>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}