#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace c_system_test
{
	class Pause : public r2cm::iItem, public r2cm::SingleTon<Pause>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}