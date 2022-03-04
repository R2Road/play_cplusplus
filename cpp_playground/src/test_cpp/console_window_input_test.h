#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace console_window_input_test
{
	class WindowInput_ReadConsoleInput : public r2::iItem, public r2::SingleTon<WindowInput_ReadConsoleInput>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class WindowInput_GetKeyState : public r2::iItem, public r2::SingleTon<WindowInput_GetKeyState>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class WindowInput_GetKeyboardState : public r2::iItem, public r2::SingleTon<WindowInput_GetKeyboardState>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class WindowInput_GetAsyncKeyStates : public r2::iItem, public r2::SingleTon<WindowInput_GetAsyncKeyStates>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}