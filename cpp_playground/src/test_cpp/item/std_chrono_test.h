#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2/r2_Singleton.h"

namespace std_chrono_test
{
	class Epoch : public r2cm::iItem, public r2::SingleTon<Epoch>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class Chrono : public r2cm::iItem, public r2::SingleTon<Chrono>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}