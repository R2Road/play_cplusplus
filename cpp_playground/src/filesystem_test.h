#pragma once

#include "r2_iNode.h"

namespace filesystem_test
{
	class CurrentDirectory : public r2::iNode<CurrentDirectory>
	{
	public:
		const char* GetTitle() const override { return "File System : Current Directory"; }
		void Do() override;
	};
}