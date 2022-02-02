#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace console_window_input_test
{
	class WindowInput_ReadConsoleInput : public r2::iTest, public r2::SingleTon<WindowInput_ReadConsoleInput>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class WindowInput_GetKeyState : public r2::iTest, public r2::SingleTon<WindowInput_GetKeyState>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class WindowInput_GetKeyboardState : public r2::iTest, public r2::SingleTon<WindowInput_GetKeyboardState>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class WindowInput_GetAsyncKeyStates : public r2::iTest, public r2::SingleTon<WindowInput_GetAsyncKeyStates>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}