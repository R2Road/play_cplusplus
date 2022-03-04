#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace std_list_test
{
	class Splice : public r2::iTest, public r2::SingleTon<Splice>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class OthersIterator : public r2::iTest, public r2::SingleTon<OthersIterator>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class EndIterator : public r2::iTest, public r2::SingleTon<EndIterator>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}