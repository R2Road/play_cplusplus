namespace c_union_test_helper_unnamedunion_with_vector3_2
{
	struct TestStruct
	{
		TestStruct() :
			r()
			, x( r[0] )
			, y( r[1] )
			, z( r[2] )
		{}

		float r[3];
		float& x;
		float& y;
		float& z;
	};
}