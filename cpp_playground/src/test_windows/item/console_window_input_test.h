#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace console_window_input_test
{
	class WindowInput_ReadConsoleInput : public r2cm::iItem, public r2cm::SingleTon<WindowInput_ReadConsoleInput>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class WindowInput_GetKeyState : public r2cm::iItem, public r2cm::SingleTon<WindowInput_GetKeyState>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class WindowInput_GetKeyboardState : public r2cm::iItem, public r2cm::SingleTon<WindowInput_GetKeyboardState>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class WindowInput_GetAsyncKeyStates : public r2cm::iItem, public r2cm::SingleTon<WindowInput_GetAsyncKeyStates>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}