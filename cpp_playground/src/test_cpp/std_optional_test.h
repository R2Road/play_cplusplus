#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace std_optional_test
{
	class Basic : public r2::iItem, public r2::SingleTon<Basic>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class Constructor : public r2::iItem, public r2::SingleTon<Constructor>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class Reference : public r2::iItem, public r2::SingleTon<Reference>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}