#pragma once

#include <functional>

namespace r2
{
	enum class eTestEndAction;

	class iItem
	{
	public:
		using TitleFuncT = std::function<const char*()>;
		using DoFunc = std::function<eTestEndAction()>;

		virtual ~iItem() {}

		virtual TitleFuncT GetTitleFunction() const = 0;
		virtual DoFunc GetDoFunction() = 0;
	};
}