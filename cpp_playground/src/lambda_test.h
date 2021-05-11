#pragma once

#include "r2_iTest.h"
#include "r2_Singleton.h"

namespace lambda_test
{
	class CaptureValue : public r2::iTest, public r2::SingleTon<CaptureValue>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() const override;
	};

	class CaptureValueWithMutable : public r2::iTest, public r2::SingleTon<CaptureValueWithMutable>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() const override;
	};

	class CaptureReference : public r2::iTest, public r2::SingleTon<CaptureReference>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() const override;
	};

	class CaptureUniquePtr : public r2::iTest, public r2::SingleTon<CaptureUniquePtr>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() const override;
	};
}