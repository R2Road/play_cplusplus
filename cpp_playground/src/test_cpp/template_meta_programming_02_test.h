#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace template_meta_programming_test
{
	class Character2String : public r2::iItem, public r2::SingleTon<Character2String>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};


	class Integer2String : public r2::iItem, public r2::SingleTon<Integer2String>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};


	class CalculatePlaceValue : public r2::iItem, public r2::SingleTon<CalculatePlaceValue>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};


	class Integer2String_II : public r2::iItem, public r2::SingleTon<Integer2String_II>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}