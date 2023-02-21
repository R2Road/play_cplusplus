namespace cpp_class_private_inheritance_test_helper_demo1
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

//
// iPublic �� ���ƴٴѴٴ� �����̶�� private ��ӹ��� ��Ҹ� ���� ���� ��� ���°� �ƴұ�?
// �׷��ٰ� ����� �ʿ�� ������.
//

	class T : private iPrivate, public iPublic
	{
	public:
		void DoProcess() override {}

	public:
		void Do() override
		{
			DoProcess();
		}
	};
}