#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace screen_buffer_test
{
	class FillBuffer : public r2cm::iItem, public r2cm::SingleTon<FillBuffer>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Write2Buffer_WriteConsole : public r2cm::iItem, public r2cm::SingleTon<Write2Buffer_WriteConsole>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Write2Buffer_WriteConsoleOutput : public r2cm::iItem, public r2cm::SingleTon<Write2Buffer_WriteConsoleOutput>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class ReadConsoleOutputTest : public r2cm::iItem, public r2cm::SingleTon<ReadConsoleOutputTest>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class ETCTest : public r2cm::iItem, public r2cm::SingleTon<ETCTest>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class DoubleBuffering : public r2cm::iItem, public r2cm::SingleTon<DoubleBuffering>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}