#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace std_chrono_test
{
	class Epoch : public r2::iItem, public r2::SingleTon<Epoch>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class Chrono : public r2::iItem, public r2::SingleTon<Chrono>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}