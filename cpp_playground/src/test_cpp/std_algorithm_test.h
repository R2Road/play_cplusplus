#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace std_algorithm_test
{
	class Shuffle : public r2::iItem, public r2::SingleTon<Shuffle>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}