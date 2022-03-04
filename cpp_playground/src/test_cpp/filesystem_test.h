#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace filesystem_test
{
	class DirectoryPath : public r2::iTest, public r2::SingleTon<DirectoryPath>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};



	class DirectoryIterator : public r2::iTest, public r2::SingleTon<DirectoryIterator>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};



	class RecursiveDirectoryIterator : public r2::iTest, public r2::SingleTon<RecursiveDirectoryIterator>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};



	class PathOperation_1 : public r2::iTest, public r2::SingleTon<PathOperation_1>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
	class PathOperation_2 : public r2::iTest, public r2::SingleTon<PathOperation_2>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}