#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace std_function_2_test
{
	class Equality_STDBind_1 : public r2cm::iItem, public r2cm::SingleTon<Equality_STDBind_1>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}