#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace std_optional_test
{
	class Basic : public r2::iTest, public r2::SingleTon<Basic>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class Constructor : public r2::iTest, public r2::SingleTon<Constructor>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class Basic_discard : public r2::iTest, public r2::SingleTon<Basic_discard>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}