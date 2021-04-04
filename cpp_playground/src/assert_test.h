#pragma once

#include "r2_iNode.h"

namespace assert_test
{
	class Basic : public r2::iNode<Basic>
	{
	public:
		static const char* GetTitle() { return "Assert : Basic"; }
		static void Do();
	};
}