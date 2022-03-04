#pragma once

#include "base/r2cm_iItem.h"
#include "r2/r2_Singleton.h"

namespace console_buffer_test
{
	class FillBuffer : public r2cm::iItem, public r2::SingleTon<FillBuffer>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class Write2Buffer_WriteConsole : public r2cm::iItem, public r2::SingleTon<Write2Buffer_WriteConsole>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class Write2Buffer_WriteConsoleOutput : public r2cm::iItem, public r2::SingleTon<Write2Buffer_WriteConsoleOutput>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class DoubleBuffering : public r2cm::iItem, public r2::SingleTon<DoubleBuffering>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}