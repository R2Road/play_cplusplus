#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace class_test
{
	class Braces : public r2cm::iItem, public r2cm::SingleTon<Braces>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class PrintName : public r2cm::iItem, public r2cm::SingleTon<PrintName>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class PrivateInheritance_1 : public r2cm::iItem, public r2cm::SingleTon<PrivateInheritance_1>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
	class PrivateInheritance_2 : public r2cm::iItem, public r2cm::SingleTon<PrivateInheritance_2>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class MemberAdress : public r2cm::iItem, public r2cm::SingleTon<MemberAdress>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}