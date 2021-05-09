#pragma once

#include "r2_iTest.h"
#include "r2_Singleton.h"

namespace lambda_test
{
	class Capture : public r2::iTest, public r2::SingleTon<Capture>
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

	class TestETC : public r2::iTest, public r2::SingleTon<TestETC>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};
}