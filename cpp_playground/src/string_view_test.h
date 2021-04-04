#pragma once

#include "r2_iNode.h"

namespace stringview_test
{
	class Basic : public r2::iNode<Basic>
	{
	public:
		static const char* GetTitle() { return "StringView : Basic"; }
		static void Do();
	};
}