#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace thread_test
{
	class Basic : public r2::iTest, public r2::SingleTon<Basic>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class Declaration : public r2::iTest, public r2::SingleTon<Declaration>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class CopyAssaignment : public r2::iTest, public r2::SingleTon<CopyAssaignment>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class WaitProcess_SleepFor : public r2::iTest, public r2::SingleTon<WaitProcess_SleepFor>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class WaitProcess_Yield : public r2::iTest, public r2::SingleTon<WaitProcess_Yield>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}