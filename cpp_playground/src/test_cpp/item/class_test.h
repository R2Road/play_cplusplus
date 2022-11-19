#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace class_test
{
	class Method : public r2cm::iItem, public r2cm::SingleTon<Method>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class MemberValue : public r2cm::iItem, public r2cm::SingleTon<MemberValue>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Braces : public r2cm::iItem, public r2cm::SingleTon<Braces>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class PrintName : public r2cm::iItem, public r2cm::SingleTon<PrintName>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class PrivateInheritance_1 : public r2cm::iItem, public r2cm::SingleTon<PrivateInheritance_1>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
	class PrivateInheritance_2 : public r2cm::iItem, public r2cm::SingleTon<PrivateInheritance_2>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class ImplicitTypeConversion : public r2cm::iItem, public r2cm::SingleTon<ImplicitTypeConversion>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};



	class MemberAdress_Value : public r2cm::iItem, public r2cm::SingleTon<MemberAdress_Value>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class MemberAdress_Method : public r2cm::iItem, public r2cm::SingleTon<MemberAdress_Method>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Offset_SingleInheritance : public r2cm::iItem, public r2cm::SingleTon<Offset_SingleInheritance>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Offset_MultipleInheritance : public r2cm::iItem, public r2cm::SingleTon<Offset_MultipleInheritance>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Offset_Singleton : public r2cm::iItem, public r2cm::SingleTon<Offset_Singleton>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}