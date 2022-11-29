namespace cpp_class_test_helper_nvi
{
	// private 속성의 virtual 함수는 자식 class 에서 재정의 가능하다.

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