#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace lambda_test
{
	class CaptureValue : public r2::iTest, public r2::SingleTon<CaptureValue>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class CaptureValueWithMutable : public r2::iTest, public r2::SingleTon<CaptureValueWithMutable>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class CaptureReference : public r2::iTest, public r2::SingleTon<CaptureReference>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class CaptureUniquePtr : public r2::iTest, public r2::SingleTon<CaptureUniquePtr>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class CaptureValueWithAssign : public r2::iTest, public r2::SingleTon<CaptureValueWithAssign>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}