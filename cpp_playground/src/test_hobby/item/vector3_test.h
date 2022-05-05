#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2/r2_Singleton.h"

namespace vector3_test
{
	class OperatorPlus : public r2cm::iItem, public r2::SingleTon<OperatorPlus>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
	class OperatorPlusEqual : public r2cm::iItem, public r2::SingleTon<OperatorPlusEqual>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class OperatorMinus : public r2cm::iItem, public r2::SingleTon<OperatorMinus>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
	class OperatorMinusEqual : public r2cm::iItem, public r2::SingleTon<OperatorMinusEqual>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class OperatorMultiply_With_Scalar : public r2cm::iItem, public r2::SingleTon<OperatorMultiply_With_Scalar>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
	class OperatorMultiplyEqual_With_Scalar : public r2cm::iItem, public r2::SingleTon<OperatorMultiplyEqual_With_Scalar>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}