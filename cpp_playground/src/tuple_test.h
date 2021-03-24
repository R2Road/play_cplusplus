#pragma once

namespace tuple_test
{
	class  Basic
	{
	private:
		Basic() = delete;

	public:
		static const char* GetTitle() { return "Tuple : Basic"; }
		static void Do();
	};
}