#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace c_file_test
{
	class OpenAndClose : public r2cm::iItem, public r2cm::SingleTon<OpenAndClose>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class GetCharacter : public r2cm::iItem, public r2cm::SingleTon<GetCharacter>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class GetLine : public r2cm::iItem, public r2cm::SingleTon<GetLine>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}