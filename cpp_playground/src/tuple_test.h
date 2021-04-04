#pragma once

#include "r2_iNode.h"

namespace tuple_test
{
	class Basic : public r2::iNode<Basic>
	{
	private:
		Basic() = delete;

	public:
		static const char* GetTitle() { return "Tuple : Basic"; }
		static void Do();
	};
}