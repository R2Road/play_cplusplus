#pragma once

#include "r2_iNode.h"

namespace const_pointer_test
{
	class Basic : public r2::iNode<Basic>
	{
	public:
		static const char* GetTitle() { return "Const Pointer : Basic"; }
		static void Do();
	};
}