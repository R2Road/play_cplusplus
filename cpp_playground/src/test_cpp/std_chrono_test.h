#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace std_chrono_test
{
	class Chrono : public r2::iTest, public r2::SingleTon<Chrono>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}