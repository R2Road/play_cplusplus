#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace console_buffer_test
{
	class FillBuffer : public r2::iItem, public r2::SingleTon<FillBuffer>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class Write2Buffer_WriteConsole : public r2::iItem, public r2::SingleTon<Write2Buffer_WriteConsole>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class Write2Buffer_WriteConsoleOutput : public r2::iItem, public r2::SingleTon<Write2Buffer_WriteConsoleOutput>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class DoubleBuffering : public r2::iItem, public r2::SingleTon<DoubleBuffering>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}