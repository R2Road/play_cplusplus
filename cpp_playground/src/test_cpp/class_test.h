#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace class_test
{
	class Braces : public r2::iTest, public r2::SingleTon<Braces>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class PrintName : public r2::iTest, public r2::SingleTon<PrintName>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class PrivateInheritance_1 : public r2::iTest, public r2::SingleTon<PrivateInheritance_1>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
	class PrivateInheritance_2 : public r2::iTest, public r2::SingleTon<PrivateInheritance_2>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class MemberAdress : public r2::iTest, public r2::SingleTon<MemberAdress>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}