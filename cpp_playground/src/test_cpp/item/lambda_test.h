#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2/r2_Singleton.h"

namespace lambda_test
{
	class CaptureValue : public r2cm::iItem, public r2::SingleTon<CaptureValue>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class CaptureValueWithMutable : public r2cm::iItem, public r2::SingleTon<CaptureValueWithMutable>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class CaptureReference : public r2cm::iItem, public r2::SingleTon<CaptureReference>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class CaptureUniquePtr : public r2cm::iItem, public r2::SingleTon<CaptureUniquePtr>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class CaptureValueWithAssign : public r2cm::iItem, public r2::SingleTon<CaptureValueWithAssign>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}