#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace vector3_test
{
	class OperatorPlus : public r2::iTest, public r2::SingleTon<OperatorPlus>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
	class OperatorPlusEqual : public r2::iTest, public r2::SingleTon<OperatorPlusEqual>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class OperatorMinus : public r2::iTest, public r2::SingleTon<OperatorMinus>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
	class OperatorMinusEqual : public r2::iTest, public r2::SingleTon<OperatorMinusEqual>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}