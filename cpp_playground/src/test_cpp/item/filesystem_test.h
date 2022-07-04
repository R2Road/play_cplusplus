#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace filesystem_test
{
	class DirectoryPath : public r2cm::iItem, public r2cm::SingleTon<DirectoryPath>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};



	class DirectoryIterator : public r2cm::iItem, public r2cm::SingleTon<DirectoryIterator>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};



	class RecursiveDirectoryIterator : public r2cm::iItem, public r2cm::SingleTon<RecursiveDirectoryIterator>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};



	class PathOperation_1 : public r2cm::iItem, public r2cm::SingleTon<PathOperation_1>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
	class PathOperation_2 : public r2cm::iItem, public r2cm::SingleTon<PathOperation_2>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}