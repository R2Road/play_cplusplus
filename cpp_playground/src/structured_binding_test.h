#pragma once

#include "r2_iNode.h"

namespace structured_binding_test
{
	class Basic : public r2::iNode<Basic>
	{
	private:
		Basic() = delete;

	public:
		static const char* GetTitle() { return "Structured Binding : Basic"; }
		static void Do();
	};
}