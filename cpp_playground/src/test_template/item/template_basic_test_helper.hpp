namespace template_basic_test
{
	template<typename T>
	struct MemberVariableTest_01
	{
		T t;
	};

	template<typename T1, typename T2>
	struct MemberVariableTest_02
	{
		T1 t1;
		T2 t2;
	};
}