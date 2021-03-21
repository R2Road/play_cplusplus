#pragma once

namespace variant_test
{
	class  Basic
	{
	private:
		Basic() = delete;

	public:
		static const char* GetTitle() { return "Variant : Basic"; }
		static void Do();
	};
}