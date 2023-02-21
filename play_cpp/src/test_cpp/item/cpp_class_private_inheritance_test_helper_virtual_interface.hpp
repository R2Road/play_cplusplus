namespace cpp_class_private_inheritance_test_helper_virtual_interface
{
	// private ����̾ �ڽ� class ���� ���� ���� �� �ִ�.

	class iVirtualPrivate
	{
	private:
		virtual void DoProcess() {};
	};

	class VP_Private : private iVirtualPrivate
	{
	public:
		void DoProcess() override {}
	};

	class VP_Protected : protected iVirtualPrivate
	{
	public:
		void DoProcess() override {}
	};

	class VP_Public : public iVirtualPrivate
	{
	public:
		void DoProcess() override {}
	};
}