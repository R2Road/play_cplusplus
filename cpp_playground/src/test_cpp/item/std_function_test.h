#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace std_function_test
{
	class Equality_FunctionPointer_1 : public r2cm::iItem, public r2cm::SingleTon<Equality_FunctionPointer_1>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class Equality_FunctionPointer_2 : public r2cm::iItem, public r2cm::SingleTon<Equality_FunctionPointer_2>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class Equality_FunctionPointer_3 : public r2cm::iItem, public r2cm::SingleTon<Equality_FunctionPointer_3>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class Equality_Lambda_1 : public r2cm::iItem, public r2cm::SingleTon<Equality_Lambda_1>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}