#pragma warning( push )
#pragma warning( disable : 4201 )

namespace c_union_test_helper_unnamedunion_with_vector3
{
	struct Vector3
	{
		union
		{
			float r[3];

			struct
			{
				float x;
				float y;
				float z;
			};
		};
	};
}

#pragma warning( pop )