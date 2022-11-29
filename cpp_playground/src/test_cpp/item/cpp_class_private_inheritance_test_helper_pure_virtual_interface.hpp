namespace cpp_class_private_inheritance_test_helper_pure_virtual_interface
{
	// private pure virtual method ��...
	// ��� ����ϰ� public ������ �ȴ�. ��?

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