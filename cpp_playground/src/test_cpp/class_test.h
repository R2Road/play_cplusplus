#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

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

	class PrivateInheritance : public r2::iTest, public r2::SingleTon<PrivateInheritance>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}