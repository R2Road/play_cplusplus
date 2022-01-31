#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace console_window_input_test
{
	class EnableWindowInput : public r2::iTest, public r2::SingleTon<EnableWindowInput>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}