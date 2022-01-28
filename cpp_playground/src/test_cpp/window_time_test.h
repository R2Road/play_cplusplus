#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace window_time_test
{
	class WindowTime : public r2::iTest, public r2::SingleTon<WindowTime>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}