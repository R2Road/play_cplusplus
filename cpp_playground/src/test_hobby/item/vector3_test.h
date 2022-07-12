#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace vector3_test
{
	class Declaration : public r2cm::iItem, public r2cm::SingleTon<Declaration>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class OperatorPlus : public r2cm::iItem, public r2cm::SingleTon<OperatorPlus>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
	class OperatorPlusEqual : public r2cm::iItem, public r2cm::SingleTon<OperatorPlusEqual>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class OperatorMinus : public r2cm::iItem, public r2cm::SingleTon<OperatorMinus>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
	class OperatorMinusEqual : public r2cm::iItem, public r2cm::SingleTon<OperatorMinusEqual>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class OperatorMultiply_With_Scalar : public r2cm::iItem, public r2cm::SingleTon<OperatorMultiply_With_Scalar>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
	class OperatorMultiplyEqual_With_Scalar : public r2cm::iItem, public r2cm::SingleTon<OperatorMultiplyEqual_With_Scalar>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}