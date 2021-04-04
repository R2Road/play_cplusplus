#pragma once

#include "r2_iNode.h"

namespace optional_test
{
	class Basic : public r2::iNode<Basic>
	{
	public:
		static const char* GetTitle() { return "Optional : Basic"; }
		static void Do();
	};
}