#include <stdio.h>

namespace cpp_class_private_inheritance_test_helper
{
	class iPrivate
	{
	private:
		virtual void DoProcess() = 0;
	};

	class iPublic
	{
	public:
		virtual void Do() = 0;
	};

	class T : private iPrivate, public iPublic
	{
	public:
		void DoProcess() override
		{
			puts( "Call" );
		}

	public:
		void Do() override
		{
			DoProcess();
		}
	};
}