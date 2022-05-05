#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2/r2_Singleton.h"

namespace debug_test
{
	class PredefinedMacro : public r2cm::iItem, public r2::SingleTon<PredefinedMacro>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class OutPutDebugString : public r2cm::iItem, public r2::SingleTon<OutPutDebugString>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class Assertion : public r2cm::iItem, public r2::SingleTon<Assertion>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class DebugBreak : public r2cm::iItem, public r2::SingleTon<DebugBreak>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class MyAssertion : public r2cm::iItem, public r2::SingleTon<MyAssertion>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class SimpleLog : public r2cm::iItem, public r2::SingleTon<SimpleLog>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}