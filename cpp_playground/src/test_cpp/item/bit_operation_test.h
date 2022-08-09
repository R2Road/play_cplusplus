#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace bit_operation_test
{
	class Basic : public r2cm::iItem, public r2cm::SingleTon<Basic>
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

	class Complement : public r2cm::iItem, public r2cm::SingleTon<Complement>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Add_Remove_Toggle : public r2cm::iItem, public r2cm::SingleTon<Add_Remove_Toggle>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Mask : public r2cm::iItem, public r2cm::SingleTon<Mask>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class XOR_Swap : public r2cm::iItem, public r2cm::SingleTon<XOR_Swap>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};


	class ETC_1 : public r2cm::iItem, public r2cm::SingleTon<ETC_1>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Plus : public r2cm::iItem, public r2cm::SingleTon<Plus>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Plus_2 : public r2cm::iItem, public r2cm::SingleTon<Plus_2>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}