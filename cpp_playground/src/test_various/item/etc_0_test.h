#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace etc_test
{
	class Macro2String : public r2cm::iItem, public r2cm::SingleTon<Macro2String>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class ShowBinary : public r2cm::iItem, public r2cm::SingleTon<ShowBinary>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}