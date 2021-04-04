#pragma once

namespace r2
{
	template<typename T>
	class iNode
	{
	public:
		using ChildT = T;

		virtual ~iNode() {}

		virtual const char* GetTitle() const = 0;
		virtual void Do() = 0;

		static ChildT& GetInstance()
		{
			static ChildT instance;
			return instance;
		}
	};
}