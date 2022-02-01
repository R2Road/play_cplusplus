#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace std_algorithm_test
{
	class Shuffle : public r2::iTest, public r2::SingleTon<Shuffle>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}