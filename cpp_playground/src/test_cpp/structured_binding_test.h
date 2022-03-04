#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace structured_binding_test
{
	class Basic : public r2cm::iItem, public r2::SingleTon<Basic>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}