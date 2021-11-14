#include "pch.h"
#include "vector3_test.h"

#include "base/r2_eTestResult.h"

namespace r2
{
	struct Vector3
	{
		float x = 0.f;
		float y = 0.f;
		float z = 0.f;
	};

	Vector3 operator+( const Vector3& v1, const Vector3& v2 )
	{
		return Vector3{ v1.x + v2.x, v1.y + v2.y, v1.z + v2.z };
	}
	void operator+=( Vector3& v1, const Vector3& v2 )
	{
		v1.x += v2.x;
		v1.y += v2.y;
		v1.z += v2.z;
	}

	Vector3 operator-( const Vector3& v1, const Vector3& v2 )
	{
		return Vector3{ v1.x - v2.x, v1.y - v2.y, v1.z - v2.z };
	}
	void operator-=( Vector3& v1, const Vector3& v2 )
	{
		v1.x -= v2.x;
		v1.y -= v2.y;
		v1.z -= v2.z;
	}

	Vector3 operator*( const Vector3& v1, const float scalar )
	{
		return Vector3{ v1.x * scalar, v1.y * scalar, v1.z * scalar };
	}
	void operator*=( Vector3& v1, const float scalar )
	{
		v1.x *= scalar;
		v1.y *= scalar;
		v1.z *= scalar;
	}
}

