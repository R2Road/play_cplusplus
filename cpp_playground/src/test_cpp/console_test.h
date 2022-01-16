#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace console_test
{
	class Pixel : public r2::iTest, public r2::SingleTon<Pixel>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}