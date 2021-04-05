#pragma once

#include "r2_iNode.h"
#include "r2_Singleton.h"

namespace random_test
{
	class Basic : public r2::iNode, public r2::SingleTon<Basic>
	{
	public:
		const char* GetTitle() const override { return "Random : Basic"; }
		r2::eTestResult Do() override;
	};



	class StatusSaveAndLoad : public r2::iNode, public r2::SingleTon<StatusSaveAndLoad>
	{
	public:
		const char* GetTitle() const override { return "Random : Status Save And Load"; }
		r2::eTestResult Do() override;
	};
}