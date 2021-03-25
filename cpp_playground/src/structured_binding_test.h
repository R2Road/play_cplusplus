#pragma once

namespace structured_binding_test
{
	class  Basic
	{
	private:
		Basic() = delete;

	public:
		static const char* GetTitle() { return "Structured Binding : Basic"; }
		static void Do();
	};
}