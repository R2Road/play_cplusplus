#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2/r2_Singleton.h"

namespace std_list_test
{
	class Splice : public r2cm::iItem, public r2::SingleTon<Splice>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class OthersIterator : public r2cm::iItem, public r2::SingleTon<OthersIterator>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class EndIterator : public r2cm::iItem, public r2::SingleTon<EndIterator>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}