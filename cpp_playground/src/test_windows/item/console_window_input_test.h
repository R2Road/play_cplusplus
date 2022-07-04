#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace console_window_input_test
{
	class WindowInput_ReadConsoleInput : public r2cm::iItem, public r2cm::SingleTon<WindowInput_ReadConsoleInput>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class WindowInput_GetKeyState : public r2cm::iItem, public r2cm::SingleTon<WindowInput_GetKeyState>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class WindowInput_GetKeyboardState : public r2cm::iItem, public r2cm::SingleTon<WindowInput_GetKeyboardState>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class WindowInput_GetAsyncKeyStates : public r2cm::iItem, public r2cm::SingleTon<WindowInput_GetAsyncKeyStates>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}