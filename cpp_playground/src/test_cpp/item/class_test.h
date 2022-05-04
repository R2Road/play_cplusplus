#pragma once

#include "base/r2cm_iItem.h"
#include "r2/r2_Singleton.h"

namespace class_test
{
	class Braces : public r2cm::iItem, public r2::SingleTon<Braces>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class PrintName : public r2cm::iItem, public r2::SingleTon<PrintName>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class PrivateInheritance_1 : public r2cm::iItem, public r2::SingleTon<PrivateInheritance_1>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
	class PrivateInheritance_2 : public r2cm::iItem, public r2::SingleTon<PrivateInheritance_2>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class MemberAdress : public r2cm::iItem, public r2::SingleTon<MemberAdress>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}