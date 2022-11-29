namespace cpp_class_test_helper_private_inheritance_ienum
{
	class iEnum
	{
	protected:
		enum eEnum
		{
			a, b, c
		};
	};

	class T : private iEnum
	{
	public:
		int Do() { return eEnum::c; }
	};
}