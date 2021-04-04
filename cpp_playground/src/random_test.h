#pragma once

#include "r2_iNode.h"

namespace random_test
{
	class Basic : public r2::iNode<Basic>
	{
	public:
		static const char* GetTitle() { return "Random : Basic"; }
		static void Do();
	};



	class StatusSaveAndLoad : public r2::iNode<StatusSaveAndLoad>
	{
	public:
		static const char* GetTitle() { return "Random : Status Save And Load"; }
		static void Do();
	};
}