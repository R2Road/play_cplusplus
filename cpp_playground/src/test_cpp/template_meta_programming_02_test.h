#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace template_meta_programming_test
{
	class Character2String : public r2::iTest, public r2::SingleTon<Character2String>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};


	class Integer2String : public r2::iTest, public r2::SingleTon<Integer2String>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};


	class CalculatePlaceValue : public r2::iTest, public r2::SingleTon<CalculatePlaceValue>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};


	class Integer2String_II : public r2::iTest, public r2::SingleTon<Integer2String_II>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}