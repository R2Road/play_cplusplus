#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace std_function_test
{
	class Equality : public r2::iTest, public r2::SingleTon<Equality>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}