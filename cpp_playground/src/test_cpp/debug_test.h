#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace debug_test
{
	class PredefinedMacro : public r2::iItem, public r2::SingleTon<PredefinedMacro>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class OutPutDebugString : public r2::iItem, public r2::SingleTon<OutPutDebugString>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class Assertion : public r2::iItem, public r2::SingleTon<Assertion>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class DebugBreak : public r2::iItem, public r2::SingleTon<DebugBreak>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class MyAssertion : public r2::iItem, public r2::SingleTon<MyAssertion>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}