namespace cpp_class_private_inheritance_test_helper_pure_virtual_interface
{
	// private ����̾ �ڽ� class ���� ���� ���� �� �ִ�.

	class iPureVirtualPrivate
	{
	private:
		virtual void DoProcess() = 0;
	};

	class PVP_Private : private iPureVirtualPrivate
	{
	public:
		void DoProcess() override {}
	};

	class PVP_Protected : protected iPureVirtualPrivate
	{
	public:
		void DoProcess() override {}
	};

	class PVP_Public : public iPureVirtualPrivate
	{
	public:
		void DoProcess() override {}
	};
}