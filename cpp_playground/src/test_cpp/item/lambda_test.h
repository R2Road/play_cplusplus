#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace lambda_test
{
	class CaptureValue : public r2cm::iItem, public r2cm::SingleTon<CaptureValue>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class CaptureValueWithMutable : public r2cm::iItem, public r2cm::SingleTon<CaptureValueWithMutable>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class CaptureReference : public r2cm::iItem, public r2cm::SingleTon<CaptureReference>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class CaptureUniquePtr : public r2cm::iItem, public r2cm::SingleTon<CaptureUniquePtr>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class CaptureValueWithAssign : public r2cm::iItem, public r2cm::SingleTon<CaptureValueWithAssign>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}