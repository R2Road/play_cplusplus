#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace various_debug_test
{
	class PredefinedMacro : public r2cm::iItem, public r2cm::SingleTon<PredefinedMacro>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class OutPutDebugString : public r2cm::iItem, public r2cm::SingleTon<OutPutDebugString>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Assertion : public r2cm::iItem, public r2cm::SingleTon<Assertion>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class DebugBreak : public r2cm::iItem, public r2cm::SingleTon<DebugBreak>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class MyAssertion : public r2cm::iItem, public r2cm::SingleTon<MyAssertion>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class SimpleLog : public r2cm::iItem, public r2cm::SingleTon<SimpleLog>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}