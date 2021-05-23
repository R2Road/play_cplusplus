#pragma once

#include "r2_iTest.h"
#include "r2_Singleton.h"

namespace time_test
{
	class Chrono : public r2::iTest, public r2::SingleTon<Chrono>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}