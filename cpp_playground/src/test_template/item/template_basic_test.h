#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace template_basic_test
{
	class MemberVariable : public r2cm::iItem, public r2cm::SingleTon<MemberVariable>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Function : public r2cm::iItem, public r2cm::SingleTon<Function>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}