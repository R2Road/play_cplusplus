#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace c_file_test
{
	class OpenAndClose : public r2cm::iItem, public r2cm::SingleTon<OpenAndClose>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class GetCharacter : public r2cm::iItem, public r2cm::SingleTon<GetCharacter>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}