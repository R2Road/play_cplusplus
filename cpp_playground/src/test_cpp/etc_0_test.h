#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace etc_test
{
	class XOR_Swap : public r2::iTest, public r2::SingleTon<XOR_Swap>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class InitArray : public r2::iTest, public r2::SingleTon<InitArray>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class Macro2String : public r2::iTest, public r2::SingleTon<Macro2String>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
	class MacroShowCodeInfo : public r2::iTest, public r2::SingleTon<MacroShowCodeInfo>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class Pointer2Index : public r2::iTest, public r2::SingleTon<Pointer2Index>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}