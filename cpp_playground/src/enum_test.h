#pragma once

#include "r2_iTest.h"
#include "r2_Singleton.h"

namespace enum_test
{
	class Basic : public r2::iTest, public r2::SingleTon<Basic>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() const override;
	};

	class Convert : public r2::iTest, public r2::SingleTon<Convert>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() const override;
	};
}