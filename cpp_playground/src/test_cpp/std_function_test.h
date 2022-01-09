#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace std_function_test
{
	class Equality_0 : public r2::iTest, public r2::SingleTon<Equality_0>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class Equality_1 : public r2::iTest, public r2::SingleTon<Equality_1>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class Equality_2 : public r2::iTest, public r2::SingleTon<Equality_2>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}