namespace cpp_class_test_helper_nvi
{
	// private �Ӽ��� virtual �Լ��� �ڽ� class ���� ������ �����ϴ�.

	class D1
	{
	public:
		virtual ~D1() = default;

		int Do()
		{
			return Process();
		}

	private:
		virtual int Process()
		{
			return 1;
		}
	};

	class D2 : public D1
	{
	private:
		int Process() override
		{
			return 2;
		}
	};
}