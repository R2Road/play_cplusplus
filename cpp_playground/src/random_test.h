#pragma once

#include "r2_iNode.h"

namespace random_test
{
	class Basic : public r2::iNode<Basic>
	{
	public:
		const char* GetTitle() const override { return "Random : Basic"; }
		void Do() override;
	};



	class StatusSaveAndLoad : public r2::iNode<StatusSaveAndLoad>
	{
	public:
		const char* GetTitle() const override { return "Random : Status Save And Load"; }
		void Do() override;
	};
}