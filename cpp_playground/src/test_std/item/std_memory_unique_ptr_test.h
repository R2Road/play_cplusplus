#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace std_memory_unique_ptr_test
{
	class Basic : public r2cm::iItem, public r2cm::SingleTon<Basic>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Deleter : public r2cm::iItem, public r2cm::SingleTon<Deleter>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class TemplateDeleter : public r2cm::iItem, public r2cm::SingleTon<TemplateDeleter>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class FowardDeclaration : public r2cm::iItem, public r2cm::SingleTon<FowardDeclaration>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}