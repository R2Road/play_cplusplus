namespace c_union_test_helper_unnamedunion_with_struct
{
	struct TestStruct
	{
		bool b;

		union
		{
			int i;
			long long ll;
		};
	};
}