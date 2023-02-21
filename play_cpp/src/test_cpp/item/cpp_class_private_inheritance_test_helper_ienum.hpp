namespace cpp_class_private_inheritance_test_helper_ienum
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