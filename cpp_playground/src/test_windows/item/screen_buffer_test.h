#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace screen_buffer_test
{
	class FillBuffer : public r2cm::iItem, public r2cm::SingleTon<FillBuffer>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class Write2Buffer_WriteConsole : public r2cm::iItem, public r2cm::SingleTon<Write2Buffer_WriteConsole>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class Write2Buffer_WriteConsoleOutput : public r2cm::iItem, public r2cm::SingleTon<Write2Buffer_WriteConsoleOutput>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class ReadConsoleOutputTest : public r2cm::iItem, public r2cm::SingleTon<ReadConsoleOutputTest>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class ETCTest : public r2cm::iItem, public r2cm::SingleTon<ETCTest>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class DoubleBuffering : public r2cm::iItem, public r2cm::SingleTon<DoubleBuffering>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}