namespace vector3_test
{
	r2::iTest::TitleFunc OperatorPlus::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector3 : Operator+";
		};
	}
	r2::iTest::DoFunc OperatorPlus::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()()  << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				const r2::Vector3 v1{ 1.f, 1.1f, 2.2f };
				const r2::Vector3 v2{ 2.1f, 0.f, 2.f };

				const auto v3 = v1 + v2;

				std::cout << r2::tab << "+ Variable" << r2::linefeed2;
				std::cout << r2::tab2 << "r2::Vector3 v1{ 1.f, 1.1f, 2.2f };" << r2::linefeed;
				std::cout << r2::tab2 << "r2::Vector3 v2{ 2.1f, 0.f, 2.f };" << r2::linefeed;


				std::cout << r2::linefeed;


				std::cout << r2::tab << "+ Operation" << r2::linefeed2;
				std::cout << r2::tab2 << "const auto v3 = v1 + v2;" << r2::linefeed;


				std::cout << r2::linefeed;


				std::cout << r2::tab << "+ Result" << r2::linefeed2;
				std::cout << r2::tab2 << "v3.x : " << v3.x << r2::linefeed;
				std::cout << r2::tab2 << "v3.y : " << v3.y << r2::linefeed;
				std::cout << r2::tab2 << "v3.z : " << v3.z << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}

	r2::iTest::TitleFunc OperatorPlusEqual::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector3 : Operator+=";
		};
	}
	r2::iTest::DoFunc OperatorPlusEqual::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				r2::Vector3 v1{ 3.f, .2f, 1.2f };
				const r2::Vector3 v2{ 1.4f, 1.3f, 1.5f };

				v1 += v2;

				std::cout << r2::tab << "+ Variable" << r2::linefeed2;
				std::cout << r2::tab2 << "r2::Vector3 v1{ 3.f, .2f, 1.2f };" << r2::linefeed;
				std::cout << r2::tab2 << "r2::Vector3 v2{ 1.4f, 1.3f, 1.5f };" << r2::linefeed;


				std::cout << r2::linefeed;


				std::cout << r2::tab << "+ Operation" << r2::linefeed2;
				std::cout << r2::tab2 << "v1 += v2;" << r2::linefeed;


				std::cout << r2::linefeed;


				std::cout << r2::tab << "+ Result" << r2::linefeed2;
				std::cout << r2::tab2 << "v1.x : " << v1.x << r2::linefeed;
				std::cout << r2::tab2 << "v1.y : " << v1.y << r2::linefeed;
				std::cout << r2::tab2 << "v1.z : " << v1.z << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc OperatorMinus::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector3 : Operator-";
		};
	}
	r2::iTest::DoFunc OperatorMinus::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				const r2::Vector3 v1{ 1.f, 1.1f, 2.2f };
				const r2::Vector3 v2{ 2.1f, 0.f, 2.f };

				const auto v3 = v1 - v2;

				std::cout << r2::tab << "+ Variable" << r2::linefeed2;
				std::cout << r2::tab2 << "r2::Vector3 v1{ 1.f, 1.1f, 2.2f };" << r2::linefeed;
				std::cout << r2::tab2 << "r2::Vector3 v2{ 2.1f, 0.f, 2.f };" << r2::linefeed;


				std::cout << r2::linefeed;


				std::cout << r2::tab << "+ Operation" << r2::linefeed2;
				std::cout << r2::tab2 << "const auto v3 = v1 - v2;" << r2::linefeed;


				std::cout << r2::linefeed;


				std::cout << r2::tab << "+ Result" << r2::linefeed2;
				std::cout << r2::tab2 << "v3.x : " << v3.x << r2::linefeed;
				std::cout << r2::tab2 << "v3.y : " << v3.y << r2::linefeed;
				std::cout << r2::tab2 << "v3.z : " << v3.z << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}

	r2::iTest::TitleFunc OperatorMinusEqual::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector3 : Operator-=";
		};
	}
	r2::iTest::DoFunc OperatorMinusEqual::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				r2::Vector3 v1{ 3.f, .2f, 1.2f };
				const r2::Vector3 v2{ 1.4f, 1.3f, 1.5f };

				v1 -= v2;

				std::cout << r2::tab << "+ Variable" << r2::linefeed2;
				std::cout << r2::tab2 << "r2::Vector3 v1{ 3.f, .2f, 1.2f };" << r2::linefeed;
				std::cout << r2::tab2 << "r2::Vector3 v2{ 1.4f, 1.3f, 1.5f };" << r2::linefeed;


				std::cout << r2::linefeed;


				std::cout << r2::tab << "+ Operation" << r2::linefeed2;
				std::cout << r2::tab2 << "v1 -= v2;" << r2::linefeed;


				std::cout << r2::linefeed;


				std::cout << r2::tab << "+ Result" << r2::linefeed2;
				std::cout << r2::tab2 << "v1.x : " << v1.x << r2::linefeed;
				std::cout << r2::tab2 << "v1.y : " << v1.y << r2::linefeed;
				std::cout << r2::tab2 << "v1.z : " << v1.z << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc OperatorMultiply_With_Scalar::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector3 : Operator* Scalar";
		};
	}
	r2::iTest::DoFunc OperatorMultiply_With_Scalar::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				const r2::Vector3 v1{ 1.f, 1.1f, 2.2f };
				const float scalar = 3.f;

				const auto v3 = v1 * scalar;

				std::cout << r2::tab << "+ Variable" << r2::linefeed2;
				std::cout << r2::tab2 << "r2::Vector3 v1{ 1.f, 1.1f, 2.2f };" << r2::linefeed;
				std::cout << r2::tab2 << "float scalar = 3.f;" << r2::linefeed;


				std::cout << r2::linefeed;


				std::cout << r2::tab << "+ Operation" << r2::linefeed2;
				std::cout << r2::tab2 << "const auto v3 = v1 * scalar;" << r2::linefeed;


				std::cout << r2::linefeed;


				std::cout << r2::tab << "+ Result" << r2::linefeed2;
				std::cout << r2::tab2 << "v3.x : " << v3.x << r2::linefeed;
				std::cout << r2::tab2 << "v3.y : " << v3.y << r2::linefeed;
				std::cout << r2::tab2 << "v3.z : " << v3.z << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}

	r2::iTest::TitleFunc OperatorMultiplyEqual_With_Scalar::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector3 : Operator*= Scalar";
		};
	}
	r2::iTest::DoFunc OperatorMultiplyEqual_With_Scalar::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				r2::Vector3 v1{ 1.f, 1.1f, 2.2f };
				const float scalar = 3.f;

				v1 *= scalar;

				std::cout << r2::tab << "+ Variable" << r2::linefeed2;
				std::cout << r2::tab2 << "r2::Vector3 v1{ 1.f, 1.1f, 2.2f };" << r2::linefeed;
				std::cout << r2::tab2 << "float scalar = 3.f;" << r2::linefeed;


				std::cout << r2::linefeed;


				std::cout << r2::tab << "+ Operation" << r2::linefeed2;
				std::cout << r2::tab2 << "v1 *= scalar;" << r2::linefeed;


				std::cout << r2::linefeed;


				std::cout << r2::tab << "+ Result" << r2::linefeed2;
				std::cout << r2::tab2 << "v1.x : " << v1.x << r2::linefeed;
				std::cout << r2::tab2 << "v1.y : " << v1.y << r2::linefeed;
				std::cout << r2::tab2 << "v1.z : " << v1.z << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}