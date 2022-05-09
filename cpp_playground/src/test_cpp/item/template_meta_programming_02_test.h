#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace template_meta_programming_test
{
	class Character2String : public r2cm::iItem, public r2cm::SingleTon<Character2String>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};


	class Integer2String : public r2cm::iItem, public r2cm::SingleTon<Integer2String>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};


	class CalculatePlaceValue : public r2cm::iItem, public r2cm::SingleTon<CalculatePlaceValue>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};


	class Integer2String_II : public r2cm::iItem, public r2cm::SingleTon<Integer2String_II>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}