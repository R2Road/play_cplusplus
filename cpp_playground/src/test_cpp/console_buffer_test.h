#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace console_buffer_test
{
	class FillBuffer : public r2::iTest, public r2::SingleTon<FillBuffer>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class Write2Buffer : public r2::iTest, public r2::SingleTon<Write2Buffer>
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