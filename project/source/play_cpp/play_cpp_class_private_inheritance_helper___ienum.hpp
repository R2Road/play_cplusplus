namespace play_cpp_class_private_inheritance_helper___ienum
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