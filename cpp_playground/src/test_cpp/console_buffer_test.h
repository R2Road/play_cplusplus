#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace console_buffer_test
{
	class BufferInfo : public r2::iTest, public r2::SingleTon<BufferInfo>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class DoubleBuffering : public r2::iTest, public r2::SingleTon<DoubleBuffering>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}