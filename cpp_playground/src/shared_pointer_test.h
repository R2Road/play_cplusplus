#pragma once

#include "r2_iTest.h"
#include "r2_Singleton.h"

namespace shared_pointer_test
{
	class SharedPtr : public r2::iTest, public r2::SingleTon<SharedPtr>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() const override;
	};
}