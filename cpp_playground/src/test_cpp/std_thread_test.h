#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace std_thread_test
{
	class Basic : public r2cm::iItem, public r2::SingleTon<Basic>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class Declaration : public r2cm::iItem, public r2::SingleTon<Declaration>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class CopyAssaignment : public r2cm::iItem, public r2::SingleTon<CopyAssaignment>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class WaitProcess_SleepFor : public r2cm::iItem, public r2::SingleTon<WaitProcess_SleepFor>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class WaitProcess_Yield : public r2cm::iItem, public r2::SingleTon<WaitProcess_Yield>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}