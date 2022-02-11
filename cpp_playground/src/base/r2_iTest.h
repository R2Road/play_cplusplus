#pragma once

#include <functional>

namespace r2
{
	enum class eTestEndAction;

	class iTest
	{
	public:
		using TitleFunc = std::function<const char*()>;
		using DoFunc = std::function<eTestEndAction()>;

		virtual ~iTest() {}

		virtual TitleFunc GetTitleFunction() const = 0;
		virtual DoFunc GetDoFunction() = 0;
	};
}