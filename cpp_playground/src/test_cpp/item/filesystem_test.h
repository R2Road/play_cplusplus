#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2/r2_Singleton.h"

namespace filesystem_test
{
	class DirectoryPath : public r2cm::iItem, public r2::SingleTon<DirectoryPath>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};



	class DirectoryIterator : public r2cm::iItem, public r2::SingleTon<DirectoryIterator>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};



	class RecursiveDirectoryIterator : public r2cm::iItem, public r2::SingleTon<RecursiveDirectoryIterator>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};



	class PathOperation_1 : public r2cm::iItem, public r2::SingleTon<PathOperation_1>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
	class PathOperation_2 : public r2cm::iItem, public r2::SingleTon<PathOperation_2>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}