#pragma once

#include "r2_iTest.h"
#include "r2_Singleton.h"

namespace etc_test
{
	class XOR_Swap : public r2::iTest, public r2::SingleTon<XOR_Swap>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}