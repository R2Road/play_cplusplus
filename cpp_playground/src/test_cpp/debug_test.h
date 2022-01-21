#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace debug_test
{
	class Basic : public r2::iTest, public r2::SingleTon<Basic>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class DebugBreak : public r2::iTest, public r2::SingleTon<DebugBreak>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}