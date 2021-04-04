#pragma once

#include "r2_iNode.h"

namespace filesystem_test
{
	class CurrentDirectory : public r2::iNode<CurrentDirectory>
	{
	public:
		static const char* GetTitle() { return "File System : Current Directory"; }
		static void Do();
	};
}