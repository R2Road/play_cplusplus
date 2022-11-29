namespace cpp_class_private_inheritance_test_helper_pure_virtual_interface
{
	// private pure virtual method 는...
	// 어떻게 상속하건 public 공개가 된다. 왜?

	class iPureVirtualPrivate
	{
	private:
		virtual void DoProcess() = 0;
	};

	class T_Private : private iPureVirtualPrivate
	{
	public:
		void DoProcess() override {}
	};

	class T_Protected : protected iPureVirtualPrivate
	{
	public:
		void DoProcess() override {}
	};

	class T_Public : public iPureVirtualPrivate
	{
	public:
		void DoProcess() override {}
	};
}