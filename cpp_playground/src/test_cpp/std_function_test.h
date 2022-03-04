#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace std_function_test
{
	class Equality_FunctionPointer_1 : public r2::iTest, public r2::SingleTon<Equality_FunctionPointer_1>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class Equality_FunctionPointer_2 : public r2::iTest, public r2::SingleTon<Equality_FunctionPointer_2>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class Equality_FunctionPointer_3 : public r2::iTest, public r2::SingleTon<Equality_FunctionPointer_3>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class Equality_Lambda_1 : public r2::iTest, public r2::SingleTon<Equality_Lambda_1>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}