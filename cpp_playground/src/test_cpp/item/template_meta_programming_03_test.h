#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace template_meta_programming_test
{
	class MultiTypePackage : public r2cm::iItem, public r2cm::SingleTon<MultiTypePackage>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}