#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace debug_test
{
	class PredefinedMacro : public r2::iItem, public r2::SingleTon<PredefinedMacro>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class OutPutDebugString : public r2::iItem, public r2::SingleTon<OutPutDebugString>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class Assertion : public r2::iItem, public r2::SingleTon<Assertion>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class DebugBreak : public r2::iItem, public r2::SingleTon<DebugBreak>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class MyAssertion : public r2::iItem, public r2::SingleTon<MyAssertion>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}