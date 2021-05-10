#pragma once

#include "r2_iTest.h"
#include "r2_Singleton.h"

namespace lambda_test
{
	class CaptureValue : public r2::iTest, public r2::SingleTon<CaptureValue>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};

	class CaptureReference : public r2::iTest, public r2::SingleTon<CaptureReference>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};

	class CaptureUniquePtr : public r2::iTest, public r2::SingleTon<CaptureUniquePtr>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};

	class CaptureValueWithMutable : public r2::iTest, public r2::SingleTon<CaptureValueWithMutable>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};
}