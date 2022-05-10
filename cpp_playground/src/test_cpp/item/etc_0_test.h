#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace etc_test
{
	class InitArray : public r2cm::iItem, public r2cm::SingleTon<InitArray>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class Macro2String : public r2cm::iItem, public r2cm::SingleTon<Macro2String>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}