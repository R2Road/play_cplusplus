#pragma once

#include "r2_iTest.h"
#include "r2_Singleton.h"

namespace filesystem_test
{
	class DirectoryPath : public r2::iTest, public r2::SingleTon<DirectoryPath>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};

	class CurrentDirectory : public r2::iTest, public r2::SingleTon<CurrentDirectory>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};
}