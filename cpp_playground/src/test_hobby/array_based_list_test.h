#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace array_based_list_test
{
	class Basic_1 : public r2::iTest, public r2::SingleTon<Basic_1>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class Basic_2 : public r2::iTest, public r2::SingleTon<Basic_2>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class Basic_3 : public r2::iTest, public r2::SingleTon<Basic_3>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class Basic_4 : public r2::iTest, public r2::SingleTon<Basic_4>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}