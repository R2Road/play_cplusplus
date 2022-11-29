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
// iPublic 이 돌아다닌다는 조건이라면 private 상속받은 요소를 열건 말건 상관 없는게 아닐까?
// 그렇다고 열어둘 필요는 없지만.
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