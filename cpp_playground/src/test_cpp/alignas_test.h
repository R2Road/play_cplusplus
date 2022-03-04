#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace align_test
{
	class AlignAs : public r2::iItem, public r2::SingleTon<AlignAs>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}