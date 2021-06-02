#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace align_test
{
	class AlignAs : public r2::iTest, public r2::SingleTon<AlignAs>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}