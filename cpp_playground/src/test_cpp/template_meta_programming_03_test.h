#pragma once

#include "base/r2cm_iItem.h"
#include "r2/r2_Singleton.h"

namespace template_meta_programming_test
{
	class MultiTypePackage : public r2cm::iItem, public r2::SingleTon<MultiTypePackage>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}