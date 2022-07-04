#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace std_list_test
{
	class Splice : public r2cm::iItem, public r2cm::SingleTon<Splice>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class OthersIterator : public r2cm::iItem, public r2cm::SingleTon<OthersIterator>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class EndIterator : public r2cm::iItem, public r2cm::SingleTon<EndIterator>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}