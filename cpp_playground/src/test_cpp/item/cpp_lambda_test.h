#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace cpp_lambda_test
{
	class Basic : public r2cm::iItem, public r2cm::SingleTon<Basic>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class CaptureValue : public r2cm::iItem, public r2cm::SingleTon<CaptureValue>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class CaptureValueWithMutable : public r2cm::iItem, public r2cm::SingleTon<CaptureValueWithMutable>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class CaptureReference : public r2cm::iItem, public r2cm::SingleTon<CaptureReference>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class CaptureUniquePtr : public r2cm::iItem, public r2cm::SingleTon<CaptureUniquePtr>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class CaptureValueWithAssign : public r2cm::iItem, public r2cm::SingleTon<CaptureValueWithAssign>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Size : public r2cm::iItem, public r2cm::SingleTon<Size>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Size_2 : public r2cm::iItem, public r2cm::SingleTon<Size_2>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Size_3 : public r2cm::iItem, public r2cm::SingleTon<Size_3>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}