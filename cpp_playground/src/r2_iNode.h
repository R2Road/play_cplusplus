#pragma once

namespace r2
{
	class iNode
	{
	public:
		virtual ~iNode() {}

		virtual const char* GetTitle() const = 0;
		virtual void Do() = 0;
	};
}